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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/19/19
* Time: 10:43:03
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 73 ".\\myparser.y"

	// place any extra class members here
	virtual void yyerror(const char YYFAR* text);

#line 70 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 89 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif

#line 83 "myparser.h"
#define MAIN 257
#define CHAR 258
#define SHORT 259
#define INT 260
#define FLOAT 261
#define DOUBLE 262
#define LONG 263
#define UNSIGNED 264
#define SIGNED 265
#define STRUCT 266
#define UNION 267
#define ENUM 268
#define VOID 269
#define IF 270
#define ELSE 271
#define SWITCH 272
#define CASE 273
#define DEFAULT 274
#define FOR 275
#define DO 276
#define WHILE 277
#define BREAK 278
#define CONTINUE 279
#define GOTO 280
#define RETURN 281
#define AUTO 282
#define REGISTER 283
#define STATIC 284
#define CONST 285
#define SIZEOF 286
#define TYPEDEF 287
#define VOLATILE 288
#define ID 289
#define NUM 290
#define CHARCONST 291
#define STRCONST 292
#define POINTMEM 293
#define ARROWMEM 294
#define PLUSPLUS 295
#define MINUSMINUS 296
#define SHIFTLEFT 297
#define SHIFTRIGHT 298
#define GREEQU 299
#define SMAEQU 300
#define EQUAL 301
#define NOTEQUAL 302
#define LOGAND 303
#define LOGOR 304
#define PLUSASSIGN 305
#define MINUSASSIGN 306
#define MULASSIGN 307
#define OVERASSIGN 308
#define MODASSIGN 309
#define LSHIFTASSIGN 310
#define RSHIFTASSIGN 311
#define ANDASSIGN 312
#define XORASSIGN 313
#define ORASSIGN 314
#define NOT 315
#define NEG 316
#define STAR 317
#define OVER 318
#define MOD 319
#define PLUS 320
#define MINUS 321
#define GREAT 322
#define SMALL 323
#define AND 324
#define OR 325
#define XOR 326
#define ASSIGN 327
#define QUES 328
#define COLON 329
#define LBRACE 330
#define RBRACE 331
#define LPAREN 332
#define RPAREN 333
#define LSQURE 334
#define RSQURE 335
#define SEMICOLON 336
#define COMMA 337
#define ERROR 338
#define MUL 339
#define POINTER 340
#define GETADDR 341
#define GETDATA 342
#define PLUSU 343
#define MINUSU 344
#define PLUSPLUSL 345
#define PLUSPLUSR 346
#define MINUSMINUSL 347
#define MINUSMINUSR 348
#define INPUT 349
#define OUTPUT 350
#define EXTERN 351
#define ENDL 352
#define IFU 353
#endif
