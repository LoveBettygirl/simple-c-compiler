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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/19/19
* Time: 10:43:03
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

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


#line 87 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 62 ".\\mylexer.l"

	// place any extra initialisation code here
	currtext=&yytext;

#line 112 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 68 ".\\mylexer.l"

	// place any extra cleanup code here

#line 124 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 187 ".\\mylexer.l"

	// extract yylval for use later on in actions
	//this code will be added into yyaction function
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 196 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 194 ".\\mylexer.l"
 /* do nothing */ 
#line 203 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 195 ".\\mylexer.l"
 /* do nothing */ 
#line 210 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 196 ".\\mylexer.l"

					string s(yytext);
					int len = s.length();
					for(int i = 0;i < len;i++)
					{
						if(s[i] == '\n')
							num_lines++;
					}
				
#line 225 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 206 ".\\mylexer.l"
 return MAIN; 
#line 232 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 208 ".\\mylexer.l"
 return INPUT; 
#line 239 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 209 ".\\mylexer.l"
 return OUTPUT; 
#line 246 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 210 ".\\mylexer.l"
 return ENDL; 
#line 253 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 212 ".\\mylexer.l"
 TreeNode *t=newTypeNode(Char); yylval = t; return CHAR; 
#line 260 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 213 ".\\mylexer.l"
 TreeNode *t=newTypeNode(Short); yylval = t; return SHORT; 
#line 267 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 214 ".\\mylexer.l"
 TreeNode *t=newTypeNode(Integer); yylval = t; return INT; 
#line 274 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 215 ".\\mylexer.l"
 return LONG; 
#line 281 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 216 ".\\mylexer.l"
 TreeNode *t=newTypeNode(Float); yylval = t; return FLOAT; 
#line 288 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 217 ".\\mylexer.l"
 TreeNode *t=newTypeNode(Double); yylval = t; return DOUBLE; 
#line 295 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 218 ".\\mylexer.l"
 return UNSIGNED; 
#line 302 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 219 ".\\mylexer.l"
 return SIGNED; 
#line 309 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 220 ".\\mylexer.l"
 return STRUCT; 
#line 316 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 221 ".\\mylexer.l"
 return UNION; 
#line 323 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 222 ".\\mylexer.l"
 return ENUM; 
#line 330 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 223 ".\\mylexer.l"
 TreeNode *t=newTypeNode(Void); yylval = t; return VOID; 
#line 337 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 224 ".\\mylexer.l"
 return IF; 
#line 344 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 225 ".\\mylexer.l"
 return ELSE; 
#line 351 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 226 ".\\mylexer.l"
 return SWITCH; 
#line 358 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 227 ".\\mylexer.l"
 TreeNode *t=newCaseNode(); yylval = t; return CASE; 
#line 365 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 228 ".\\mylexer.l"
 TreeNode *t=newDefaultNode(); yylval = t; return DEFAULT; 
#line 372 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 229 ".\\mylexer.l"
 return FOR; 
#line 379 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 230 ".\\mylexer.l"
 return DO; 
#line 386 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 231 ".\\mylexer.l"
 return WHILE; 
#line 393 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 232 ".\\mylexer.l"
 return BREAK; 
#line 400 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 233 ".\\mylexer.l"
 return CONTINUE; 
#line 407 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 234 ".\\mylexer.l"
 return GOTO; 
#line 414 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 235 ".\\mylexer.l"
 return RETURN; 
#line 421 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 236 ".\\mylexer.l"
 return AUTO; 
#line 428 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 237 ".\\mylexer.l"
 return EXTERN; 
#line 435 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 238 ".\\mylexer.l"
 return REGISTER; 
#line 442 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 239 ".\\mylexer.l"
 TreeNode *t=newStaticNode(); yylval = t; return STATIC; 
#line 449 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 240 ".\\mylexer.l"
 return CONST; 
#line 456 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 241 ".\\mylexer.l"
 return SIZEOF; 
#line 463 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 242 ".\\mylexer.l"
 return TYPEDEF; 
#line 470 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 243 ".\\mylexer.l"
 return VOLATILE; 
#line 477 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 245 ".\\mylexer.l"

					TreeNode *t = newIDNode();
					char *idname=new char[strlen(yytext)+1];//copy the yytext（由于yytext指向的地址值固定）
					strcpy(idname, yytext);
					t->attr.idname = idname;
					insert_table(idname);
					yylval = t;
					return ID;
				
