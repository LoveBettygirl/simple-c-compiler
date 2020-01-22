/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 72 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/19/19
* Time: 10:43:03
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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


#line 103 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 79 ".\\myparser.y"

	// place any extra initialisation code here

#line 127 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 84 ".\\myparser.y"

	// place any extra cleanup code here

#line 141 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 132 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
						//cout<<"program entry"<<endl;
						root = (*(YYSTYPE YYFAR*)yyvalptr);
					
#line 255 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 138 ".\\myparser.y"

						if(yyattribute(1 - 2))
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
							(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(2 - 2);
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
						}
						root = (*(YYSTYPE YYFAR*)yyvalptr);
					
#line 279 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 153 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(5 - 5);
					
#line 294 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 157 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(4 - 4);
					
#line 309 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 161 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(6 - 6);
					
#line 324 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 165 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(5 - 5);
					
#line 339 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#line 179 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = NULL;
					
#line 349 "myparser.cpp"
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 185 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 363 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 189 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
						TreeNode *temp1 = yyattribute(1 - 1)->child[1];
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
					
#line 403 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 229 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 418 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 233 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 433 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 249 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 448 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 259 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newDeclNode(VarK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(2 - 2);
						(*(YYSTYPE YYFAR*)yyvalptr)->type = (*(YYSTYPE YYFAR*)yyvalptr)->child[0]->type;
						TreeNode *temp1 = yyattribute(2 - 2);
						for(;temp1;temp1=temp1->sibling)
						{
							if(temp1->nodekind == ExpK && temp1->kind.exp == IdK)
							{
								Symbol *sym = lookup_table(temp1->attr.idname);
								sym->base_type = yyattribute(1 - 2)->type;
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
											sym->base_type = yyattribute(1 - 2)->type;
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
					
#line 514 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 314 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newDeclNode(VarK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(2 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(3 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->type = (*(YYSTYPE YYFAR*)yyvalptr)->child[1]->type;
						TreeNode *temp1 = yyattribute(3 - 3);
						for(;temp1;temp1=temp1->sibling)
						{
							if(temp1->nodekind == ExpK && temp1->kind.exp == IdK)
							{
								Symbol *sym = lookup_table(temp1->attr.idname);
								sym->base_type = yyattribute(1 - 3)->type;
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
											sym->base_type = yyattribute(1 - 3)->type;
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
					
#line 583 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 422 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 598 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 475 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newPointerNode();
						(*(YYSTYPE YYFAR*)yyvalptr)->pointer = 1;
					
#line 614 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 480 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
						(*(YYSTYPE YYFAR*)yyvalptr)->pointer++;
					
#line 630 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 513 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 645 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 564 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 660 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 568 ".\\myparser.y"

						if(yyattribute(1 - 3))
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(3 - 3);
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(3 - 3);
						}
					
#line 683 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 748 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 698 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 752 ".\\myparser.y"

						if(yyattribute(1 - 3))
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
							TreeNode *t = (*(YYSTYPE YYFAR*)yyvalptr);
							while (t->sibling != NULL)
								t = t->sibling;
							t->sibling = yyattribute(3 - 3);
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(3 - 3);
						}
					
#line 724 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 769 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 739 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 773 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(ASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(ASSIGN) == opmap.end())
						{
							opmap[ASSIGN]="=";
						}
					
#line 760 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 783 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(PLUSASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(PLUSASSIGN) == opmap.end())
						{
							opmap[PLUSASSIGN]="+=";
						}
					
#line 781 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 793 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MINUSASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(MINUSASSIGN) == opmap.end())
						{
							opmap[MINUSASSIGN]="-=";
						}
					
#line 802 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 803 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MULASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(MULASSIGN) == opmap.end())
						{
							opmap[MULASSIGN]="*=";
						}
					
#line 823 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 813 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(OVERASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(OVERASSIGN) == opmap.end())
						{
							opmap[OVERASSIGN]="/=";
						}
					
#line 844 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 823 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MODASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(MODASSIGN) == opmap.end())
						{
							opmap[MODASSIGN]="%=";
						}
					
#line 865 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 833 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(LSHIFTASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(LSHIFTASSIGN) == opmap.end())
						{
							opmap[LSHIFTASSIGN]="<<=";
						}
					
#line 886 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 843 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(RSHIFTASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(RSHIFTASSIGN) == opmap.end())
						{
							opmap[RSHIFTASSIGN]=">>=";
						}
					
#line 907 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 853 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(ANDASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(ANDASSIGN) == opmap.end())
						{
							opmap[ANDASSIGN]="&=";
						}
					
#line 928 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 863 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(XORASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(XORASSIGN) == opmap.end())
						{
							opmap[XORASSIGN]="^=";
						}
					
#line 949 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 873 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(ORASSIGN);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(ORASSIGN) == opmap.end())
						{
							opmap[ORASSIGN]="|=";
						}
					
#line 970 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 902 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 985 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 906 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(LOGOR);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(LOGOR) == opmap.end())
						{
							opmap[LOGOR]="||";
						}
					
#line 1006 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 918 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1021 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 922 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(LOGAND);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(LOGAND) == opmap.end())
						{
							opmap[LOGAND]="&&";
						}
					
#line 1042 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 934 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1057 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 938 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(OR);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(OR) == opmap.end())
						{
							opmap[OR]="|";
						}
					
#line 1078 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 950 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1093 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 954 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(XOR);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(XOR) == opmap.end())
						{
							opmap[XOR]="^";
						}
					
#line 1114 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 966 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1129 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 970 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(AND);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(AND) == opmap.end())
						{
							opmap[AND]="&(AND)";
						}
					
#line 1150 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 982 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1165 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 986 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(EQUAL);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(EQUAL) == opmap.end())
						{
							opmap[EQUAL]="==";
						}
					
#line 1186 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 996 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(NOTEQUAL);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(NOTEQUAL) == opmap.end())
						{
							opmap[NOTEQUAL]="!=";
						}
					
#line 1207 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1008 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1222 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1012 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(GREAT);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(GREAT) == opmap.end())
						{
							opmap[GREAT]=">";
						}
					
#line 1243 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1022 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(SMALL);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(SMALL) == opmap.end())
						{
							opmap[SMALL]="<";
						}
					
#line 1264 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1032 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(GREEQU);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(GREEQU) == opmap.end())
						{
							opmap[GREEQU]=">=";
						}
					
#line 1285 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1042 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(SMAEQU);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(SMAEQU) == opmap.end())
						{
							opmap[SMAEQU]="<=";
						}
					
#line 1306 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1054 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1321 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1058 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(SHIFTLEFT);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(SHIFTLEFT) == opmap.end())
						{
							opmap[SHIFTLEFT]="<<";
						}
					
#line 1342 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1068 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(SHIFTRIGHT);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(SHIFTRIGHT) == opmap.end())
						{
							opmap[SHIFTRIGHT]=">>";
						}
					
#line 1363 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1080 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1378 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1084 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(PLUS);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(PLUS) == opmap.end())
						{
							opmap[PLUS]="+(PLUS)";
						}
					
#line 1399 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1094 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MINUS);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(MINUS) == opmap.end())
						{
							opmap[MINUS]="-(MINUS)";
						}
					
#line 1420 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1106 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1435 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1110 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MUL);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(MUL) == opmap.end())
						{
							opmap[MUL]="*(MUL)";
						}
					
#line 1456 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1120 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(OVER);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(OVER) == opmap.end())
						{
							opmap[OVER]="/";
						}
					
#line 1477 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1130 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MOD);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
						if(opmap.find(MOD) == opmap.end())
						{
							opmap[MOD]="%";
						}
					
#line 1498 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1142 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1513 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1146 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MINUSU);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(MINUSU) == opmap.end())
						{
							opmap[MINUSU]="-(MINUSU)";
						}
					
#line 1533 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1155 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(PLUSU);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(PLUSU) == opmap.end())
						{
							opmap[PLUSU]="+(PLUSU)";
						}
					
#line 1553 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1164 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(NOT);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(NOT) == opmap.end())
						{
							opmap[NOT]="!";
						}
					
#line 1573 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1173 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(NEG);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(NEG) == opmap.end())
						{
							opmap[NEG]="~";
						}
					
#line 1593 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1182 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(GETDATA);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(GETDATA) == opmap.end())
						{
							opmap[GETDATA]="*(GETDATA)";
						}
					
#line 1613 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1191 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(GETADDR);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(GETADDR) == opmap.end())
						{
							opmap[GETADDR]="&(GETADDR)";
						}
					
#line 1633 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1200 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(PLUSPLUSL);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(PLUSPLUSL) == opmap.end())
						{
							opmap[PLUSPLUSL]="++(L)";
						}
					
#line 1653 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1209 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MINUSMINUSL);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
						if(opmap.find(MINUSMINUSL) == opmap.end())
						{
							opmap[MINUSMINUSL]="--(l)";
						}
					
#line 1673 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1218 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(PLUSPLUSR);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
						if(opmap.find(PLUSPLUSR) == opmap.end())
						{
							opmap[PLUSPLUSR]="++(R)";
						}
					
#line 1693 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1227 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newOpNode(MINUSMINUSR);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
						if(opmap.find(MINUSMINUSR) == opmap.end())
						{
							opmap[MINUSMINUSR]="--(R)";
						}
					
#line 1713 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1285 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newForceCastNode();
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 4);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 4);
						(*(YYSTYPE YYFAR*)yyvalptr)->type = (*(YYSTYPE YYFAR*)yyvalptr)->child[0]->type;
					
