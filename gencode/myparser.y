%{
//this code will be added into the header of generated .cpp file
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "mylexer.h"
#include "TreeNode.h"
#include "symbol_table.h"
using namespace std;

extern int nodecount;
unordered_map<int, char*> opmap;
extern int num_lines;
extern char **currtext;//yytext
extern vector<Symbol*> table; //symbol table
TreeNode *root = NULL;

extern TreeNode *newIDNode();
extern TreeNode *newTypeNode(ExpType type);
extern TreeNode *newStaticNode();
extern TreeNode *newCaseNode();
extern TreeNode *newDefaultNode();
extern TreeNode *newConstNode();
extern TreeNode *newVarNode();
extern TreeNode *newStmtNode(StmtKind kind);
extern TreeNode *newOpNode(int op);
extern TreeNode *newFuncCallNode();
extern TreeNode *newForceCastNode();
extern TreeNode *newDeclNode(DeclKind kind);
extern TreeNode *newPointerNode();

extern void ShowNode(TreeNode *p);
extern void Display(TreeNode *p);
extern void Traverse(TreeNode *p);
extern int typeCheck(TreeNode *t);
extern void typeError(TreeNode *t, char *errmsg);


extern string new_label();
extern void stmt_get_label(TreeNode *t);
extern void expr_get_label(TreeNode *t);
extern void get_label();
extern void recursive_get_label(TreeNode *t);
extern void gen_code(ostream &out);
extern void gen_header(ostream &out);
extern void get_temp_var(TreeNode *t);
extern void gen_decl(ostream &out, TreeNode *t);
extern void recursive_gen_code(ostream &out, TreeNode *t);
extern void expr_gen_code(ostream &out, TreeNode *t);
extern void stmt_gen_code(ostream &out, TreeNode *t);

extern Symbol *newEntry(char *id);
extern Symbol *lookup_table(char *id);
extern Symbol *lookup_table(int pos);
extern Symbol *insert_table(char *id);
extern void printSymTable();

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
	virtual void yyerror(const char YYFAR* text);
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif
}

// place any declarations here
%token MAIN CHAR SHORT INT FLOAT DOUBLE LONG UNSIGNED SIGNED STRUCT UNION ENUM VOID IF ELSE SWITCH CASE DEFAULT FOR DO WHILE BREAK
%token CONTINUE GOTO RETURN AUTO REGISTER STATIC CONST SIZEOF TYPEDEF VOLATILE
%token ID NUM CHARCONST STRCONST
%token POINTMEM ARROWMEM PLUSPLUS MINUSMINUS SHIFTLEFT SHIFTRIGHT GREEQU SMAEQU EQUAL NOTEQUAL LOGAND LOGOR PLUSASSIGN MINUSASSIGN
%token MULASSIGN OVERASSIGN MODASSIGN LSHIFTASSIGN RSHIFTASSIGN ANDASSIGN XORASSIGN ORASSIGN NOT NEG STAR OVER MOD PLUS MINUS
%token GREAT SMALL AND OR XOR ASSIGN QUES COLON LBRACE RBRACE LPAREN RPAREN LSQURE RSQURE SEMICOLON COMMA ERROR
%token MUL POINTER GETADDR GETDATA PLUSU MINUSU PLUSPLUSL PLUSPLUSR MINUSMINUSL MINUSMINUSR INPUT OUTPUT EXTERN ENDL

%left COMMA
%right ASSIGN PLUSASSIGN MINUSASSIGN MULASSIGN OVERASSIGN MODASSIGN LSHIFTASSIGN RSHIFTASSIGN ANDASSIGN XORASSIGN ORASSIGN
%left LOGOR
%left LOGAND
%left OR
%left XOR
%left AND
%left EQUAL NOTEQUAL
%left SMALL GREAT GREEQU SMAEQU
%left SHIFTLEFT SHIFTRIGHT
%left PLUS MINUS
%left MUL OVER MOD
%right PLUSU MINUSU PLUSPLUSL MINUSMINUSL POINTER GETADDR GETDATA NOT NEG SIZEOF
%left PLUSPLUSR MINUSMINUSR

%nonassoc IFU
%nonassoc ELSE

%start program   //start from here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

program			:	global_decl
					{
						$$ = $1;
						//cout<<"program entry"<<endl;
						root = $$;
					}
				|	global_decl program
					{
						if($1)
						{
							$$ = $1;
							$$->sibling = $2;
						}
						else
						{
							$$ = $2;
						}
						root = $$;
					}
				;

entry			:	type_specifier MAIN LPAREN RPAREN compound_stmt  //eg. int main() {}
					{
						$$ = $5;
					}
				|	MAIN LPAREN RPAREN compound_stmt  //eg. main() {}
					{
						$$ = $4;
					}
				|	type_specifier MAIN LPAREN VOID RPAREN compound_stmt  //eg. int main(void) {}
					{
						$$ = $6;
					}
				|	MAIN LPAREN VOID RPAREN compound_stmt  //eg. main(void) {}
					{
						$$ = $5;
					}
				/*|	type_specifier MAIN LPAREN params RPAREN compound_stmt //eg. int main(int argc, char *argv[]) {}
					{
						$$ = $6;
						//Display($$); //Display the tree from here
					}
				|	MAIN LPAREN params RPAREN compound_stmt  //eg. main(int argc, char *argv[]) {}
					{
						$$ = $5;
						//Display($$); //Display the tree from here
					}*/
				|	/* empty */
					{
						$$ = NULL;
					}
				;