#line 492 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 254 ".\\mylexer.l"

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
				
#line 522 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 278 ".\\mylexer.l"

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
				
#line 659 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 409 ".\\mylexer.l"

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
				
#line 798 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 543 ".\\mylexer.l"
 return POINTMEM; 
#line 805 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 544 ".\\mylexer.l"
 return ARROWMEM; 
#line 812 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 545 ".\\mylexer.l"
 return PLUSPLUS; 
#line 819 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 546 ".\\mylexer.l"
 return MINUSMINUS; 
#line 826 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 547 ".\\mylexer.l"
 return SHIFTLEFT; 
#line 833 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 548 ".\\mylexer.l"
 return SHIFTRIGHT; 
#line 840 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 549 ".\\mylexer.l"
 return GREEQU; 
#line 847 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 550 ".\\mylexer.l"
 return SMAEQU; 
#line 854 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 551 ".\\mylexer.l"
 return EQUAL; 
#line 861 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 552 ".\\mylexer.l"
 return NOTEQUAL; 
#line 868 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 553 ".\\mylexer.l"
 return LOGAND; 
#line 875 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 554 ".\\mylexer.l"
 return LOGOR; 
#line 882 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 555 ".\\mylexer.l"
 return PLUSASSIGN; 
#line 889 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 556 ".\\mylexer.l"
 return MINUSASSIGN; 
#line 896 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 557 ".\\mylexer.l"
 return MULASSIGN; 
#line 903 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 558 ".\\mylexer.l"
 return OVERASSIGN; 
#line 910 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 559 ".\\mylexer.l"
 return MODASSIGN; 
#line 917 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 560 ".\\mylexer.l"
 return LSHIFTASSIGN; 
#line 924 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 561 ".\\mylexer.l"
 return RSHIFTASSIGN; 
#line 931 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 562 ".\\mylexer.l"
 return ANDASSIGN; 
#line 938 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 563 ".\\mylexer.l"
 return XORASSIGN; 
#line 945 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 564 ".\\mylexer.l"
 return ORASSIGN; 
#line 952 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 565 ".\\mylexer.l"
 return NOT; 
#line 959 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 566 ".\\mylexer.l"
 return NEG; 
#line 966 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 567 ".\\mylexer.l"
 return STAR; 
#line 973 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 568 ".\\mylexer.l"
 return OVER; 
#line 980 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 569 ".\\mylexer.l"
 return MOD; 
#line 987 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 570 ".\\mylexer.l"
 return PLUS; 
#line 994 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 571 ".\\mylexer.l"
 return MINUS; 