#line 1731 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1292 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newForceCastNode();
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 5);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 5);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(5 - 5);
						(*(YYSTYPE YYFAR*)yyvalptr)->type = (*(YYSTYPE YYFAR*)yyvalptr)->child[0]->type;
						(*(YYSTYPE YYFAR*)yyvalptr)->pointer = (*(YYSTYPE YYFAR*)yyvalptr)->child[1]->pointer;
					
#line 1751 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1318 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1766 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1322 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1781 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1326 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1796 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1330 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1811 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1334 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
					
#line 1826 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1402 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1841 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1406 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1856 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1410 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1871 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1414 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1886 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1418 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1901 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1422 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1916 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1426 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1931 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1430 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1946 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1434 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1961 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1438 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1976 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1442 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1991 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1450 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 2006 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1454 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 2021 "myparser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1458 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 2036 "myparser.cpp"
			}
		}
		break;
	case 94:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1464 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
					
#line 2052 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1471 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(OutputK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
					
#line 2068 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1478 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 4);
					
#line 2084 "myparser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1485 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(OutputK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 4);
					
#line 2100 "myparser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1492 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(LabelK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
					
#line 2117 "myparser.cpp"
			}
		}
		break;
	case 99:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1498 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(LabelK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
					
#line 2134 "myparser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1504 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(LabelK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
					
#line 2151 "myparser.cpp"
			}
		}
		break;
	case 101:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1512 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(GotoK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(2 - 3);
					
#line 2168 "myparser.cpp"
			}
		}
		break;
	case 102:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1520 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ContK);
					
#line 2183 "myparser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1526 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(BreakK);
					
#line 2198 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1532 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(RetK);
					
#line 2213 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1536 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(RetK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 3);
					
#line 2229 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1543 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
					
#line 2244 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1559 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
					
#line 2259 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1563 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = NULL;
					
#line 2274 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1569 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 3);
					
#line 2290 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1576 ".\\myparser.y"

						if(yyattribute(1 - 2))
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
							(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(2 - 2);
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
						}
						//ShowNode($$);
					
#line 2314 "myparser.cpp"
			}
		}
		break;
	case 111:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1589 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
						//ShowNode($$);
					
#line 2330 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#line 1594 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = NULL;
					
#line 2340 "myparser.cpp"
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1600 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
					
#line 2356 "myparser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1606 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 7);
					
#line 2374 "myparser.cpp"
			}
		}
		break;
	case 115:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1615 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WhileK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
					
#line 2391 "myparser.cpp"
			}
		}
		break;
	case 116:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1623 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(DoWhileK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
					
#line 2408 "myparser.cpp"
			}
		}
		break;
	case 117:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 1631 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 9);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 9);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 9);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(9 - 9);
					
#line 2427 "myparser.cpp"
			}
		}
		break;
	case 118:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 1639 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
					