global_decl		:	entry
					{
						$$ = $1;
					}
				|	var_decl_stmt
					{
						$$ = $1;
						TreeNode *temp1 = $1->child[1];
						for(;temp1;temp1=temp1->sibling)
						{
							if(temp1->nodekind == ExpK && temp1->kind.exp == IdK)
							{
								Symbol *sym = lookup_table(temp1->attr.idname);
								sym->islocal = false;
							}
							else
							{
								Symbol *sym = NULL;
								for(int i = 0;i<MAXCHILDREN;i++)
								{
									TreeNode *temp2 = temp1->child[i];
									if(temp2)
									{
										if(temp2->nodekind == ExpK && temp2->kind.exp == IdK)
										{
											sym = lookup_table(temp2->attr.idname);
											sym->islocal = false;
										}
									}
								}
							}
						}
					}
				/*|	func_decl_stmt
					{
						$$ = $1;
					}
				|	func_def
					{
						$$ = $1;
					}*/
				;

/* Variable Declaration */
type_specifier	:	INT
					{
						$$ = $1;
					}
				|	CHAR
					{
						$$ = $1;
					}
				/*|	FLOAT
					{
						$$ = $1;
					}
				|	DOUBLE
					{
						$$ = $1;
					}
				|	SHORT
					{
						$$ = $1;
					}*/
				|	VOID
					{
						$$ = $1;
					}
				/*|	struct_union_spci
					{
						$$ = $1;
					}*/
				;

var_decl		:	type_specifier decl_list
					{
						$$ = newDeclNode(VarK);
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->type = $$->child[0]->type;
						TreeNode *temp1 = $2;
						for(;temp1;temp1=temp1->sibling)
						{
							if(temp1->nodekind == ExpK && temp1->kind.exp == IdK)
							{
								Symbol *sym = lookup_table(temp1->attr.idname);
								sym->base_type = $1->type;
								if(sym->decled)
								{
									sym->redecl = true;
								}
								else
								{
									sym->decled = true;
								}
							}
							else
							{
								Symbol *sym = NULL;
								for(int i = 0;i<MAXCHILDREN;i++)
								{
									TreeNode *temp2 = temp1->child[i];
									if(temp2)
									{
										if(temp2->nodekind == ExpK && temp2->kind.exp == IdK)
										{
											sym = lookup_table(temp2->attr.idname);
											sym->base_type = $1->type;
											if(sym->decled)
											{
												sym->redecl = true;
											}
											else
											{
												sym->decled = true;
											}
										}
										else if(temp2->nodekind == PointK)
										{
											if(sym)
											{
												sym->pointer = temp2->pointer;
											}
										}
									}
								}
							}
						}
					}
				|	STATIC type_specifier decl_list
					{
						$$ = newDeclNode(VarK);
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
						$$->type = $$->child[1]->type;
						TreeNode *temp1 = $3;
						for(;temp1;temp1=temp1->sibling)
						{
							if(temp1->nodekind == ExpK && temp1->kind.exp == IdK)
							{
								Symbol *sym = lookup_table(temp1->attr.idname);
								sym->base_type = $1->type;
								sym->isstatic = true;
								if(sym->decled)
								{
									sym->redecl = true;
								}
								else
								{
									sym->decled = true;
								}
							}
							else
							{
								Symbol *sym = NULL;
								for(int i = 0;i<MAXCHILDREN;i++)
								{
									TreeNode *temp2 = temp1->child[i];
									if(temp2)
									{
										if(temp2->nodekind == ExpK && temp2->kind.exp == IdK)
										{
											sym = lookup_table(temp2->attr.idname);
											sym->base_type = $1->type;
											sym->isstatic = true;
											if(sym->decled)
											{
												sym->redecl = true;
											}
											else
											{
												sym->decled = true;
											}
										}
										else if(temp2->nodekind == PointK)
										{
											if(sym)
											{
												sym->pointer = temp2->pointer;
											}
										}
									}
								}
							}
						}
					}
				;

/*struct_union_spci	:	STRUCT ID
						{
							$$ = newStructUnionNode(StructK);
							$$->child[0] = $2;
						}
					|	UNION ID
						{
							$$ = newStructUnionNode(UnionK);
							$$->child[0] = $2;
						}
					|	STRUCT ID var_block
						{
							$$ = newStructUnionNode(StructK);
							$$->child[0] = $2;
							$$->child[1] = $3;
						}
					|	UNION ID var_block
						{
							$$ = newStructUnionNode(UnionK);
							$$->child[0] = $2;
							$$->child[1] = $3;
						}
					;*/

/*var_block			:	LBRACE var_list RBRACE
						{
							$$ = $2;
						}
					;*/

/*var_list			:	var_decl_stmt
						{
							$$ = $1;
						}
					|	var_decl_stmt var_list
						{
							if($1)
							{
								$$ = $1;
								$$->sibling = $2;
							}
							else
							{
								$$ = $2;
							}
						}
					;*/

