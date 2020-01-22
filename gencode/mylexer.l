%{
//this code will be added into the header of generated .cpp file
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <vector>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "myparser.h"
#include "TreeNode.h"
#include "symbol_table.h"
using namespace std;

extern int nodecount;
char **currtext;
int num_lines = 1;
extern vector<Symbol*> table; //symbol table

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
extern int typeCheck(TreeNode *t);
extern void typeError(TreeNode *t, char *errmsg);

extern Symbol *newEntry(char *id);
extern Symbol *lookup_table(char *id);
extern Symbol *lookup_table(int pos);
extern Symbol *insert_table(char *id);
extern void printSymTable();

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
	currtext=&yytext;
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
/* basic characters */
delim			[ \t]
ws				{delim}+
newline			[\n]|\r\n
digit			[0-9]

/* preprocess */
preprocess		#((include|define|ifdef|ifndef|pragma|elif|endif|error|undef|line).*)?

/* comments */
SLCOMMENT		\/\/.*
DLCOMMENT		\/\*(([^\*]|\*[^\/]+)*|\*)\*\/

/* program entry */
MAIN			main

/* Input and Output */
INPUT			cin
OUTPUT			cout
ENDL			endl

/* reserved words */
CHAR			char
SHORT			short
INT				int
LONG			long
FLOAT			float
DOUBLE			double
UNSIGNED		unsigned
SIGNED			signed
STRUCT			struct
UNION			union
ENUM			enum
VOID			void
IF				if
ELSE			else
SWITCH			switch
CASE			case
DEFAULT			default
FOR				for
DO				do
WHILE			while
BREAK			break
CONTINUE		continue
GOTO			goto
RETURN			return
AUTO			auto
EXTERN			extern
REGISTER		register
STATIC			static
CONST			const
SIZEOF			sizeof
TYPEDEF			typedef
VOLATILE		volatile

ID				[a-zA-Z_][a-zA-Z0-9_]*
/* can support 12.34 */
NUM				{digit}+(\.{digit}+)?((E|e)(\+|\-)?{digit}+)?(F|f)?
CHARCONST		'(((\\)?[^\\'\n]+)|(\\['\\]))+'
STRCONST		\"([^\"\n]|(\\\"))*\"

/* operators or other symbols */
POINTMEM		\.
ARROWMEM		\-\>
PLUSPLUS  		\+\+
MINUSMINUS 		\-\-
SHIFTLEFT  		\<\<
SHIFTRIGHT 		\>\>
GREEQU			\>=
SMAEQU			\<=
EQUAL 			==
NOTEQUAL  		!=
LOGAND  		&&
LOGOR   		\|\|
PLUSASSIGN		\+=
MINUSASSIGN		\-=
MULASSIGN		\*=
OVERASSIGN		\/=
MODASSIGN		\%=
LSHIFTASSIGN	\<\<=
RSHIFTASSIGN	\>\>=
ANDASSIGN		&=
XORASSIGN		\^=
ORASSIGN		\|=
NOT     		!
NEG   			~
STAR 			\*
OVER  			\/
MOD   			\%
PLUS  			\+
MINUS 			\-
GREAT			\>
SMALL			\<
AND   			&
OR    			\|
XOR   			\^
ASSIGN			=
QUES			\?
COLON			:
LBRACE			\{
RBRACE  		\}
LPAREN  		\(
RPAREN  		\)
LSQURE			\[
RSQURE			\]
SEMICOLON		;
COMMA			,

other			.
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	//this code will be added into yyaction function
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{preprocess}	{ /* do nothing */ }
{SLCOMMENT}		{ /* do nothing */ }
{DLCOMMENT}		{
					string s(yytext);
					int len = s.length();
					for(int i = 0;i < len;i++)
					{
						if(s[i] == '\n')
							num_lines++;
					}
				}

{MAIN}			{ return MAIN; }

{INPUT}			{ return INPUT; }
{OUTPUT}		{ return OUTPUT; }
{ENDL}			{ return ENDL; }

{CHAR}			{ TreeNode *t=newTypeNode(Char); yylval = t; return CHAR; }
{SHORT}			{ TreeNode *t=newTypeNode(Short); yylval = t; return SHORT; }
{INT}			{ TreeNode *t=newTypeNode(Integer); yylval = t; return INT; }
{LONG}			{ return LONG; }
{FLOAT}			{ TreeNode *t=newTypeNode(Float); yylval = t; return FLOAT; }
{DOUBLE}		{ TreeNode *t=newTypeNode(Double); yylval = t; return DOUBLE; }
{UNSIGNED}		{ return UNSIGNED; }
{SIGNED}		{ return SIGNED; }
{STRUCT}		{ return STRUCT; }
{UNION}			{ return UNION; }
{ENUM}			{ return ENUM; }
{VOID}			{ TreeNode *t=newTypeNode(Void); yylval = t; return VOID; }
{IF}			{ return IF; }
{ELSE}			{ return ELSE; }
{SWITCH}		{ return SWITCH; }
{CASE}			{ TreeNode *t=newCaseNode(); yylval = t; return CASE; }
{DEFAULT}		{ TreeNode *t=newDefaultNode(); yylval = t; return DEFAULT; }
{FOR}			{ return FOR; }
{DO}			{ return DO; }
{WHILE}			{ return WHILE; }
{BREAK}			{ return BREAK; }
{CONTINUE}		{ return CONTINUE; }
{GOTO}			{ return GOTO; }
{RETURN}		{ return RETURN; }
{AUTO}			{ return AUTO; }
{EXTERN}		{ return EXTERN; }
{REGISTER}		{ return REGISTER; }
{STATIC}		{ TreeNode *t=newStaticNode(); yylval = t; return STATIC; }
{CONST}			{ return CONST; }
{SIZEOF}		{ return SIZEOF; }
{TYPEDEF}		{ return TYPEDEF; }
{VOLATILE}		{ return VOLATILE; }

{ID}			{
					TreeNode *t = newIDNode();
					char *idname=new char[strlen(yytext)+1];//copy the yytext（由于yytext指向的地址值固定）
					strcpy(idname, yytext);
					t->attr.idname = idname;
					insert_table(idname);
					yylval = t;
					return ID;
				}
{NUM}			{
					string v(yytext);
					TreeNode *t = newConstNode();
					if(v.find(".") != string::npos || v.find("E") != string::npos|| v.find("e") != string::npos)
					{
						if(v.find("f") != string::npos || v.find("F") != string::npos)
						{
							t->type = Float;
							t->attr.floatval = atof(yytext);
						}
						else
						{
							t->type = Double;
							t->attr.douval = atof(yytext);
						}
					}
					else
					{
						t->type = Integer;
						t->attr.intval = atoi(yytext);
					}
					yylval = t;
					return NUM;
				}
{CHARCONST}		{
					string v(yytext);
					v = v.substr(1, v.length() - 2);//substr between two quotations
					TreeNode *t = newConstNode();
					int val = 0, len = v.length(), temp;
					char ch[2];
					for(int i=0;i<len;)
					{
						if(v[i] == '\\')
						{
							if(v[i + 1] == 'a')
							{
								temp = 7;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == 'b')
							{
								temp = 8;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == 'f')
							{
								temp = 12;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == 'n')
							{
								temp = 10;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == 'r')
							{
								temp = 13;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == 't')
							{
								temp = 9;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == 'v')
							{
								temp = 11;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == '\\')
							{
								temp = 92;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == '\'')
							{
								temp = 39;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == '\"')
							{
								temp = 34;
								val <<= 8;
								val |= temp;
								i += 2;
							}
							else if(v[i + 1] == 'x')
							{
								int j = 2;
								string t;
								while(isdigit(v[i + j]) && i + j < len)
								{
									sprintf(ch, "%c", v[i + j]);
									t.append(ch);
									j++;
								}
								sscanf(t.c_str(), "%x", &temp);
								val <<= 8;
								val |= temp;
								i += j;
							}
							else if(isdigit(v[i + 1]))
							{
								int j = 1;
								string t;
								while(isdigit(v[i + j]) && i + j < len)
								{
									sprintf(ch, "%c", v[i + j]);
									t.append(ch);
									j++;
								}
								sscanf(t.c_str(), "%o", &temp);
								val <<= 8;
								val |= temp;
								i += j;
							}
							else
							{
								temp = (int)v[i + 1];
								val <<= 8;
								val |= temp;
								i += 2;
							}
						}
						else
						{
							temp = (int)v[i];
							val <<= 8;
							val |= temp;
							i++;
						}
					}
					t->type = Char;
					t->attr.charval = (char)val;
					yylval = t;
					return CHARCONST;
				}
{STRCONST}		{
					string v(yytext);
					v = v.substr(1, v.length() - 2);//substr between two quotations
					TreeNode *t = newConstNode();
					string val;
					int len = v.length(), temp;
					char ch[2];
					for(int i=0;i<len;)
					{
						if(v[i] == '\\')
						{
							if(v[i + 1] == 'a')
							{
								temp = 7;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == 'b')
							{
								temp = 8;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == 'f')
							{
								temp = 12;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == 'n')
							{
								temp = 10;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == 'r')
							{
								temp = 13;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == 't')
							{
								temp = 9;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == 'v')
							{
								temp = 11;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == '\\')
							{
								temp = 92;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == '\'')
							{
								temp = 39;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == '\"')
							{
								temp = 34;
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
							else if(v[i + 1] == 'x')
							{
								int j = 2;
								string t;
								while(isdigit(v[i + j]) && i + j < len)
								{
									sprintf(ch, "%c", v[i + j]);
									t.append(ch);
									j++;
								}
								sscanf(t.c_str(), "%x", &temp);
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += j;
							}
							else if(isdigit(v[i + 1]))
							{
								int j = 1;
								string t;
								while(isdigit(v[i + j]) && i + j < len)
								{
									sprintf(ch, "%c", v[i + j]);
									t.append(ch);
									j++;
								}
								sscanf(t.c_str(), "%o", &temp);
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += j;
							}
							else
							{
								temp = (int)v[i + 1];
								sprintf(ch, "%c", (char)temp);
								val.append(ch);
								i += 2;
							}
						}
						else
						{
							sprintf(ch, "%c", v[i]);
							val.append(ch);
							i++;
						}
					}
					t->type = Str;
					char *copy = new char[strlen(val.c_str()) + 1];
					strcpy(copy, val.c_str());
					t->attr.strval = copy;
					yylval = t;
					return STRCONST;
				}

{POINTMEM}		{ return POINTMEM; }
{ARROWMEM}		{ return ARROWMEM; }
{PLUSPLUS}  	{ return PLUSPLUS; }
{MINUSMINUS} 	{ return MINUSMINUS; }
{SHIFTLEFT}  	{ return SHIFTLEFT; }
{SHIFTRIGHT} 	{ return SHIFTRIGHT; }
{GREEQU}		{ return GREEQU; }
{SMAEQU}		{ return SMAEQU; }
{EQUAL} 		{ return EQUAL; }
{NOTEQUAL}  	{ return NOTEQUAL; }
{LOGAND}  		{ return LOGAND; }
{LOGOR}   		{ return LOGOR; }
{PLUSASSIGN}	{ return PLUSASSIGN; }
{MINUSASSIGN}	{ return MINUSASSIGN; }
{MULASSIGN}	{ return MULASSIGN; }
{OVERASSIGN}	{ return OVERASSIGN; }
{MODASSIGN}		{ return MODASSIGN; }
{LSHIFTASSIGN}	{ return LSHIFTASSIGN; }
{RSHIFTASSIGN}	{ return RSHIFTASSIGN; }
{ANDASSIGN}		{ return ANDASSIGN; }
{XORASSIGN}		{ return XORASSIGN; }
{ORASSIGN}		{ return ORASSIGN; }
{NOT}     		{ return NOT; }
{NEG}   		{ return NEG; }
{STAR} 			{ return STAR; }
{OVER}  		{ return OVER; }
{MOD}   		{ return MOD; }
{PLUS}  		{ return PLUS; }
{MINUS} 		{ return MINUS; }
{GREAT}			{ return GREAT; }
{SMALL}			{ return SMALL; }
{AND}   		{ return AND; }
{OR}    		{ return OR; }
{XOR}   		{ return XOR; }
{ASSIGN}		{ return ASSIGN; }
{QUES}			{ return QUES; }
{COLON}			{ return COLON; }
{LBRACE}		{ return LBRACE; }
{RBRACE}  		{ return RBRACE; }
{LPAREN}  		{ return LPAREN; }
{RPAREN}  		{ return RPAREN; }
{LSQURE}		{ return LSQURE; }
{RSQURE}		{ return RSQURE; }
{SEMICOLON}		{ return SEMICOLON; }
{COMMA}			{ return COMMA; }


{newline}		{
					num_lines++;
					//cout << "num_lines: " << num_lines << endl;
				}
{ws}			{ /* do nothing */ }
{other}			{
					cout << num_lines << "Lex error!" << endl;
					return ERROR;
				}
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