#line 1001 "mylexer.cpp"
		}
		break;
	case 73:
		{
#line 572 ".\\mylexer.l"
 return GREAT; 
#line 1008 "mylexer.cpp"
		}
		break;
	case 74:
		{
#line 573 ".\\mylexer.l"
 return SMALL; 
#line 1015 "mylexer.cpp"
		}
		break;
	case 75:
		{
#line 574 ".\\mylexer.l"
 return AND; 
#line 1022 "mylexer.cpp"
		}
		break;
	case 76:
		{
#line 575 ".\\mylexer.l"
 return OR; 
#line 1029 "mylexer.cpp"
		}
		break;
	case 77:
		{
#line 576 ".\\mylexer.l"
 return XOR; 
#line 1036 "mylexer.cpp"
		}
		break;
	case 78:
		{
#line 577 ".\\mylexer.l"
 return ASSIGN; 
#line 1043 "mylexer.cpp"
		}
		break;
	case 79:
		{
#line 578 ".\\mylexer.l"
 return QUES; 
#line 1050 "mylexer.cpp"
		}
		break;
	case 80:
		{
#line 579 ".\\mylexer.l"
 return COLON; 
#line 1057 "mylexer.cpp"
		}
		break;
	case 81:
		{
#line 580 ".\\mylexer.l"
 return LBRACE; 
#line 1064 "mylexer.cpp"
		}
		break;
	case 82:
		{
#line 581 ".\\mylexer.l"
 return RBRACE; 
#line 1071 "mylexer.cpp"
		}
		break;
	case 83:
		{
#line 582 ".\\mylexer.l"
 return LPAREN; 
#line 1078 "mylexer.cpp"
		}
		break;
	case 84:
		{
#line 583 ".\\mylexer.l"
 return RPAREN; 
#line 1085 "mylexer.cpp"
		}
		break;
	case 85:
		{
#line 584 ".\\mylexer.l"
 return LSQURE; 
#line 1092 "mylexer.cpp"
		}
		break;
	case 86:
		{
#line 585 ".\\mylexer.l"
 return RSQURE; 
#line 1099 "mylexer.cpp"
		}
		break;
	case 87:
		{
#line 586 ".\\mylexer.l"
 return SEMICOLON; 
#line 1106 "mylexer.cpp"
		}
		break;
	case 88:
		{
#line 587 ".\\mylexer.l"
 return COMMA; 
#line 1113 "mylexer.cpp"
		}
		break;
	case 89:
		{
#line 590 ".\\mylexer.l"

					num_lines++;
					//cout << "num_lines: " << num_lines << endl;
				
#line 1123 "mylexer.cpp"
		}
		break;
	case 90:
		{
#line 594 ".\\mylexer.l"
 /* do nothing */ 
#line 1130 "mylexer.cpp"
		}
		break;
	case 91:
		{
#line 595 ".\\mylexer.l"

					cout << num_lines << "Lex error!" << endl;
					return ERROR;
				
#line 1140 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 414;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 124, 65 },
		{ 154, 105 },
		{ 6, 1 },
		{ 160, 109 },
		{ 104, 43 },
		{ 105, 43 },
		{ 73, 20 },
		{ 91, 35 },
		{ 137, 90 },
		{ 173, 173 },
		{ 128, 77 },
		{ 74, 20 },
		{ 128, 77 },
		{ 161, 109 },
		{ 210, 173 },
		{ 138, 90 },
		{ 106, 43 },
		{ 92, 35 },
		{ 112, 49 },
		{ 107, 43 },
		{ 155, 105 },
		{ 4, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 75, 20 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 66, 65 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 113, 49 },
		{ 30, 1 },
		{ 31, 1 },
		{ 28, 1 },
		{ 0, 128 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 28, 1 },
		{ 39, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 40, 1 },
		{ 41, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 42, 1 },
		{ 43, 1 },
		{ 44, 1 },
		{ 45, 1 },
		{ 46, 1 },
		{ 47, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 28, 1 },
		{ 48, 1 },
		{ 49, 1 },
		{ 50, 1 },
		{ 51, 1 },
		{ 0, 114 },
		{ 0, 128 },
		{ 4, 4 },
		{ 63, 11 },
		{ 68, 16 },
		{ 151, 103 },
		{ 142, 94 },
		{ 93, 36 },
		{ 99, 39 },
		{ 94, 36 },
		{ 156, 106 },
		{ 85, 32 },
		{ 0, 76 },
		{ 0, 76 },
		{ 70, 18 },
		{ 116, 57 },
		{ 100, 39 },
		{ 117, 57 },
		{ 152, 103 },
		{ 95, 36 },
		{ 119, 58 },
		{ 118, 57 },
		{ 69, 16 },
		{ 143, 94 },
		{ 54, 114 },
		{ 4, 4 },
		{ 64, 11 },
		{ 157, 106 },
		{ 120, 58 },
		{ 96, 37 },
		{ 71, 18 },
		{ 72, 18 },
		{ 97, 37 },
		{ 86, 33 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 0, 76 },
		{ 0, 76 },
		{ 162, 110 },
		{ 179, 137 },
		{ 180, 137 },
		{ 163, 110 },
		{ 121, 59 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 82, 26 },
		{ 83, 26 },
		{ 79, 24 },
		{ 80, 24 },
		{ 28, 256 },
		{ 55, 114 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 28, 256 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 129, 129 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 127, 127 },
		{ 56, 9 },
		{ 57, 9 },
		{ 78, 129 },
		{ 122, 60 },
		{ 123, 61 },
		{ 58, 9 },
		{ 87, 34 },
		{ 62, 10 },
		{ 59, 9 },
		{ 0, 66 },
		{ 126, 73 },
		{ 77, 127 },
		{ 60, 9 },
		{ 88, 34 },
		{ 89, 34 },
		{ 0, 74 },
		{ 52, 7 },
		{ 61, 9 },
		{ 0, 12 },
		{ 76, 21 },
		{ 90, 34 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 21, 21 },
		{ 130, 79 },
		{ 131, 83 },
		{ 132, 85 },
		{ 78, 129 },
		{ 133, 86 },
		{ 134, 87 },
		{ 135, 88 },
		{ 136, 89 },
		{ 67, 15 },
		{ 139, 91 },
		{ 140, 92 },
		{ 141, 93 },
		{ 77, 127 },
		{ 98, 38 },
		{ 144, 95 },
		{ 145, 96 },
		{ 146, 97 },
		{ 147, 98 },
		{ 148, 100 },
		{ 149, 101 },
		{ 150, 102 },
		{ 81, 25 },
		{ 153, 104 },
		{ 101, 40 },
		{ 102, 41 },
		{ 158, 107 },
		{ 159, 108 },
		{ 103, 42 },
		{ 5, 6 },
		{ 164, 111 },
		{ 108, 44 },
		{ 59, 115 },
		{ 165, 116 },
		{ 116, 117 },
		{ 166, 118 },
		{ 123, 119 },
		{ 168, 120 },
		{ 169, 121 },
		{ 170, 122 },
		{ 167, 123 },
		{ 174, 126 },
		{ 109, 45 },
		{ 110, 46 },
		{ 111, 47 },
		{ 175, 132 },
		{ 176, 133 },
		{ 177, 134 },
		{ 178, 135 },
		{ 84, 31 },
		{ 181, 138 },
		{ 182, 139 },
		{ 183, 140 },
		{ 184, 141 },
		{ 185, 142 },
		{ 186, 143 },
		{ 187, 144 },
		{ 188, 145 },
		{ 189, 147 },
		{ 190, 149 },
		{ 191, 150 },
		{ 192, 151 },
		{ 193, 152 },
		{ 194, 153 },
		{ 195, 154 },
		{ 196, 155 },
		{ 197, 156 },
		{ 198, 157 },
		{ 199, 158 },
		{ 200, 159 },
		{ 201, 160 },
		{ 202, 161 },
		{ 203, 162 },
		{ 204, 163 },
		{ 205, 164 },
		{ 206, 165 },
		{ 207, 166 },
		{ 165, 167 },
		{ 208, 168 },
		{ 206, 169 },
		{ 209, 170 },
		{ 174, 171 },
		{ 125, 172 },
		{ 114, 55 },
		{ 211, 176 },
		{ 212, 179 },
		{ 213, 180 },
		{ 214, 182 },
		{ 215, 183 },
		{ 216, 187 },
		{ 217, 188 },
		{ 218, 192 },
		{ 219, 193 },
		{ 220, 194 },
		{ 221, 195 },
		{ 222, 196 },
		{ 223, 197 },
		{ 224, 198 },
		{ 225, 199 },
		{ 226, 200 },
		{ 227, 201 },
		{ 228, 202 },
		{ 229, 204 },
		{ 230, 205 },
		{ 0, 206 },
		{ 206, 207 },
		{ 231, 208 },
		{ 232, 209 },
		{ 171, 210 },
		{ 233, 213 },
		{ 234, 214 },
		{ 235, 215 },
		{ 236, 216 },
		{ 237, 218 },
		{ 238, 219 },
		{ 239, 221 },
		{ 240, 222 },
		{ 241, 223 },
		{ 242, 224 },
		{ 243, 225 },
		{ 244, 226 },
		{ 245, 228 },
		{ 246, 229 },
		{ 169, 231 },
		{ 206, 232 },
		{ 247, 233 },
		{ 248, 234 },
		{ 249, 237 },
		{ 250, 244 },
		{ 251, 245 },
		{ 252, 246 },
		{ 253, 247 },
		{ 254, 249 },
		{ 255, 251 },
		{ 256, 252 },
		{ 115, 56 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 91 },
		{ 0, 112, 90 },
		{ 0, 0, 89 },
		{ 0, 297, 91 },
		{ 0, 203, 66 },
		{ 114, 0, 91 },
		{ 0, 148, 1 },
		{ 0, 194, 70 },
		{ 0, 84, 75 },
		{ 65, 227, 91 },
		{ 0, 0, 83 },
		{ 0, 0, 84 },
		{ 0, 226, 68 },
		{ 0, 80, 71 },
		{ 0, 0, 88 },
		{ 0, 88, 72 },
		{ 0, 0, 44 },
		{ 0, -33, 69 },
		{ 127, 221, 41 },
		{ 0, 0, 80 },
		{ 0, 0, 87 },
		{ 0, 138, 74 },
		{ 0, 239, 78 },
		{ 0, 135, 73 },
		{ 0, 0, 79 },
		{ 256, 0, 40 },
		{ 0, 0, 85 },
		{ 0, 0, 86 },
		{ 0, 266, 77 },
		{ 256, 13, 40 },
		{ 256, 38, 40 },
		{ 256, 157, 40 },
		{ 256, -91, 40 },
		{ 256, 18, 40 },
		{ 256, 40, 40 },
		{ 256, 181, 40 },
		{ 256, 25, 40 },
		{ 256, 191, 40 },
		{ 256, 206, 40 },
		{ 256, 205, 40 },
		{ 256, -97, 40 },
		{ 256, 188, 40 },
		{ 256, 210, 40 },
		{ 256, 210, 40 },
		{ 256, 218, 40 },
		{ 0, 0, 81 },
		{ 0, -40, 76 },
		{ 0, 0, 82 },
		{ 0, 0, 67 },
		{ 0, 0, 53 },
		{ 114, 0, 0 },
		{ 0, 0, 43 },
		{ 114, 327, 0 },
		{ 0, 312, 0 },
		{ 0, 26, 0 },
		{ 0, 37, 0 },
		{ 0, 64, 0 },
		{ 0, 137, 0 },
		{ 0, 142, 0 },
		{ 0, 0, 60 },
		{ 0, 0, 54 },
		{ 0, 0, 63 },
		{ 66, -36, 0 },
		{ -65, 247, 0 },
		{ 0, 0, 58 },
		{ 0, 0, 46 },
		{ 0, 0, 56 },
		{ 0, 0, 47 },
		{ 0, 0, 57 },
		{ 0, 0, 45 },
		{ -125, 216, 0 },
		{ -74, 253, 2 },
		{ 0, 0, 59 },
		{ 127, 62, 0 },
		{ 128, -30, 0 },
		{ 0, 0, 41 },
		{ 0, 218, 48 },
		{ 0, 0, 51 },
		{ 0, 0, 52 },
		{ 0, 0, 50 },
		{ 0, 219, 49 },
		{ 0, 0, 64 },
		{ 256, 165, 40 },
		{ 256, 182, 40 },
		{ 256, 169, 40 },
		{ 256, 188, 40 },
		{ 256, 176, 40 },
		{ 256, -99, 40 },
		{ 256, 186, 40 },
		{ 256, 172, 26 },
		{ 256, 175, 40 },
		{ 256, 25, 40 },
		{ 256, 177, 40 },
		{ 256, 183, 40 },
		{ 256, 181, 40 },
		{ 256, 180, 40 },
		{ 256, 0, 20 },
		{ 256, 181, 40 },
		{ 256, 188, 40 },
		{ 256, 194, 40 },
		{ 256, 21, 40 },
		{ 256, 190, 40 },
		{ 256, -99, 40 },
		{ 256, 32, 40 },
		{ 256, 199, 40 },
		{ 256, 193, 40 },
		{ 256, -99, 40 },
		{ 256, 60, 40 },
		{ 256, 203, 40 },
		{ 0, 0, 65 },
		{ 0, 0, 55 },
		{ -53, 109, 43 },
		{ 0, 208, 0 },
		{ 0, 206, 0 },
		{ 0, 212, 0 },
		{ 0, 199, 0 },
		{ 123, 204, 0 },
		{ 0, 216, 0 },
		{ 0, 206, 0 },
		{ 0, 220, 0 },
		{ 0, 218, 0 },
		{ 0, 0, 42 },
		{ 210, 0, 0 },
		{ 173, 272, 0 },
		{ 129, 190, 41 },
		{ 129, 18, 0 },
		{ 0, 180, 41 },
		{ 0, 0, 61 },
		{ 0, 0, 62 },
		{ 256, 212, 40 },
		{ 256, 227, 40 },
		{ 256, 224, 40 },
		{ 256, 212, 40 },
		{ 256, 0, 5 },
		{ 256, 51, 40 },
		{ 256, 212, 40 },
		{ 256, 232, 40 },
		{ 256, 232, 40 },
		{ 256, 230, 40 },
		{ 256, 224, 40 },
		{ 256, 224, 40 },
		{ 256, 233, 40 },
		{ 256, 238, 40 },
		{ 256, 0, 25 },
		{ 256, 225, 40 },
		{ 256, 0, 10 },
		{ 256, 234, 40 },
		{ 256, 228, 40 },
		{ 256, 234, 40 },
		{ 256, 223, 40 },
		{ 256, 227, 40 },
		{ 256, 232, 40 },
		{ 256, 242, 40 },
		{ 256, 228, 40 },
		{ 256, 228, 40 },
		{ 256, 230, 40 },
		{ 256, 246, 40 },
		{ 256, 237, 40 },
		{ 256, 244, 40 },
		{ 256, 250, 40 },
		{ 256, 254, 40 },
		{ 256, 244, 40 },
		{ 0, 251, 0 },
		{ 0, 243, 0 },
		{ 0, 254, 0 },
		{ 0, 248, 0 },
		{ 0, 256, 0 },
		{ 0, 255, 0 },
		{ -172, 312, 0 },
		{ 173, 313, 0 },
		{ -172, -30, 0 },
		{ 0, 0, 3 },
		{ 256, 0, 32 },
		{ 256, 255, 40 },
		{ 256, 0, 23 },
		{ 256, 0, 8 },
		{ 256, 247, 40 },
		{ 256, 259, 40 },
		{ 256, 0, 6 },
		{ 256, 248, 40 },
		{ 256, 258, 40 },
		{ 256, 0, 21 },
		{ 256, 0, 7 },
		{ 256, 0, 18 },
		{ 256, 253, 40 },
		{ 256, 252, 40 },
		{ 256, 0, 30 },
		{ 256, 0, 11 },
		{ 256, 0, 4 },
		{ 256, 254, 40 },
		{ 256, 256, 40 },
		{ 256, 255, 40 },
		{ 256, 271, 40 },
		{ 256, 262, 40 },
		{ 256, 269, 40 },
		{ 256, 276, 40 },
		{ 256, 277, 40 },
		{ 256, 277, 40 },
		{ 256, 268, 40 },
		{ 256, 276, 40 },
		{ 256, 0, 19 },
		{ 256, 264, 40 },
		{ 256, 280, 40 },
		{ -206, 372, 1 },
		{ 0, 269, 0 },
		{ 0, 267, 0 },
		{ 0, 276, 0 },
		{ -125, 344, 3 },
		{ 256, 0, 28 },
		{ 256, 0, 36 },
		{ 256, 277, 40 },
		{ 256, 280, 40 },
		{ 256, 288, 40 },
		{ 256, 280, 40 },
		{ 256, 0, 12 },
		{ 256, 275, 40 },
		{ 256, 282, 40 },
		{ 256, 0, 9 },
		{ 256, 293, 40 },
		{ 256, 292, 40 },
		{ 256, 296, 40 },
		{ 256, 280, 40 },
		{ 256, 293, 40 },
		{ 256, 297, 40 },
		{ 256, 0, 17 },
		{ 256, 289, 40 },
		{ 256, 295, 40 },
		{ 256, 0, 27 },
		{ 0, 301, 0 },
		{ 0, 305, 0 },
		{ 256, 286, 40 },
		{ 256, 288, 40 },
		{ 256, 0, 13 },
		{ 256, 0, 33 },
		{ 256, 304, 40 },
		{ 256, 0, 31 },
		{ 256, 0, 15 },
		{ 256, 0, 37 },
		{ 256, 0, 35 },
		{ 256, 0, 16 },
		{ 256, 0, 22 },
		{ 256, 304, 40 },
		{ 256, 306, 40 },
		{ 256, 300, 40 },
		{ 256, 308, 40 },
		{ 256, 0, 24 },
		{ 256, 296, 40 },
		{ 256, 0, 38 },
		{ 256, 311, 40 },
		{ 256, 311, 40 },
		{ 256, 0, 29 },
		{ 256, 0, 34 },
		{ 256, 0, 14 },
		{ 0, 105, 39 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 599 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