decl_list_unit	:	ID
					{
						$$ = $1;
					}
				/*|	pointer ID
					{
						$$ = newVarNode();
						$$->child[0] = $2;
						$$->child[1] = $1;
					}*/
				/*|	ID array
					{
						$$ = newVarNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
					}
				|	pointer ID array
					{
						$$ = newVarNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
					}*/
				/*|	ID ASSIGN decl_init
					{
						$$ = newVarNode();
						$$->child[0] = $1;
						$$->child[1] = $3;
					}*/
				/*|	pointer ID ASSIGN decl_init
					{
						$$ = newVarNode();
						$$->child[0] = $2;
						$$->child[1] = $1;
						$$->child[2] = $4;
					}*/
				/*|	ID array ASSIGN decl_init
					{
						$$ = newVarNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $4;
					}
				|	pointer ID array ASSIGN decl_init
					{
						$$ = newVarNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
						$$->child[3] = $5;
					}*/
				;

pointer			:	STAR %prec POINTER
					{
						$$ = newPointerNode();
						$$->pointer = 1;
					}
				|	STAR pointer %prec POINTER
					{
						$$ = $2;
						$$->pointer++;
					}
				;

/*array			:	LSQURE RSQURE
					{
						$$ = newArrayNode();
						$$->arraydim = 1;
					}
				|	LSQURE cond_expr RSQURE
					{
						$$ = newArrayNode();
						$$->arraydim = 1;
						$$->child[0] = $2;
					}
				|	LSQURE RSQURE LSQURE cond_expr RSQURE
					{
						$$ = newArrayNode();
						$$->arraydim = 2;
						$$->child[0] = $4;
					}
				|	LSQURE cond_expr RSQURE LSQURE cond_expr RSQURE
					{
						$$ = newArrayNode();
						$$->arraydim = 2;
						$$->child[0] = $2;
						$$->child[1] = $5;
					}
				;*/

decl_init		:	assign_expr
					{
						$$ = $1;
					}
				/*|	decl_prog
					{
						$$ = $1;
					}*/
				;

/*decl_prog		:	LBRACE decl_prog_list RBRACE
					{
						$$ = newInitNode();
						$$->child[0] = $2;
					}
				;*/

/*decl_prog_list	:	assign_expr
					{
						$$ = $1;
					}
				|	decl_prog
					{
						$$ = $1;
					}
				|	assign_expr COMMA decl_prog_list
					{
						if($1)
						{
							$$ = $1;
							$$->sibling = $3;
						}
						else
						{
							$$ = $3;
						}
					}
				|	decl_prog COMMA decl_prog_list
					{
						if($1)
						{
							$$ = $1;
							$$->sibling = $3;
						}
						else
						{
							$$ = $3;
						}
					}
				;*/

decl_list		:	decl_list_unit
					{
						$$ = $1;
					}
				|	decl_list_unit COMMA decl_list
					{
						if($1)
						{
							$$ = $1;
							$$->sibling = $3;
						}
						else
						{
							$$ = $3;
						}
					}
				;

/* Func decline and define */
/*func_decl		:	type_specifier ID LPAREN RPAREN  //eg. int fun()
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
						$$->child[1] = $2;
					}
				|	type_specifier pointer ID LPAREN RPAREN  //eg. int *fun()
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
					}
				|	type_specifier ID LPAREN VOID RPAREN //eg. int fun(void)
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
						$$->child[1] = $2;
					}
				|	type_specifier pointer ID LPAREN VOID RPAREN //eg. int *fun(void)
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
					}
				|	type_specifier ID LPAREN params RPAREN  //eg. int fun(int)
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $4;
					}
				|	type_specifier pointer ID LPAREN params RPAREN  //eg. int *fun(int)
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
						$$->child[3] = $5;
					}
				/*|	ID LPAREN RPAREN %prec FUNCDECL //eg. fun()
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
					}
				|	ID LPAREN params RPAREN  //eg. fun(int)
					{
						$$ = newDeclNode(FuncK);
						$$->child[0] = $1;
						$$->child[1] = $3;
					}*/
				//;*/

/*func_def		:	type_specifier ID LPAREN RPAREN compound_stmt //eg. int fun()
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $5;
					}
				|	type_specifier pointer ID LPAREN RPAREN compound_stmt //eg. int *fun()
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
						$$->child[3] = $6;
					}
				|	type_specifier ID LPAREN VOID RPAREN compound_stmt //eg. int fun(void)
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $6;
					}
				|	type_specifier pointer ID LPAREN VOID RPAREN compound_stmt //eg. int *fun(void)
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
						$$->child[3] = $7;
					}
				|	type_specifier ID LPAREN params RPAREN compound_stmt //eg. int fun(int)
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $4;
						$$->child[3] = $6;
					}
				|	type_specifier pointer ID LPAREN params RPAREN compound_stmt //eg. int *fun(int)
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
						$$->child[3] = $5;
						$$->child[4] = $7;
					}
				/*|	ID LPAREN RPAREN compound_stmt  //eg. fun()
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $4;
					}
				|	ID LPAREN params RPAREN compound_stmt  //eg. fun(int)
					{
						$$ = newFuncDefNode();
						$$->child[0] = $1;
						$$->child[1] = $3;
						$$->child[2] = $5;
					}*/
				//;*/

/*param			:	type_specifier ID
					{
						$$ = newParamNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
					}
				|	type_specifier pointer ID
					{
						$$ = newParamNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
					}
				|	type_specifier ID array
					{
						$$ = newParamNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
					}
				|	type_specifier pointer ID array
					{
						$$ = newParamNode();
						$$->child[0] = $1;
						$$->child[1] = $2;
						$$->child[2] = $3;
						$$->child[3] = $4;
					}
				//;*/

/*params			:	param
					{
						$$ = $1;
					}
				|	param COMMA params
					{
						if($1)
						{
							$$ = $1;
							$$->sibling = $3;
						}
						else
						{
							$$ = $3;
						}
					}
				//;*/