#line 2446 "myparser.cpp"
			}
		}
		break;
	case 119:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 1647 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
					
#line 2465 "myparser.cpp"
			}
		}
		break;
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1655 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
					
#line 2484 "myparser.cpp"
			}
		}
		break;
	case 121:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 1663 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
					
#line 2503 "myparser.cpp"
			}
		}
		break;
	case 122:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1671 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
					
#line 2522 "myparser.cpp"
			}
		}
		break;
	case 123:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1679 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(5 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
					
#line 2541 "myparser.cpp"
			}
		}
		break;
	case 124:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 1687 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
						(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
						(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(6 - 6);
					
#line 2560 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "MAIN", 257 },
		{ "CHAR", 258 },
		{ "INT", 260 },
		{ "VOID", 269 },
		{ "IF", 270 },
		{ "ELSE", 271 },
		{ "CASE", 273 },
		{ "DEFAULT", 274 },
		{ "FOR", 275 },
		{ "DO", 276 },
		{ "WHILE", 277 },
		{ "BREAK", 278 },
		{ "CONTINUE", 279 },
		{ "GOTO", 280 },
		{ "RETURN", 281 },
		{ "STATIC", 284 },
		{ "ID", 289 },
		{ "NUM", 290 },
		{ "CHARCONST", 291 },
		{ "STRCONST", 292 },
		{ "PLUSPLUS", 295 },
		{ "MINUSMINUS", 296 },
		{ "SHIFTLEFT", 297 },
		{ "SHIFTRIGHT", 298 },
		{ "GREEQU", 299 },
		{ "SMAEQU", 300 },
		{ "EQUAL", 301 },
		{ "NOTEQUAL", 302 },
		{ "LOGAND", 303 },
		{ "LOGOR", 304 },
		{ "PLUSASSIGN", 305 },
		{ "MINUSASSIGN", 306 },
		{ "MULASSIGN", 307 },
		{ "OVERASSIGN", 308 },
		{ "MODASSIGN", 309 },
		{ "LSHIFTASSIGN", 310 },
		{ "RSHIFTASSIGN", 311 },
		{ "ANDASSIGN", 312 },
		{ "XORASSIGN", 313 },
		{ "ORASSIGN", 314 },
		{ "NOT", 315 },
		{ "NEG", 316 },
		{ "STAR", 317 },
		{ "OVER", 318 },
		{ "MOD", 319 },
		{ "PLUS", 320 },
		{ "MINUS", 321 },
		{ "GREAT", 322 },
		{ "SMALL", 323 },
		{ "AND", 324 },
		{ "OR", 325 },
		{ "XOR", 326 },
		{ "ASSIGN", 327 },
		{ "COLON", 329 },
		{ "LBRACE", 330 },
		{ "RBRACE", 331 },
		{ "LPAREN", 332 },
		{ "RPAREN", 333 },
		{ "SEMICOLON", 336 },
		{ "COMMA", 337 },
		{ "MUL", 339 },
		{ "POINTER", 340 },
		{ "GETADDR", 341 },
		{ "GETDATA", 342 },
		{ "PLUSU", 343 },
		{ "MINUSU", 344 },
		{ "PLUSPLUSL", 345 },
		{ "PLUSPLUSR", 346 },
		{ "MINUSMINUSL", 347 },
		{ "MINUSMINUSR", 348 },
		{ "INPUT", 349 },
		{ "OUTPUT", 350 },
		{ "IFU", 353 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: global_decl",
		"program: global_decl program",
		"entry: type_specifier MAIN LPAREN RPAREN compound_stmt",
		"entry: MAIN LPAREN RPAREN compound_stmt",
		"entry: type_specifier MAIN LPAREN VOID RPAREN compound_stmt",
		"entry: MAIN LPAREN VOID RPAREN compound_stmt",
		"entry:",
		"global_decl: entry",
		"global_decl: var_decl_stmt",
		"type_specifier: INT",
		"type_specifier: CHAR",
		"type_specifier: VOID",
		"var_decl: type_specifier decl_list",
		"var_decl: STATIC type_specifier decl_list",
		"decl_list_unit: ID",
		"pointer: STAR",
		"pointer: STAR pointer",
		"decl_init: assign_expr",
		"decl_list: decl_list_unit",
		"decl_list: decl_list_unit COMMA decl_list",
		"expr: assign_expr",
		"expr: expr COMMA assign_expr",
		"assign_expr: logical_or",
		"assign_expr: unary_expr ASSIGN assign_expr",
		"assign_expr: unary_expr PLUSASSIGN assign_expr",
		"assign_expr: unary_expr MINUSASSIGN assign_expr",
		"assign_expr: unary_expr MULASSIGN assign_expr",
		"assign_expr: unary_expr OVERASSIGN assign_expr",
		"assign_expr: unary_expr MODASSIGN assign_expr",
		"assign_expr: unary_expr LSHIFTASSIGN assign_expr",
		"assign_expr: unary_expr RSHIFTASSIGN assign_expr",
		"assign_expr: unary_expr ANDASSIGN assign_expr",
		"assign_expr: unary_expr XORASSIGN assign_expr",
		"assign_expr: unary_expr ORASSIGN assign_expr",
		"logical_or: logical_and",
		"logical_or: logical_or LOGOR logical_and",
		"logical_and: or_expr",
		"logical_and: logical_and LOGAND or_expr",
		"or_expr: xor_expr",
		"or_expr: or_expr OR xor_expr",
		"xor_expr: and_expr",
		"xor_expr: xor_expr XOR and_expr",
		"and_expr: equal_expr",
		"and_expr: and_expr AND equal_expr",
		"equal_expr: compare_expr",
		"equal_expr: equal_expr EQUAL compare_expr",
		"equal_expr: equal_expr NOTEQUAL compare_expr",
		"compare_expr: shift_expr",
		"compare_expr: compare_expr GREAT shift_expr",
		"compare_expr: compare_expr SMALL shift_expr",
		"compare_expr: compare_expr GREEQU shift_expr",
		"compare_expr: compare_expr SMAEQU shift_expr",
		"shift_expr: add_expr",
		"shift_expr: shift_expr SHIFTLEFT add_expr",
		"shift_expr: shift_expr SHIFTRIGHT add_expr",
		"add_expr: mul_expr",
		"add_expr: add_expr PLUS mul_expr",
		"add_expr: add_expr MINUS mul_expr",
		"mul_expr: unary_expr",
		"mul_expr: mul_expr STAR unary_expr",
		"mul_expr: mul_expr OVER unary_expr",
		"mul_expr: mul_expr MOD unary_expr",
		"unary_expr: factor",
		"unary_expr: MINUS factor",
		"unary_expr: PLUS factor",
		"unary_expr: NOT factor",
		"unary_expr: NEG factor",
		"unary_expr: STAR factor",
		"unary_expr: AND factor",
		"unary_expr: PLUSPLUS factor",
		"unary_expr: MINUSMINUS factor",
		"unary_expr: factor PLUSPLUS",
		"unary_expr: factor MINUSMINUS",
		"unary_expr: LPAREN type_specifier RPAREN factor",
		"unary_expr: LPAREN type_specifier pointer RPAREN factor",
		"factor: ID",
		"factor: NUM",
		"factor: CHARCONST",
		"factor: STRCONST",
		"factor: LPAREN expr RPAREN",
		"stmt: if_stmt",
		"stmt: for_stmt",
		"stmt: while_stmt",
		"stmt: do_while_stmt",
		"stmt: label_stmt",
		"stmt: goto_stmt",
		"stmt: continue_stmt",
		"stmt: break_stmt",
		"stmt: return_stmt",
		"stmt: expr_stmt",
		"stmt: var_decl_stmt",
		"stmt: compound_stmt",
		"stmt: input_stmt",
		"stmt: output_stmt",
		"input_stmt: INPUT LPAREN expr RPAREN SEMICOLON",
		"output_stmt: OUTPUT LPAREN expr RPAREN SEMICOLON",
		"input_stmt: INPUT SHIFTRIGHT expr SEMICOLON",
		"output_stmt: OUTPUT SHIFTLEFT expr SEMICOLON",
		"label_stmt: ID COLON stmt",
		"label_stmt: CASE COLON stmt",
		"label_stmt: DEFAULT COLON stmt",
		"goto_stmt: GOTO ID SEMICOLON",
		"continue_stmt: CONTINUE SEMICOLON",
		"break_stmt: BREAK SEMICOLON",
		"return_stmt: RETURN SEMICOLON",
		"return_stmt: RETURN expr SEMICOLON",
		"var_decl_stmt: var_decl SEMICOLON",
		"expr_stmt: expr SEMICOLON",
		"expr_stmt: SEMICOLON",
		"compound_stmt: LBRACE stmts RBRACE",
		"stmts: stmt stmts",
		"stmts: stmt",
		"stmts:",
		"if_stmt: IF LPAREN expr RPAREN stmt",
		"if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt",
		"while_stmt: WHILE LPAREN expr RPAREN stmt",
		"do_while_stmt: DO stmt WHILE LPAREN expr RPAREN SEMICOLON",
		"for_stmt: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 1, 2, 1 },
		{ 2, 5, 2 },
		{ 2, 4, 3 },
		{ 2, 6, 4 },
		{ 2, 5, 5 },
		{ 2, 0, 6 },
		{ 3, 1, 7 },
		{ 3, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 5, 2, 12 },
		{ 5, 3, 13 },
		{ 6, 1, 14 },
		{ 7, 1, 15 },
		{ 7, 2, 16 },
		{ 8, 1, 17 },
		{ 9, 1, 18 },
		{ 9, 3, 19 },
		{ 10, 1, 20 },
		{ 10, 3, 21 },
		{ 11, 1, 22 },
		{ 11, 3, 23 },
		{ 11, 3, 24 },
		{ 11, 3, 25 },
		{ 11, 3, 26 },
		{ 11, 3, 27 },
		{ 11, 3, 28 },
		{ 11, 3, 29 },
		{ 11, 3, 30 },
		{ 11, 3, 31 },
		{ 11, 3, 32 },
		{ 11, 3, 33 },
		{ 12, 1, 34 },
		{ 12, 3, 35 },
		{ 13, 1, 36 },
		{ 13, 3, 37 },
		{ 14, 1, 38 },
		{ 14, 3, 39 },
		{ 15, 1, 40 },
		{ 15, 3, 41 },
		{ 16, 1, 42 },
		{ 16, 3, 43 },
		{ 17, 1, 44 },
		{ 17, 3, 45 },
		{ 17, 3, 46 },
		{ 18, 1, 47 },
		{ 18, 3, 48 },
		{ 18, 3, 49 },
		{ 18, 3, 50 },
		{ 18, 3, 51 },
		{ 19, 1, 52 },
		{ 19, 3, 53 },
		{ 19, 3, 54 },
		{ 20, 1, 55 },
		{ 20, 3, 56 },
		{ 20, 3, 57 },
		{ 21, 1, 58 },
		{ 21, 3, 59 },
		{ 21, 3, 60 },
		{ 21, 3, 61 },
		{ 22, 1, 62 },
		{ 22, 2, 63 },
		{ 22, 2, 64 },
		{ 22, 2, 65 },
		{ 22, 2, 66 },
		{ 22, 2, 67 },
		{ 22, 2, 68 },
		{ 22, 2, 69 },
		{ 22, 2, 70 },
		{ 22, 2, 71 },
		{ 22, 2, 72 },
		{ 22, 4, 73 },
		{ 22, 5, 74 },
		{ 23, 1, 75 },
		{ 23, 1, 76 },
		{ 23, 1, 77 },
		{ 23, 1, 78 },
		{ 23, 3, 79 },
		{ 24, 1, 80 },
		{ 24, 1, 81 },
		{ 24, 1, 82 },
		{ 24, 1, 83 },
		{ 24, 1, 84 },
		{ 24, 1, 85 },
		{ 24, 1, 86 },
		{ 24, 1, 87 },
		{ 24, 1, 88 },
		{ 24, 1, 89 },
		{ 24, 1, 90 },
		{ 24, 1, 91 },
		{ 24, 1, 92 },
		{ 24, 1, 93 },
		{ 25, 5, 94 },
		{ 26, 5, 95 },
		{ 25, 4, 96 },
		{ 26, 4, 97 },
		{ 27, 3, 98 },
		{ 27, 3, 99 },
		{ 27, 3, 100 },
		{ 28, 3, 101 },
		{ 29, 2, 102 },
		{ 30, 2, 103 },
		{ 31, 2, 104 },
		{ 31, 3, 105 },
		{ 32, 2, 106 },
		{ 33, 2, 107 },
		{ 33, 1, 108 },
		{ 34, 3, 109 },
		{ 35, 2, 110 },
		{ 35, 1, 111 },
		{ 35, 0, 112 },
		{ 36, 5, 113 },
		{ 36, 7, 114 },
		{ 37, 5, 115 },
		{ 38, 7, 116 },
		{ 39, 9, 117 },
		{ 39, 8, 118 },
		{ 39, 8, 119 },
		{ 39, 7, 120 },
		{ 39, 8, 121 },
		{ 39, 7, 122 },
		{ 39, 7, 123 },
		{ 39, 6, 124 }
	};
	yyreduction = reduction;

	yytokenaction_size = 238;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 75, YYAT_SHIFT, 2 },
		{ 57, YYAT_SHIFT, 117 },
		{ 75, YYAT_SHIFT, 3 },
		{ 23, YYAT_SHIFT, 28 },
		{ 12, YYAT_SHIFT, 20 },
		{ 56, YYAT_SHIFT, 115 },
		{ 236, YYAT_SHIFT, 245 },
		{ 212, YYAT_SHIFT, 100 },
		{ 212, YYAT_SHIFT, 43 },
		{ 212, YYAT_SHIFT, 44 },
		{ 212, YYAT_SHIFT, 45 },
		{ 75, YYAT_SHIFT, 4 },
		{ 75, YYAT_SHIFT, 32 },
		{ 113, YYAT_SHIFT, 165 },
		{ 234, YYAT_SHIFT, 242 },
		{ 75, YYAT_SHIFT, 33 },
		{ 75, YYAT_SHIFT, 34 },
		{ 75, YYAT_SHIFT, 35 },
		{ 75, YYAT_SHIFT, 36 },
		{ 75, YYAT_SHIFT, 37 },
		{ 75, YYAT_SHIFT, 38 },
		{ 75, YYAT_SHIFT, 39 },
		{ 75, YYAT_SHIFT, 40 },
		{ 75, YYAT_SHIFT, 41 },
		{ 222, YYAT_SHIFT, 235 },
		{ 222, YYAT_SHIFT, 122 },
		{ 75, YYAT_SHIFT, 5 },
		{ 235, YYAT_SHIFT, 46 },
		{ 235, YYAT_SHIFT, 47 },
		{ 113, YYAT_SHIFT, 166 },
		{ 232, YYAT_SHIFT, 240 },
		{ 75, YYAT_SHIFT, 42 },
		{ 75, YYAT_SHIFT, 43 },
		{ 75, YYAT_SHIFT, 44 },
		{ 75, YYAT_SHIFT, 45 },
		{ 223, YYAT_SHIFT, 236 },
		{ 57, YYAT_SHIFT, 118 },
		{ 75, YYAT_SHIFT, 46 },
		{ 75, YYAT_SHIFT, 47 },
		{ 56, YYAT_SHIFT, 116 },
		{ 198, YYAT_SHIFT, 134 },
		{ 198, YYAT_SHIFT, 135 },
		{ 6, YYAT_SHIFT, 1 },
		{ 6, YYAT_SHIFT, 2 },
		{ 54, YYAT_SHIFT, 2 },
		{ 6, YYAT_SHIFT, 3 },
		{ 54, YYAT_SHIFT, 3 },
		{ 235, YYAT_SHIFT, 48 },
		{ 235, YYAT_SHIFT, 49 },
		{ 235, YYAT_SHIFT, 50 },
		{ 212, YYAT_SHIFT, 104 },
		{ 221, YYAT_SHIFT, 233 },
		{ 235, YYAT_SHIFT, 51 },
		{ 235, YYAT_SHIFT, 52 },
		{ 6, YYAT_SHIFT, 4 },
		{ 54, YYAT_SHIFT, 4 },
		{ 235, YYAT_SHIFT, 53 },
		{ 75, YYAT_SHIFT, 48 },
		{ 75, YYAT_SHIFT, 49 },
		{ 75, YYAT_SHIFT, 50 },
		{ 197, YYAT_SHIFT, 134 },
		{ 197, YYAT_SHIFT, 135 },
		{ 75, YYAT_SHIFT, 51 },
		{ 75, YYAT_SHIFT, 52 },
		{ 235, YYAT_SHIFT, 54 },
		{ 235, YYAT_SHIFT, 243 },
		{ 75, YYAT_SHIFT, 53 },
		{ 23, YYAT_SHIFT, 29 },
		{ 12, YYAT_SHIFT, 21 },
		{ 6, YYAT_SHIFT, 5 },
		{ 196, YYAT_SHIFT, 134 },
		{ 196, YYAT_SHIFT, 135 },
		{ 75, YYAT_SHIFT, 26 },
		{ 220, YYAT_SHIFT, 231 },
		{ 75, YYAT_SHIFT, 54 },
		{ 193, YYAT_SHIFT, 149 },
		{ 193, YYAT_SHIFT, 150 },
		{ 193, YYAT_SHIFT, 151 },
		{ 75, YYAT_SHIFT, 55 },
		{ 5, YYAT_SHIFT, 2 },
		{ 219, YYAT_SHIFT, 230 },
		{ 5, YYAT_SHIFT, 3 },
		{ 26, YYAT_SHIFT, 2 },
		{ 217, YYAT_SHIFT, 228 },
		{ 26, YYAT_SHIFT, 3 },
		{ 216, YYAT_SHIFT, 227 },
		{ 191, YYAT_SHIFT, 143 },
		{ 191, YYAT_SHIFT, 144 },
		{ 190, YYAT_SHIFT, 143 },
		{ 190, YYAT_SHIFT, 144 },
		{ 5, YYAT_SHIFT, 4 },
		{ 75, YYAT_SHIFT, 56 },
		{ 75, YYAT_SHIFT, 57 },
		{ 26, YYAT_SHIFT, 4 },
		{ 26, YYAT_SHIFT, 32 },
		{ 195, YYAT_SHIFT, 134 },
		{ 195, YYAT_SHIFT, 135 },
		{ 26, YYAT_SHIFT, 33 },
		{ 26, YYAT_SHIFT, 34 },
		{ 26, YYAT_SHIFT, 35 },
		{ 26, YYAT_SHIFT, 36 },
		{ 26, YYAT_SHIFT, 37 },
		{ 26, YYAT_SHIFT, 38 },
		{ 26, YYAT_SHIFT, 39 },
		{ 26, YYAT_SHIFT, 40 },
		{ 26, YYAT_SHIFT, 41 },
		{ 189, YYAT_SHIFT, 138 },
		{ 189, YYAT_SHIFT, 139 },
		{ 26, YYAT_SHIFT, 5 },
		{ 191, YYAT_SHIFT, 145 },
		{ 191, YYAT_SHIFT, 146 },
		{ 190, YYAT_SHIFT, 145 },
		{ 190, YYAT_SHIFT, 146 },
		{ 26, YYAT_SHIFT, 42 },
		{ 26, YYAT_SHIFT, 43 },
		{ 26, YYAT_SHIFT, 44 },
		{ 26, YYAT_SHIFT, 45 },
		{ 214, YYAT_SHIFT, 226 },
		{ 249, YYAT_SHIFT, 32 },
		{ 26, YYAT_SHIFT, 46 },
		{ 26, YYAT_SHIFT, 47 },
		{ 249, YYAT_SHIFT, 33 },
		{ 249, YYAT_SHIFT, 34 },
		{ 249, YYAT_SHIFT, 35 },
		{ 249, YYAT_SHIFT, 36 },
		{ 249, YYAT_SHIFT, 37 },
		{ 249, YYAT_SHIFT, 38 },
		{ 249, YYAT_SHIFT, 39 },
		{ 249, YYAT_SHIFT, 40 },
		{ 249, YYAT_SHIFT, 41 },
		{ 0, YYAT_SHIFT, 1 },
		{ 0, YYAT_SHIFT, 2 },
		{ 249, YYAT_SHIFT, 5 },
		{ 0, YYAT_SHIFT, 3 },
		{ 244, YYAT_SHIFT, 249 },
		{ 71, YYAT_SHIFT, 143 },
		{ 71, YYAT_SHIFT, 144 },
		{ 249, YYAT_SHIFT, 42 },
		{ 244, YYAT_SHIFT, 122 },
		{ 26, YYAT_SHIFT, 48 },
		{ 26, YYAT_SHIFT, 49 },
		{ 26, YYAT_SHIFT, 50 },
		{ 0, YYAT_SHIFT, 4 },
		{ 208, YYAT_ERROR, 0 },
		{ 26, YYAT_SHIFT, 51 },
		{ 26, YYAT_SHIFT, 52 },
		{ 188, YYAT_SHIFT, 138 },
		{ 188, YYAT_SHIFT, 139 },
		{ 26, YYAT_SHIFT, 53 },
		{ 192, YYAT_SHIFT, 149 },
		{ 192, YYAT_SHIFT, 150 },
		{ 192, YYAT_SHIFT, 151 },
		{ 174, YYAT_SHIFT, 136 },
		{ 174, YYAT_SHIFT, 137 },
		{ 26, YYAT_SHIFT, 26 },
		{ 207, YYAT_SHIFT, 221 },
		{ 26, YYAT_SHIFT, 54 },
		{ 0, YYAT_SHIFT, 5 },
		{ 71, YYAT_SHIFT, 145 },
		{ 71, YYAT_SHIFT, 146 },
		{ 26, YYAT_SHIFT, 55 },
		{ 64, YYAT_SHIFT, 123 },
		{ 64, YYAT_SHIFT, 124 },
		{ 64, YYAT_SHIFT, 125 },
		{ 64, YYAT_SHIFT, 126 },
		{ 64, YYAT_SHIFT, 127 },
		{ 64, YYAT_SHIFT, 128 },
		{ 64, YYAT_SHIFT, 129 },
		{ 64, YYAT_SHIFT, 130 },
		{ 64, YYAT_SHIFT, 131 },
		{ 64, YYAT_SHIFT, 132 },
		{ 70, YYAT_SHIFT, 141 },
		{ 70, YYAT_SHIFT, 142 },
		{ 26, YYAT_SHIFT, 56 },
		{ 26, YYAT_SHIFT, 57 },
		{ 74, YYAT_SHIFT, 149 },
		{ 74, YYAT_SHIFT, 150 },
		{ 74, YYAT_SHIFT, 151 },
		{ 249, YYAT_SHIFT, 26 },
		{ 68, YYAT_SHIFT, 138 },
		{ 68, YYAT_SHIFT, 139 },
		{ 67, YYAT_SHIFT, 136 },
		{ 67, YYAT_SHIFT, 137 },
		{ 64, YYAT_SHIFT, 133 },
		{ 249, YYAT_SHIFT, 55 },
		{ 66, YYAT_SHIFT, 134 },
		{ 66, YYAT_SHIFT, 135 },
		{ 206, YYAT_SHIFT, 220 },
		{ 205, YYAT_SHIFT, 218 },
		{ 200, YYAT_SHIFT, 140 },
		{ 199, YYAT_SHIFT, 119 },
		{ 194, YYAT_SHIFT, 147 },
		{ 175, YYAT_SHIFT, 148 },
		{ 172, YYAT_SHIFT, 216 },
		{ 171, YYAT_SHIFT, 215 },
		{ 170, YYAT_SHIFT, 214 },
		{ 169, YYAT_SHIFT, 213 },
		{ 249, YYAT_SHIFT, 56 },
		{ 249, YYAT_SHIFT, 57 },
		{ 167, YYAT_SHIFT, 212 },
		{ 165, YYAT_SHIFT, 165 },
		{ 161, YYAT_SHIFT, 209 },
		{ 160, YYAT_SHIFT, 208 },
		{ 159, YYAT_SHIFT, 207 },
		{ 158, YYAT_SHIFT, 205 },
		{ 155, YYAT_SHIFT, 204 },
		{ 114, YYAT_SHIFT, 168 },
		{ 102, YYAT_SHIFT, 163 },
		{ 99, YYAT_SHIFT, 162 },
		{ 95, YYAT_SHIFT, 160 },
		{ 94, YYAT_SHIFT, 158 },
		{ 89, YYAT_SHIFT, 26 },
		{ 88, YYAT_SHIFT, 153 },
		{ 73, YYAT_SHIFT, 148 },
		{ 72, YYAT_SHIFT, 147 },
		{ 69, YYAT_SHIFT, 140 },
		{ 63, YYAT_SHIFT, 121 },
		{ 62, YYAT_SHIFT, 120 },
		{ 61, YYAT_SHIFT, 119 },
		{ 58, YYAT_SHIFT, 16 },
		{ 42, YYAT_SHIFT, 103 },
		{ 41, YYAT_SHIFT, 101 },
		{ 40, YYAT_SHIFT, 99 },
		{ 39, YYAT_SHIFT, 98 },
		{ 38, YYAT_SHIFT, 97 },
		{ 37, YYAT_SHIFT, 96 },
		{ 35, YYAT_SHIFT, 94 },
		{ 34, YYAT_SHIFT, 93 },
		{ 33, YYAT_SHIFT, 92 },
		{ 32, YYAT_SHIFT, 91 },
		{ 28, YYAT_SHIFT, 89 },
		{ 20, YYAT_SHIFT, 25 },
		{ 18, YYAT_SHIFT, 24 },
		{ 15, YYAT_SHIFT, 23 },
		{ 11, YYAT_SHIFT, 19 },
		{ 8, YYAT_SHIFT, 15 },
		{ 7, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 12 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -127, 1, YYAT_REDUCE, 7 },
		{ -95, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ -215, 1, YYAT_REDUCE, 1 },
		{ 236, 1, YYAT_ERROR, 0 },
		{ -22, 1, YYAT_DEFAULT, 58 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ -265, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 58 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -99, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -105, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 89 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ -266, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 58 },
		{ 0, 0, YYAT_DEFAULT, 89 },
		{ -176, 1, YYAT_REDUCE, 113 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -103, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 89 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -103, 1, YYAT_ERROR, 0 },
		{ -101, 1, YYAT_ERROR, 0 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ -106, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ -107, 1, YYAT_ERROR, 0 },
		{ -112, 1, YYAT_ERROR, 0 },
		{ -113, 1, YYAT_ERROR, 0 },
		{ -67, 1, YYAT_ERROR, 0 },
		{ -115, 1, YYAT_DEFAULT, 208 },
		{ -109, 1, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ -214, 1, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ -293, 1, YYAT_ERROR, 0 },
		{ -296, 1, YYAT_ERROR, 0 },
		{ -70, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ -106, 1, YYAT_REDUCE, 41 },
		{ -87, 1, YYAT_REDUCE, 23 },
		{ -120, 1, YYAT_DEFAULT, 222 },
		{ -144, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ -112, 1, YYAT_REDUCE, 48 },
		{ -120, 1, YYAT_REDUCE, 43 },
		{ -141, 1, YYAT_REDUCE, 53 },
		{ -110, 1, YYAT_REDUCE, 37 },
		{ -124, 1, YYAT_REDUCE, 63 },
		{ -164, 1, YYAT_REDUCE, 45 },
		{ -112, 1, YYAT_REDUCE, 39 },
		{ -90, 1, YYAT_REDUCE, 35 },
		{ -142, 1, YYAT_REDUCE, 56 },
		{ -258, 1, YYAT_REDUCE, 112 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ -119, 1, YYAT_ERROR, 0 },
		{ -119, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ -126, 1, YYAT_DEFAULT, 208 },
		{ -68, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ -128, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ -129, 1, YYAT_DEFAULT, 222 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ -304, 1, YYAT_ERROR, 0 },
		{ -127, 1, YYAT_DEFAULT, 244 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -128, 1, YYAT_DEFAULT, 244 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ -132, 1, YYAT_DEFAULT, 208 },
		{ -133, 1, YYAT_DEFAULT, 222 },
		{ -130, 1, YYAT_ERROR, 0 },
		{ -132, 1, YYAT_DEFAULT, 244 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ -117, 1, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_DEFAULT, 212 },
		{ -134, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ -140, 1, YYAT_DEFAULT, 222 },
		{ -138, 1, YYAT_DEFAULT, 244 },
		{ -142, 1, YYAT_DEFAULT, 222 },
		{ -140, 1, YYAT_DEFAULT, 244 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ -149, 1, YYAT_REDUCE, 44 },
		{ -111, 1, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -174, 1, YYAT_REDUCE, 54 },
		{ -214, 1, YYAT_REDUCE, 55 },
		{ -211, 1, YYAT_REDUCE, 46 },
		{ -213, 1, YYAT_REDUCE, 47 },
		{ -168, 1, YYAT_REDUCE, 57 },
		{ -242, 1, YYAT_REDUCE, 58 },
		{ -135, 1, YYAT_REDUCE, 40 },
		{ -202, 1, YYAT_REDUCE, 51 },
		{ -227, 1, YYAT_REDUCE, 52 },
		{ -237, 1, YYAT_REDUCE, 49 },
		{ -257, 1, YYAT_REDUCE, 50 },
		{ -134, 1, YYAT_REDUCE, 42 },
		{ -136, 1, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ -145, 1, YYAT_DEFAULT, 235 },
		{ -149, 1, YYAT_DEFAULT, 222 },
		{ -181, 1, YYAT_DEFAULT, 208 },
		{ -190, 1, YYAT_DEFAULT, 235 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ -282, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ -219, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ -251, 1, YYAT_ERROR, 0 },
		{ -188, 1, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ -253, 1, YYAT_DEFAULT, 244 },
		{ -260, 1, YYAT_DEFAULT, 235 },
		{ -282, 1, YYAT_DEFAULT, 235 },
		{ -312, 1, YYAT_ERROR, 0 },
		{ -298, 1, YYAT_DEFAULT, 244 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ -303, 1, YYAT_DEFAULT, 244 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ -319, 1, YYAT_DEFAULT, 244 },
		{ -268, 1, YYAT_DEFAULT, 212 },
		{ -330, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_REDUCE, 123 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_REDUCE, 121 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ -199, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 0, 0, YYAT_REDUCE, 120 },
		{ 0, 0, YYAT_REDUCE, 119 },
		{ -152, 1, YYAT_DEFAULT, 54 },
		{ 0, 0, YYAT_REDUCE, 118 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 129;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 249, 58 },
		{ 249, 11 },
		{ 235, 244 },
		{ 235, 65 },
		{ 235, 62 },
		{ 235, 73 },
		{ 249, 63 },
		{ 6, 14 },
		{ 6, 10 },
		{ 6, 6 },
		{ 6, 8 },
		{ 6, 11 },
		{ 151, 203 },
		{ 151, 70 },
		{ 235, 64 },
		{ 148, 200 },
		{ 148, 72 },
		{ 148, 61 },
		{ 148, 67 },
		{ 148, 71 },
		{ 249, 250 },
		{ 249, 79 },
		{ 249, 84 },
		{ 249, 80 },
		{ 249, 81 },
		{ 249, 82 },
		{ 249, 77 },
		{ 249, 78 },
		{ 249, 60 },
		{ 249, 83 },
		{ 249, 59 },
		{ 75, 75 },
		{ 249, 85 },
		{ 249, 87 },
		{ 249, 76 },
		{ 249, 86 },
		{ 147, -1 },
		{ 147, 199 },
		{ 6, 9 },
		{ 146, 198 },
		{ 146, 68 },
		{ 146, 74 },
		{ 75, 152 },
		{ 58, 18 },
		{ 140, -1 },
		{ 140, 194 },
		{ 58, 17 },
		{ 139, 193 },
		{ 139, 173 },
		{ 137, 191 },
		{ 137, 66 },
		{ 135, -1 },
		{ 135, 189 },
		{ 133, -1 },
		{ 133, 187 },
		{ 120, 175 },
		{ 120, 69 },
		{ 119, -1 },
		{ 119, 174 },
		{ 243, 248 },
		{ 242, 247 },
		{ 240, 246 },
		{ 233, 241 },
		{ 231, 239 },
		{ 230, 238 },
		{ 228, 237 },
		{ 221, 234 },
		{ 220, 232 },
		{ 218, 229 },
		{ 212, 225 },
		{ 209, 224 },
		{ 208, 223 },
		{ 207, 222 },
		{ 205, 219 },
		{ 204, 217 },
		{ 166, 211 },
		{ 165, 210 },
		{ 158, 206 },
		{ 150, 202 },
		{ 149, 201 },
		{ 145, 197 },
		{ 144, 196 },
		{ 143, 195 },
		{ 138, 192 },
		{ 136, 190 },
		{ 134, 188 },
		{ 132, 186 },
		{ 131, 185 },
		{ 130, 184 },
		{ 129, 183 },
		{ 128, 182 },
		{ 127, 181 },
		{ 126, 180 },
		{ 125, 179 },
		{ 124, 178 },
		{ 123, 177 },
		{ 122, 176 },
		{ 118, 172 },
		{ 117, 171 },
		{ 116, 170 },
		{ 115, 169 },
		{ 113, 167 },
		{ 104, 114 },
		{ 103, 164 },
		{ 96, 161 },
		{ 94, 159 },
		{ 93, 157 },
		{ 92, 156 },
		{ 91, 155 },
		{ 89, 154 },
		{ 54, 113 },
		{ 53, 112 },
		{ 52, 111 },
		{ 51, 110 },
		{ 50, 109 },
		{ 49, 108 },
		{ 48, 107 },
		{ 47, 106 },
		{ 46, 105 },
		{ 41, 102 },
		{ 36, 95 },
		{ 29, 90 },
		{ 26, 88 },
		{ 25, 31 },
		{ 24, 30 },
		{ 21, 27 },
		{ 13, 22 },
		{ 5, 13 },
		{ 0, 7 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 127, 6 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 123, -1 },
		{ 6, -1 },
		{ 0, -1 },
		{ 0, 58 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 117, 58 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 91, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 115, 58 },
		{ 89, -1 },
		{ 87, 75 },
		{ 0, -1 },
		{ 0, -1 },
		{ 87, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 96, 249 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 109, 235 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 95, -1 },
		{ 94, -1 },
		{ 93, -1 },
		{ 92, -1 },
		{ 91, -1 },
		{ 90, -1 },
		{ 89, -1 },
		{ 88, -1 },
		{ 106, 104 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, 249 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, -1 },
		{ 0, -1 },
		{ 98, 235 },
		{ 83, 249 },
		{ 82, 249 },
		{ 95, 235 },
		{ 0, -1 },
		{ 94, 235 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 79, 249 },
		{ 92, 235 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 94, -1 },
		{ 0, -1 },
		{ 90, 235 },
		{ 89, 235 },
		{ 88, 235 },
		{ 87, 235 },
		{ 41, 147 },
		{ 42, 148 },
		{ 0, -1 },
		{ 85, 133 },
		{ 84, 133 },
		{ 83, 133 },
		{ 82, 133 },
		{ 81, 133 },
		{ 80, 133 },
		{ 79, 133 },
		{ 78, 133 },
		{ 77, 133 },
		{ 76, 133 },
		{ 75, 133 },
		{ 43, 235 },
		{ 65, 135 },
		{ 32, 146 },
		{ 66, 137 },
		{ 31, 146 },
		{ 62, 139 },
		{ 26, 151 },
		{ 30, 148 },
		{ 0, -1 },
		{ 0, -1 },
		{ 63, 146 },
		{ 62, 146 },
		{ 61, 146 },
		{ 20, 139 },
		{ 21, 140 },
		{ 1, 137 },
		{ 57, 151 },
		{ 56, 151 },
		{ -10, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 67, 235 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 69, -1 },
		{ 52, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 249 },
		{ 63, 235 },
		{ 0, -1 },
		{ 62, 235 },
		{ 61, 235 },
		{ 46, 249 },
		{ 0, -1 },
		{ 0, -1 },
		{ 46, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 44, 249 },
		{ 0, -1 },
		{ 57, 235 },
		{ 56, 235 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 41, 249 },
		{ 0, -1 },
		{ 40, 249 },
		{ 39, 249 },
		{ 0, -1 },
		{ 38, 249 },
		{ 0, -1 },
		{ -8, 120 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 249 },
		{ 0, -1 },
		{ 36, 249 },
		{ 35, 249 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 235 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 1697 ".\\myparser.y"


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