/* Expressions */
expr			:	assign_expr
					{
						$$ = $1;
					}
				|	expr COMMA assign_expr
					{
						if($1)
						{
							$$ = $1;
							TreeNode *t = $$;
							while (t->sibling != NULL)
								t = t->sibling;
							t->sibling = $3;
						}
						else
						{
							$$ = $3;
						}
					}
				;

assign_expr		:	logical_or
					{
						$$ = $1;
					}
				|	unary_expr ASSIGN assign_expr
					{
						$$ = newOpNode(ASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(ASSIGN) == opmap.end())
						{
							opmap[ASSIGN]="=";
						}
					}
				|	unary_expr PLUSASSIGN assign_expr
					{
						$$ = newOpNode(PLUSASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(PLUSASSIGN) == opmap.end())
						{
							opmap[PLUSASSIGN]="+=";
						}
					}
				|	unary_expr MINUSASSIGN assign_expr
					{
						$$ = newOpNode(MINUSASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(MINUSASSIGN) == opmap.end())
						{
							opmap[MINUSASSIGN]="-=";
						}
					}
				|	unary_expr MULASSIGN assign_expr
					{
						$$ = newOpNode(MULASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(MULASSIGN) == opmap.end())
						{
							opmap[MULASSIGN]="*=";
						}
					}
				|	unary_expr OVERASSIGN assign_expr
					{
						$$ = newOpNode(OVERASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(OVERASSIGN) == opmap.end())
						{
							opmap[OVERASSIGN]="/=";
						}
					}
				|	unary_expr MODASSIGN assign_expr
					{
						$$ = newOpNode(MODASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(MODASSIGN) == opmap.end())
						{
							opmap[MODASSIGN]="%=";
						}
					}
				|	unary_expr LSHIFTASSIGN assign_expr
					{
						$$ = newOpNode(LSHIFTASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(LSHIFTASSIGN) == opmap.end())
						{
							opmap[LSHIFTASSIGN]="<<=";
						}
					}
				|	unary_expr RSHIFTASSIGN assign_expr
					{
						$$ = newOpNode(RSHIFTASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(RSHIFTASSIGN) == opmap.end())
						{
							opmap[RSHIFTASSIGN]=">>=";
						}
					}
				|	unary_expr ANDASSIGN assign_expr
					{
						$$ = newOpNode(ANDASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(ANDASSIGN) == opmap.end())
						{
							opmap[ANDASSIGN]="&=";
						}
					}
				|	unary_expr XORASSIGN assign_expr
					{
						$$ = newOpNode(XORASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(XORASSIGN) == opmap.end())
						{
							opmap[XORASSIGN]="^=";
						}
					}
				|	unary_expr ORASSIGN assign_expr
					{
						$$ = newOpNode(ORASSIGN);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(ORASSIGN) == opmap.end())
						{
							opmap[ORASSIGN]="|=";
						}
					}
				;

/*cond_expr		:	logical_or
					{
						$$ = $1;
					}
				|	logical_or QUES expr COLON cond_expr
					{
						$$ = newOpNode(QUES);
						$$->child[0] = $1;
						$$->child[1] = $3;
						$$->child[2] = $5;
						if(opmap.find(QUES) == opmap.end())
						{
							opmap[QUES]="? :";
						}
					}
				;*/

logical_or		:	logical_and
					{
						$$ = $1;
					}
				|	logical_or LOGOR logical_and
					{
						$$ = newOpNode(LOGOR);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(LOGOR) == opmap.end())
						{
							opmap[LOGOR]="||";
						}
					}
				;

logical_and		:	or_expr
					{
						$$ = $1;
					}
				|	logical_and LOGAND or_expr
					{
						$$ = newOpNode(LOGAND);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(LOGAND) == opmap.end())
						{
							opmap[LOGAND]="&&";
						}
					}
				;

or_expr			:	xor_expr
					{
						$$ = $1;
					}
				|	or_expr OR xor_expr
					{
						$$ = newOpNode(OR);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(OR) == opmap.end())
						{
							opmap[OR]="|";
						}
					}
				;

xor_expr		:	and_expr
					{
						$$ = $1;
					}
				|	xor_expr XOR and_expr
					{
						$$ = newOpNode(XOR);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(XOR) == opmap.end())
						{
							opmap[XOR]="^";
						}
					}
				;

and_expr		:	equal_expr
					{
						$$ = $1;
					}
				|	and_expr AND equal_expr
					{
						$$ = newOpNode(AND);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(AND) == opmap.end())
						{
							opmap[AND]="&(AND)";
						}
					}
				;

equal_expr		:	compare_expr
					{
						$$ = $1;
					}
				|	equal_expr EQUAL compare_expr
					{
						$$ = newOpNode(EQUAL);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(EQUAL) == opmap.end())
						{
							opmap[EQUAL]="==";
						}
					}
				|	equal_expr NOTEQUAL compare_expr
					{
						$$ = newOpNode(NOTEQUAL);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(NOTEQUAL) == opmap.end())
						{
							opmap[NOTEQUAL]="!=";
						}
					}
				;

compare_expr	:	shift_expr
					{
						$$ = $1;
					}
				|	compare_expr GREAT shift_expr  //>
					{
						$$ = newOpNode(GREAT);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(GREAT) == opmap.end())
						{
							opmap[GREAT]=">";
						}
					}
				|	compare_expr SMALL shift_expr  //<
					{
						$$ = newOpNode(SMALL);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(SMALL) == opmap.end())
						{
							opmap[SMALL]="<";
						}
					}
				|	compare_expr GREEQU shift_expr  //>=
					{
						$$ = newOpNode(GREEQU);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(GREEQU) == opmap.end())
						{
							opmap[GREEQU]=">=";
						}
					}
				|	compare_expr SMAEQU shift_expr  //<=
					{
						$$ = newOpNode(SMAEQU);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(SMAEQU) == opmap.end())
						{
							opmap[SMAEQU]="<=";
						}
					}
				;

shift_expr		:	add_expr
					{
						$$ = $1;
					}
				|	shift_expr SHIFTLEFT add_expr  //<<
					{
						$$ = newOpNode(SHIFTLEFT);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(SHIFTLEFT) == opmap.end())
						{
							opmap[SHIFTLEFT]="<<";
						}
					}
				|	shift_expr SHIFTRIGHT add_expr //>>
					{
						$$ = newOpNode(SHIFTRIGHT);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(SHIFTRIGHT) == opmap.end())
						{
							opmap[SHIFTRIGHT]=">>";
						}
					}
				;

add_expr		:	mul_expr
					{
						$$ = $1;
					}
				|	add_expr PLUS mul_expr
					{
						$$ = newOpNode(PLUS);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(PLUS) == opmap.end())
						{
							opmap[PLUS]="+(PLUS)";
						}
					}
				|	add_expr MINUS mul_expr
					{
						$$ = newOpNode(MINUS);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(MINUS) == opmap.end())
						{
							opmap[MINUS]="-(MINUS)";
						}
					}
				;

mul_expr		:	unary_expr
					{
						$$ = $1;
					}
				|	mul_expr STAR unary_expr %prec MUL
					{
						$$ = newOpNode(MUL);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(MUL) == opmap.end())
						{
							opmap[MUL]="*(MUL)";
						}
					}
				|	mul_expr OVER unary_expr
					{
						$$ = newOpNode(OVER);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(OVER) == opmap.end())
						{
							opmap[OVER]="/";
						}
					}
				|	mul_expr MOD unary_expr
					{
						$$ = newOpNode(MOD);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(MOD) == opmap.end())
						{
							opmap[MOD]="%";
						}
					}
				;

unary_expr		:	factor
					{
						$$ = $1;
					}
				|	MINUS factor %prec MINUSU
					{
						$$ = newOpNode(MINUSU);
						$$->child[0] = $2;
						if(opmap.find(MINUSU) == opmap.end())
						{
							opmap[MINUSU]="-(MINUSU)";
						}
					}
				|	PLUS factor %prec PLUSU
					{
						$$ = newOpNode(PLUSU);
						$$->child[0] = $2;
						if(opmap.find(PLUSU) == opmap.end())
						{
							opmap[PLUSU]="+(PLUSU)";
						}
					}
				|	NOT factor
					{
						$$ = newOpNode(NOT);
						$$->child[0] = $2;
						if(opmap.find(NOT) == opmap.end())
						{
							opmap[NOT]="!";
						}
					}
				|	NEG factor
					{
						$$ = newOpNode(NEG);
						$$->child[0] = $2;
						if(opmap.find(NEG) == opmap.end())
						{
							opmap[NEG]="~";
						}
					}
				|	STAR factor %prec GETDATA
					{
						$$ = newOpNode(GETDATA);
						$$->child[0] = $2;
						if(opmap.find(GETDATA) == opmap.end())
						{
							opmap[GETDATA]="*(GETDATA)";
						}
					}
				|	AND factor %prec GETADDR
					{
						$$ = newOpNode(GETADDR);
						$$->child[0] = $2;
						if(opmap.find(GETADDR) == opmap.end())
						{
							opmap[GETADDR]="&(GETADDR)";
						}
					}
				|	PLUSPLUS factor %prec PLUSPLUSL
					{
						$$ = newOpNode(PLUSPLUSL);
						$$->child[0] = $2;
						if(opmap.find(PLUSPLUSL) == opmap.end())
						{
							opmap[PLUSPLUSL]="++(L)";
						}
					}
				|	MINUSMINUS factor %prec MINUSMINUSL
					{
						$$ = newOpNode(MINUSMINUSL);
						$$->child[0] = $2;
						if(opmap.find(MINUSMINUSL) == opmap.end())
						{
							opmap[MINUSMINUSL]="--(l)";
						}
					}
				|	factor PLUSPLUS %prec PLUSPLUSR
					{
						$$ = newOpNode(PLUSPLUSR);
						$$->child[0] = $1;
						if(opmap.find(PLUSPLUSR) == opmap.end())
						{
							opmap[PLUSPLUSR]="++(R)";
						}
					}
				|	factor MINUSMINUS %prec MINUSMINUSR
					{
						$$ = newOpNode(MINUSMINUSR);
						$$->child[0] = $1;
						if(opmap.find(MINUSMINUSR) == opmap.end())
						{
							opmap[MINUSMINUSR]="--(R)";
						}
					}
				/*|	SIZEOF LPAREN type_specifier RPAREN
					{
						$$ = newOpNode(SIZEOF);
						$$->child[0] = $3;
						if(opmap.find(SIZEOF) == opmap.end())
						{
							opmap[SIZEOF]="sizeof";
						}
					}
				|	SIZEOF LPAREN type_specifier pointer RPAREN
					{
						$$ = newOpNode(SIZEOF);
						$$->child[0] = $3;
						$3->sibling = $4;
						if(opmap.find(SIZEOF) == opmap.end())
						{
							opmap[SIZEOF]="sizeof";
						}
					}
				/*|	SIZEOF LPAREN type_specifier array RPAREN
					{
						$$ = newOpNode(SIZEOF);
						$$->child[0] = $3;
						$3->sibling = $4;
						if(opmap.find(SIZEOF) == opmap.end())
						{
							opmap[SIZEOF]="sizeof";
						}
					}*/
				/*|	SIZEOF LPAREN type_specifier pointer array RPAREN
					{
						$$ = newOpNode(SIZEOF);
						$$->child[0] = $3;
						$3->sibling = $4;
						$3->sibling->sibling = $5;
						if(opmap.find(SIZEOF) == opmap.end())
						{
							opmap[SIZEOF]="sizeof";
						}
					}*/
				/*|	SIZEOF factor
					{
						$$ = newOpNode(SIZEOF);
						$$->child[0] = $2;
						if(opmap.find(SIZEOF) == opmap.end())
						{
							opmap[SIZEOF]="sizeof";
						}
					}*/
				|	LPAREN type_specifier RPAREN factor
					{
						$$ = newForceCastNode();
						$$->child[0] = $2;
						$$->child[1] = $4;
						$$->type = $$->child[0]->type;
					}
				|	LPAREN type_specifier pointer RPAREN factor
					{
						$$ = newForceCastNode();
						$$->child[0] = $2;
						$$->child[1] = $3;
						$$->child[2] = $5;
						$$->type = $$->child[0]->type;
						$$->pointer = $$->child[1]->pointer;
					}
				/*|	LPAREN type_specifier array RPAREN factor
					{
						$$ = newForceCastNode();
						$$->child[0] = $2;
						$$->child[1] = $3;
						$$->child[2] = $5;
					}*/
				/*|	LPAREN type_specifier pointer array RPAREN factor
					{
						$$ = newForceCastNode();
						$$->child[0] = $2;
						$$->child[1] = $3;
						$$->child[2] = $4;
						$$->child[3] = $5;
					}*/
				;

factor			:	ID
					{
						$$ = $1;
					}
				|	NUM
					{
						$$ = $1;
					}
				|	CHARCONST
					{
						$$ = $1;
					}
				|	STRCONST
					{
						$$ = $1;
					}
				|	LPAREN expr RPAREN
					{
						$$ = $2;
					}
				/*|	factor POINTMEM ID
					{
						$$ = newOpNode(POINTMEM);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(POINTMEM) == opmap.end())
						{
							opmap[POINTMEM]=".";
						}
					}
				|	factor ARROWMEM ID
					{
						$$ = newOpNode(ARROWMEM);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(ARROWMEM) == opmap.end())
						{
							opmap[ARROWMEM]="->";
						}
					}*/
				/*|	factor LSQURE logical_or RSQURE
					{
						$$ = newOpNode(LSQURE);
						$$->child[0] = $1;
						$$->child[1] = $3;
						if(opmap.find(LSQURE) == opmap.end())
						{
							opmap[LSQURE]="[]";
						}
					}*/
				/*|	func_call
					{
						$$ = $1;
					}*/
				;

/*call_param		:	expr
					{
						$$=newParamNode();
						$$->child[0]=$1;
					}
				|	expr COMMA call_param
					{
						$1->sibling = $3->child[0];
						$$ = $3;
						$$->child[0] = $1;
					}
				;

func_call		:	ID LPAREN RPAREN
					{
						$$ = newFuncCallNode();
						$$->child[0] = $1;
					}
				|	ID LPAREN call_param RPAREN
					{
						$$ = newFuncCallNode();
						$$->child[0] = $1;
						$$->child[1] = $3;
					}
				;*/


/* Statements */
stmt			:	if_stmt
					{
						$$ = $1;
					}
				|	for_stmt
					{
						$$ = $1;
					}
				|	while_stmt
					{
						$$ = $1;
					}
				|	do_while_stmt
					{
						$$ = $1;
					}
				|	label_stmt
					{
						$$ = $1;
					}
				|	goto_stmt
					{
						$$ = $1;
					}
				|	continue_stmt
					{
						$$ = $1;
					}
				|	break_stmt
					{
						$$ = $1;
					}
				|	return_stmt
					{
						$$ = $1;
					}
				|	expr_stmt
					{
						$$ = $1;
					}
				|	var_decl_stmt
					{
						$$ = $1;
					}
				/*|	func_decl_stmt
					{
						$$ = $1;
					}*/
				|	compound_stmt
					{
						$$ = $1;
					}
				|	input_stmt
					{
						$$ = $1;
					}
				|	output_stmt
					{
						$$ = $1;
					}
				;

input_stmt		:	INPUT LPAREN expr RPAREN SEMICOLON
					{
						$$ = newStmtNode(InputK);
						$$->child[0] = $3;
					}
				;

output_stmt		:	OUTPUT LPAREN expr RPAREN SEMICOLON
					{
						$$ = newStmtNode(OutputK);
						$$->child[0] = $3;
					}
				;

input_stmt		:	INPUT SHIFTRIGHT expr SEMICOLON
					{
						$$ = newStmtNode(InputK);
						$$->child[0] = $3;
					}
				;

output_stmt		:	OUTPUT SHIFTLEFT expr SEMICOLON
					{
						$$ = newStmtNode(OutputK);
						$$->child[0] = $3;
					}
				;

label_stmt		:	ID COLON stmt
					{
						$$ = newStmtNode(LabelK);
						$$->child[0] = $1;
						$$->child[1] = $3;
					}
				|	CASE COLON stmt
					{
						$$ = newStmtNode(LabelK);
						$$->child[0] = $1;
						$$->child[1] = $3;
					}
				|	DEFAULT COLON stmt
					{
						$$ = newStmtNode(LabelK);
						$$->child[0] = $1;
						$$->child[1] = $3;
					}
				;

goto_stmt		:	GOTO ID SEMICOLON
					{
						$$ = newStmtNode(GotoK);
						$$->child[0] = $1;
						$$->child[1] = $2;
					}
				;

continue_stmt	:	CONTINUE SEMICOLON
					{
						$$ = newStmtNode(ContK);
					}
				;

break_stmt		:	BREAK SEMICOLON
					{
						$$ = newStmtNode(BreakK);
					}
				;

return_stmt		:	RETURN SEMICOLON
					{
						$$ = newStmtNode(RetK);
					}
				|	RETURN expr SEMICOLON
					{
						$$ = newStmtNode(RetK);
						$$->child[0] = $2;
					}
				;

var_decl_stmt	:	var_decl SEMICOLON
					{
						$$ = $1;
					}
				/*|	struct_union_spci SEMICOLON
					{
						$$ = $1;
					}*/
				;

/*func_decl_stmt 	:	func_decl SEMICOLON
					{
						$$ = $1;
					}
				//;*/

expr_stmt		:	expr SEMICOLON
					{
						$$ = $1;
					}
				|	SEMICOLON
					{
						$$ = NULL;
					}
				;

compound_stmt	:	LBRACE stmts RBRACE
					{
						$$ = newStmtNode(CompK);
						$$->child[0] = $2;
					}
				;

stmts			:	stmt stmts
					{
						if($1)
						{
							$$ = $1;
							$$->sibling = $2;
						}
						else
						{
							$$ = $2;
						}
						//ShowNode($$);
					}
				|	stmt
					{
						$$ = $1;
						//ShowNode($$);
					}
				|	
					{
						$$ = NULL;
					}
				;

if_stmt			:	IF LPAREN expr RPAREN stmt %prec IFU
					{
						$$ = newStmtNode(IfK);
						$$->child[0] = $3;
						$$->child[1] = $5;
					}
				|	IF LPAREN expr RPAREN stmt ELSE stmt
					{
						$$ = newStmtNode(IfK);
						$$->child[0] = $3;
						$$->child[1] = $5;
						$$->child[2] = $7;
					}
				;

while_stmt		:	WHILE LPAREN expr RPAREN stmt
					{
						$$ = newStmtNode(WhileK);
						$$->child[0] = $3;
						$$->child[1] = $5;
					}
				;

do_while_stmt	:	DO stmt WHILE LPAREN expr RPAREN SEMICOLON
					{
						$$ = newStmtNode(DoWhileK);
						$$->child[0] = $2;
						$$->child[1] = $5;
					}
				;

for_stmt		:	FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = $3;
						$$->child[1] = $5;
						$$->child[2] = $7;
						$$->child[3] = $9;
					}
				|	FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = $3;
						$$->child[1] = $5;
						$$->child[2] = NULL;
						$$->child[3] = $8;
					}
				|	FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = $3;
						$$->child[1] = NULL;
						$$->child[2] = $6;
						$$->child[3] = $8;
					}
				|	FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = $3;
						$$->child[1] = NULL;
						$$->child[2] = NULL;
						$$->child[3] = $7;
					}
				|	FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = NULL;
						$$->child[1] = $4;
						$$->child[2] = $6;
						$$->child[3] = $8;
					}
				|	FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = NULL;
						$$->child[1] = $4;
						$$->child[2] = NULL;
						$$->child[3] = $7;
					}
				|	FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = NULL;
						$$->child[1] = NULL;
						$$->child[2] = $5;
						$$->child[3] = $7;
					}
				|	FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt
					{
						$$ = newStmtNode(ForK);
						$$->child[0] = NULL;
						$$->child[1] = NULL;
						$$->child[2] = NULL;
						$$->child[3] = $6;
					}
				;


%%

/////////////////////////////////////////////////////////////////////////////
// programs section

void myparser::yyerror(const char YYFAR* text)
{
	char *curr=*currtext;
	int len=strlen(curr);
	int i;
	char buf[512]={0};
	for (i=0;i<len;++i)
	{
		sprintf(buf,"%s%c(%d) ",buf,curr[i],curr[i]);
	}
	fprintf(stderr, "ERROR: %s at symbol '%s' on line %d\n", text, buf, num_lines);
	yyparse();
}


int main(int argc, char *argv[])
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			if (argc == 4)
			{
				if (strcmp(argv[1],"-S")==0) //compile
				{
					string basename(argv[3]);
					if(basename.find(".")>=0)
					{
						basename=basename.substr(0,basename.find("."));
					}
					lexer.yyin = new ifstream(argv[2]);
					string asmfile=basename+".asm";
					lexer.yyout = new ofstream(asmfile);
					if(!lexer.yyin->fail())
					{
						n = parser.yyparse();
						Traverse(root);
						Display(root);
						cout << endl;
						printSymTable();
						get_label();
						gen_code(*(lexer.yyout));
					}
					else
					{
						cout << "Input file: No such file or directory!" <<endl;
					}
				}
				else if (strcmp(argv[1],"-c")==0) //assembly
				{
					string basename(argv[3]);
					if(basename.find(".")>=0)
					{
						basename=basename.substr(0,basename.find("."));
					}
					lexer.yyin = new ifstream(argv[2]);
					string asmfile=basename+".asm";
					lexer.yyout = new ofstream(asmfile);
					if(!lexer.yyin->fail())
					{
						n = parser.yyparse();
						Traverse(root);
						Display(root);
						cout << endl;
						printSymTable();
						get_label();
						gen_code(*(lexer.yyout));
						string asmcmd;
						asmcmd="ml /c /coff "+asmfile;
						system(asmcmd.c_str());
					}
					else
					{
						cout << "Input file: No such file or directory!" <<endl;
					}
				}
				else
				{
					//unrecognized command line option
					string a(argv[1]);
					if(a.find("-")==0)
					{
						cout << a <<": unrecognized command line option!" <<endl;
					}
					else
					{
						cout << "unrecognized command line option!" <<endl;
					}
				}
			}
			else if (argc == 3)
			{
				if (strcmp(argv[1],"-m")==0) //generate tree
				{
					lexer.yyin = new ifstream(argv[2]);
					if(!lexer.yyin->fail())
					{
						n = parser.yyparse();
						Traverse(root);
						Display(root);
						cout << endl;
						printSymTable();
					}
					else
					{
						cout << "Input file: No such file or directory!" <<endl;
					}
				}
				else if (strcmp(argv[1],"-S")==0) //compile
				{
					string basename;
					basename="a";
					lexer.yyin = new ifstream(argv[2]);
					string asmfile=basename+".asm";
					lexer.yyout = new ofstream(asmfile);
					if(!lexer.yyin->fail())
					{
						n = parser.yyparse();
						Traverse(root);
						Display(root);
						cout << endl;
						printSymTable();
						get_label();
						gen_code(*(lexer.yyout));
					}
					else
					{
						cout << "Input file: No such file or directory!" <<endl;
					}
				}
				else if (strcmp(argv[1],"-c")==0) //assembly
				{
					string basename;
					basename="a";
					lexer.yyin = new ifstream(argv[2]);
					string asmfile=basename+".asm";
					lexer.yyout = new ofstream(asmfile);
					if(!lexer.yyin->fail())
					{
						n = parser.yyparse();
						Traverse(root);
						Display(root);
						cout << endl;
						printSymTable();
						get_label();
						gen_code(*(lexer.yyout));
						string asmcmd;
						asmcmd="ml /c /coff "+asmfile;
						system(asmcmd.c_str());
					}
					else
					{
						cout << "Input file: No such file or directory!" <<endl;
					}
				}
				else //gen executable file
				{
					string basename(argv[2]);
					if(basename.find(".")>=0)
					{
						basename=basename.substr(0,basename.find("."));
					}
					lexer.yyin = new ifstream(argv[1]);
					string asmfile=basename+".asm";
					lexer.yyout = new ofstream(asmfile);
					if(!lexer.yyin->fail())
					{
						n = parser.yyparse();
						Traverse(root);
						Display(root);
						cout << endl;
						printSymTable();
						get_label();
						gen_code(*(lexer.yyout));
						string asmcmd;
						asmcmd="ml /c /coff "+asmfile;
						system(asmcmd.c_str());
						string linkcmd;
						linkcmd="link /subsystem:console "+basename+".obj";
						system(linkcmd.c_str());
					}
					else
					{
						string a(argv[1]);
						if(a.find("-")==0)
						{
							cout << a <<": unrecognized command line option" <<endl;
						}
						else
						{
							cout << "Input file: No such file or directory" <<endl;
						}
					}
				}
			}
			else if (argc == 2)
			{
				//help
				if (strcmp(argv[1],"-h")==0)
				{
					cout <<"Command option help:" <<endl;
					cout <<"-h: help" <<endl;
					cout <<"-v: version" <<endl;
					cout <<"-m: generate syntax tree" <<endl;
					cout <<"-S: compile"<<endl;
					cout <<"-c: assembly" <<endl;
					cout <<"default: generate executable file"<<endl;
				}
				else if (strcmp(argv[1],"-v")==0)
				{
					cout <<"Version: 1.0" <<endl;
				}
				else //gen executable file
				{
					string basename;
					basename="a";
					lexer.yyin = new ifstream(argv[1]);
					string asmfile=basename+".asm";
					lexer.yyout = new ofstream(asmfile);
					if(!lexer.yyin->fail())
					{
						n = parser.yyparse();
						Traverse(root);
						Display(root);
						cout << endl;
						printSymTable();
						get_label();
						gen_code(*(lexer.yyout));
						string asmcmd;
						asmcmd="ml /c /coff "+asmfile;
						system(asmcmd.c_str());
						string linkcmd;
						linkcmd="link /subsystem:console "+basename+".obj";
						system(linkcmd.c_str());
					}
					else
					{
						string a(argv[1]);
						if(a.find("-")==0)
						{
							cout << a <<": unrecognized command line option!" <<endl;
						}
						else
						{
							cout << "Input file: No such file or directory!" <<endl;
						}
					}
				}
			}
			else if (argc == 1)
			{
				//no input file
				cout << "no input file!" <<endl;
			}
			else
			{
				//unrecognized command line option
				cout << "unrecognized command line option!" <<endl;
			}
		}
	}
	return n;
}

