#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 72 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 12/19/19
# Time: 10:43:03
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : global_decl
    2          | global_decl program

    3  entry : type_specifier MAIN LPAREN RPAREN compound_stmt
    4        | MAIN LPAREN RPAREN compound_stmt
    5        | type_specifier MAIN LPAREN VOID RPAREN compound_stmt
    6        | MAIN LPAREN VOID RPAREN compound_stmt
    7        |

    8  global_decl : entry
    9              | var_decl_stmt

   10  type_specifier : INT
   11                 | CHAR
   12                 | VOID

   13  var_decl : type_specifier decl_list
   14           | STATIC type_specifier decl_list

   15  decl_list_unit : ID

   16  pointer : STAR
   17          | STAR pointer

   18  decl_init : assign_expr

   19  decl_list : decl_list_unit
   20            | decl_list_unit COMMA decl_list

   21  expr : assign_expr
   22       | expr COMMA assign_expr

   23  assign_expr : logical_or
   24              | unary_expr ASSIGN assign_expr
   25              | unary_expr PLUSASSIGN assign_expr
   26              | unary_expr MINUSASSIGN assign_expr
   27              | unary_expr MULASSIGN assign_expr
   28              | unary_expr OVERASSIGN assign_expr
   29              | unary_expr MODASSIGN assign_expr
   30              | unary_expr LSHIFTASSIGN assign_expr
   31              | unary_expr RSHIFTASSIGN assign_expr
   32              | unary_expr ANDASSIGN assign_expr
   33              | unary_expr XORASSIGN assign_expr
   34              | unary_expr ORASSIGN assign_expr

   35  logical_or : logical_and
   36             | logical_or LOGOR logical_and

   37  logical_and : or_expr
   38              | logical_and LOGAND or_expr

   39  or_expr : xor_expr
   40          | or_expr OR xor_expr

   41  xor_expr : and_expr
   42           | xor_expr XOR and_expr

   43  and_expr : equal_expr
   44           | and_expr AND equal_expr

   45  equal_expr : compare_expr
   46             | equal_expr EQUAL compare_expr
   47             | equal_expr NOTEQUAL compare_expr

   48  compare_expr : shift_expr
   49               | compare_expr GREAT shift_expr
   50               | compare_expr SMALL shift_expr
   51               | compare_expr GREEQU shift_expr
   52               | compare_expr SMAEQU shift_expr

   53  shift_expr : add_expr
   54             | shift_expr SHIFTLEFT add_expr
   55             | shift_expr SHIFTRIGHT add_expr

   56  add_expr : mul_expr
   57           | add_expr PLUS mul_expr
   58           | add_expr MINUS mul_expr

   59  mul_expr : unary_expr
   60           | mul_expr STAR unary_expr
   61           | mul_expr OVER unary_expr
   62           | mul_expr MOD unary_expr

   63  unary_expr : factor
   64             | MINUS factor
   65             | PLUS factor
   66             | NOT factor
   67             | NEG factor
   68             | STAR factor
   69             | AND factor
   70             | PLUSPLUS factor
   71             | MINUSMINUS factor
   72             | factor PLUSPLUS
   73             | factor MINUSMINUS
   74             | LPAREN type_specifier RPAREN factor
   75             | LPAREN type_specifier pointer RPAREN factor

   76  factor : ID
   77         | NUM
   78         | CHARCONST
   79         | STRCONST
   80         | LPAREN expr RPAREN

   81  stmt : if_stmt
   82       | for_stmt
   83       | while_stmt
   84       | do_while_stmt
   85       | label_stmt
   86       | goto_stmt
   87       | continue_stmt
   88       | break_stmt
   89       | return_stmt
   90       | expr_stmt
   91       | var_decl_stmt
   92       | compound_stmt
   93       | input_stmt
   94       | output_stmt

   95  input_stmt : INPUT LPAREN expr RPAREN SEMICOLON

   96  output_stmt : OUTPUT LPAREN expr RPAREN SEMICOLON

   97  input_stmt : INPUT SHIFTRIGHT expr SEMICOLON

   98  output_stmt : OUTPUT SHIFTLEFT expr SEMICOLON

   99  label_stmt : ID COLON stmt
  100             | CASE COLON stmt
  101             | DEFAULT COLON stmt

  102  goto_stmt : GOTO ID SEMICOLON

  103  continue_stmt : CONTINUE SEMICOLON

  104  break_stmt : BREAK SEMICOLON

  105  return_stmt : RETURN SEMICOLON
  106              | RETURN expr SEMICOLON

  107  var_decl_stmt : var_decl SEMICOLON

  108  expr_stmt : expr SEMICOLON
  109            | SEMICOLON

  110  compound_stmt : LBRACE stmts RBRACE

  111  stmts : stmt stmts
  112        | stmt
  113        |

  114  if_stmt : IF LPAREN expr RPAREN stmt
  115          | IF LPAREN expr RPAREN stmt ELSE stmt

  116  while_stmt : WHILE LPAREN expr RPAREN stmt

  117  do_while_stmt : DO stmt WHILE LPAREN expr RPAREN SEMICOLON

  118  for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
  119           | FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
  120           | FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
  121           | FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
  122           | FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
  123           | FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
  124           | FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
  125           | FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt


##############################################################################
# States
##############################################################################

0: shift-reduce conflict (shift 1, reduce 7) on MAIN
0: shift-reduce conflict (shift 2, reduce 7) on CHAR
0: shift-reduce conflict (shift 3, reduce 7) on INT
0: shift-reduce conflict (shift 4, reduce 7) on VOID
0: shift-reduce conflict (shift 5, reduce 7) on STATIC
state 0
	$accept : . program $end
	entry : .  (7)

	MAIN  shift 1
	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	STATIC  shift 5
	.  reduce 7

	global_decl  goto 6
	program  goto 7
	type_specifier  goto 8
	var_decl_stmt  goto 9
	entry  goto 10
	var_decl  goto 11


state 1
	entry : MAIN . LPAREN RPAREN compound_stmt
	entry : MAIN . LPAREN VOID RPAREN compound_stmt

	LPAREN  shift 12


state 2
	type_specifier : CHAR .  (11)

	.  reduce 11


state 3
	type_specifier : INT .  (10)

	.  reduce 10


state 4
	type_specifier : VOID .  (12)

	.  reduce 12


state 5
	var_decl : STATIC . type_specifier decl_list

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4

	type_specifier  goto 13


6: reduce-reduce conflict (reduce 1, reduce 7) on $end
6: shift-reduce conflict (shift 1, reduce 7) on MAIN
6: shift-reduce conflict (shift 2, reduce 7) on CHAR
6: shift-reduce conflict (shift 3, reduce 7) on INT
6: shift-reduce conflict (shift 4, reduce 7) on VOID
6: shift-reduce conflict (shift 5, reduce 7) on STATIC
state 6
	program : global_decl . program
	program : global_decl .  (1)
	entry : .  (7)

	MAIN  shift 1
	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	STATIC  shift 5
	.  reduce 1

	global_decl  goto 6
	program  goto 14
	type_specifier  goto 8
	var_decl_stmt  goto 9
	entry  goto 10
	var_decl  goto 11


state 7
	$accept : program . $end  (0)

	$end  accept


state 8
	entry : type_specifier . MAIN LPAREN RPAREN compound_stmt
	entry : type_specifier . MAIN LPAREN VOID RPAREN compound_stmt
	var_decl : type_specifier . decl_list

	MAIN  shift 15
	ID  shift 16

	decl_list  goto 17
	decl_list_unit  goto 18


state 9
	global_decl : var_decl_stmt .  (9)

	.  reduce 9


state 10
	global_decl : entry .  (8)

	.  reduce 8


state 11
	var_decl_stmt : var_decl . SEMICOLON

	SEMICOLON  shift 19


state 12
	entry : MAIN LPAREN . RPAREN compound_stmt
	entry : MAIN LPAREN . VOID RPAREN compound_stmt

	VOID  shift 20
	RPAREN  shift 21


state 13
	var_decl : STATIC type_specifier . decl_list

	ID  shift 16

	decl_list  goto 22
	decl_list_unit  goto 18


state 14
	program : global_decl program .  (2)

	.  reduce 2


state 15
	entry : type_specifier MAIN . LPAREN RPAREN compound_stmt
	entry : type_specifier MAIN . LPAREN VOID RPAREN compound_stmt

	LPAREN  shift 23


state 16
	decl_list_unit : ID .  (15)

	.  reduce 15


state 17
	var_decl : type_specifier decl_list .  (13)

	.  reduce 13


state 18
	decl_list : decl_list_unit .  (19)
	decl_list : decl_list_unit . COMMA decl_list

	COMMA  shift 24
	.  reduce 19


state 19
	var_decl_stmt : var_decl SEMICOLON .  (107)

	.  reduce 107


state 20
	entry : MAIN LPAREN VOID . RPAREN compound_stmt

	RPAREN  shift 25


state 21
	entry : MAIN LPAREN RPAREN . compound_stmt

	LBRACE  shift 26

	compound_stmt  goto 27


state 22
	var_decl : STATIC type_specifier decl_list .  (14)

	.  reduce 14


state 23
	entry : type_specifier MAIN LPAREN . RPAREN compound_stmt
	entry : type_specifier MAIN LPAREN . VOID RPAREN compound_stmt

	VOID  shift 28
	RPAREN  shift 29


state 24
	decl_list : decl_list_unit COMMA . decl_list

	ID  shift 16

	decl_list  goto 30
	decl_list_unit  goto 18


state 25
	entry : MAIN LPAREN VOID RPAREN . compound_stmt

	LBRACE  shift 26

	compound_stmt  goto 31


state 26
	compound_stmt : LBRACE . stmts RBRACE
	stmts : .  (113)

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57
	.  reduce 113

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 75
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87
	stmts  goto 88


state 27
	entry : MAIN LPAREN RPAREN compound_stmt .  (4)

	.  reduce 4


state 28
	entry : type_specifier MAIN LPAREN VOID . RPAREN compound_stmt

	RPAREN  shift 89


state 29
	entry : type_specifier MAIN LPAREN RPAREN . compound_stmt

	LBRACE  shift 26

	compound_stmt  goto 90


state 30
	decl_list : decl_list_unit COMMA decl_list .  (20)

	.  reduce 20


state 31
	entry : MAIN LPAREN VOID RPAREN compound_stmt .  (6)

	.  reduce 6


state 32
	if_stmt : IF . LPAREN expr RPAREN stmt ELSE stmt
	if_stmt : IF . LPAREN expr RPAREN stmt

	LPAREN  shift 91


state 33
	label_stmt : CASE . COLON stmt

	COLON  shift 92


state 34
	label_stmt : DEFAULT . COLON stmt

	COLON  shift 93


state 35
	for_stmt : FOR . LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON RPAREN stmt

	LPAREN  shift 94


state 36
	do_while_stmt : DO . stmt WHILE LPAREN expr RPAREN SEMICOLON

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 95
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 37
	while_stmt : WHILE . LPAREN expr RPAREN stmt

	LPAREN  shift 96


state 38
	break_stmt : BREAK . SEMICOLON

	SEMICOLON  shift 97


state 39
	continue_stmt : CONTINUE . SEMICOLON

	SEMICOLON  shift 98


state 40
	goto_stmt : GOTO . ID SEMICOLON

	ID  shift 99


state 41
	return_stmt : RETURN . expr SEMICOLON
	return_stmt : RETURN . SEMICOLON

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	SEMICOLON  shift 101

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 102
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 42
	label_stmt : ID . COLON stmt
	factor : ID .  (76)

	COLON  shift 103
	.  reduce 76


state 43
	factor : NUM .  (77)

	.  reduce 77


state 44
	factor : CHARCONST .  (78)

	.  reduce 78


state 45
	factor : STRCONST .  (79)

	.  reduce 79


state 46
	unary_expr : PLUSPLUS . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 105


state 47
	unary_expr : MINUSMINUS . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 106


state 48
	unary_expr : NOT . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 107


state 49
	unary_expr : NEG . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 108


state 50
	unary_expr : STAR . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 109


state 51
	unary_expr : PLUS . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 110


state 52
	unary_expr : MINUS . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 111


state 53
	unary_expr : AND . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 112


state 54
	factor : LPAREN . expr RPAREN
	unary_expr : LPAREN . type_specifier RPAREN factor
	unary_expr : LPAREN . type_specifier pointer RPAREN factor

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	type_specifier  goto 113
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 114
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 55
	expr_stmt : SEMICOLON .  (109)

	.  reduce 109


state 56
	input_stmt : INPUT . SHIFTRIGHT expr SEMICOLON
	input_stmt : INPUT . LPAREN expr RPAREN SEMICOLON

	SHIFTRIGHT  shift 115
	LPAREN  shift 116


state 57
	output_stmt : OUTPUT . LPAREN expr RPAREN SEMICOLON
	output_stmt : OUTPUT . SHIFTLEFT expr SEMICOLON

	SHIFTLEFT  shift 117
	LPAREN  shift 118


state 58
	var_decl : type_specifier . decl_list

	ID  shift 16

	decl_list  goto 17
	decl_list_unit  goto 18


state 59
	stmt : compound_stmt .  (92)

	.  reduce 92


state 60
	stmt : var_decl_stmt .  (91)

	.  reduce 91


state 61
	and_expr : and_expr . AND equal_expr
	xor_expr : and_expr .  (41)

	AND  shift 119
	.  reduce 41


state 62
	assign_expr : logical_or .  (23)
	logical_or : logical_or . LOGOR logical_and

	LOGOR  shift 120
	.  reduce 23


state 63
	expr : expr . COMMA assign_expr
	expr_stmt : expr . SEMICOLON

	SEMICOLON  shift 121
	COMMA  shift 122


state 64
	assign_expr : unary_expr . ASSIGN assign_expr
	assign_expr : unary_expr . XORASSIGN assign_expr
	assign_expr : unary_expr . MULASSIGN assign_expr
	assign_expr : unary_expr . OVERASSIGN assign_expr
	assign_expr : unary_expr . PLUSASSIGN assign_expr
	assign_expr : unary_expr . MINUSASSIGN assign_expr
	assign_expr : unary_expr . LSHIFTASSIGN assign_expr
	assign_expr : unary_expr . MODASSIGN assign_expr
	assign_expr : unary_expr . RSHIFTASSIGN assign_expr
	assign_expr : unary_expr . ANDASSIGN assign_expr
	assign_expr : unary_expr . ORASSIGN assign_expr
	mul_expr : unary_expr .  (59)

	PLUSASSIGN  shift 123
	MINUSASSIGN  shift 124
	MULASSIGN  shift 125
	OVERASSIGN  shift 126
	MODASSIGN  shift 127
	LSHIFTASSIGN  shift 128
	RSHIFTASSIGN  shift 129
	ANDASSIGN  shift 130
	XORASSIGN  shift 131
	ORASSIGN  shift 132
	ASSIGN  shift 133
	.  reduce 59


state 65
	expr : assign_expr .  (21)

	.  reduce 21


state 66
	shift_expr : shift_expr . SHIFTRIGHT add_expr
	shift_expr : shift_expr . SHIFTLEFT add_expr
	compare_expr : shift_expr .  (48)

	SHIFTLEFT  shift 134
	SHIFTRIGHT  shift 135
	.  reduce 48


state 67
	equal_expr : equal_expr . NOTEQUAL compare_expr
	and_expr : equal_expr .  (43)
	equal_expr : equal_expr . EQUAL compare_expr

	EQUAL  shift 136
	NOTEQUAL  shift 137
	.  reduce 43


state 68
	add_expr : add_expr . MINUS mul_expr
	add_expr : add_expr . PLUS mul_expr
	shift_expr : add_expr .  (53)

	PLUS  shift 138
	MINUS  shift 139
	.  reduce 53


state 69
	logical_and : or_expr .  (37)
	or_expr : or_expr . OR xor_expr

	OR  shift 140
	.  reduce 37


state 70
	unary_expr : factor .  (63)
	unary_expr : factor . PLUSPLUS
	unary_expr : factor . MINUSMINUS

	PLUSPLUS  shift 141
	MINUSMINUS  shift 142
	.  reduce 63


state 71
	compare_expr : compare_expr . SMALL shift_expr
	compare_expr : compare_expr . SMAEQU shift_expr
	compare_expr : compare_expr . GREEQU shift_expr
	compare_expr : compare_expr . GREAT shift_expr
	equal_expr : compare_expr .  (45)

	GREEQU  shift 143
	SMAEQU  shift 144
	GREAT  shift 145
	SMALL  shift 146
	.  reduce 45


state 72
	or_expr : xor_expr .  (39)
	xor_expr : xor_expr . XOR and_expr

	XOR  shift 147
	.  reduce 39


state 73
	logical_or : logical_and .  (35)
	logical_and : logical_and . LOGAND or_expr

	LOGAND  shift 148
	.  reduce 35


state 74
	add_expr : mul_expr .  (56)
	mul_expr : mul_expr . OVER unary_expr
	mul_expr : mul_expr . MOD unary_expr
	mul_expr : mul_expr . STAR unary_expr

	STAR  shift 149
	OVER  shift 150
	MOD  shift 151
	.  reduce 56


75: reduce-reduce conflict (reduce 112, reduce 113) on RBRACE
state 75
	stmts : stmt . stmts
	stmts : stmt .  (112)
	stmts : .  (113)

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57
	.  reduce 112

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 75
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87
	stmts  goto 152


state 76
	stmt : do_while_stmt .  (84)

	.  reduce 84


state 77
	stmt : break_stmt .  (88)

	.  reduce 88


state 78
	stmt : return_stmt .  (89)

	.  reduce 89


state 79
	stmt : input_stmt .  (93)

	.  reduce 93


state 80
	stmt : label_stmt .  (85)

	.  reduce 85


state 81
	stmt : goto_stmt .  (86)

	.  reduce 86


state 82
	stmt : continue_stmt .  (87)

	.  reduce 87


state 83
	stmt : expr_stmt .  (90)

	.  reduce 90


state 84
	stmt : output_stmt .  (94)

	.  reduce 94


state 85
	stmt : if_stmt .  (81)

	.  reduce 81


state 86
	stmt : for_stmt .  (82)

	.  reduce 82


state 87
	stmt : while_stmt .  (83)

	.  reduce 83


state 88
	compound_stmt : LBRACE stmts . RBRACE

	RBRACE  shift 153


state 89
	entry : type_specifier MAIN LPAREN VOID RPAREN . compound_stmt

	LBRACE  shift 26

	compound_stmt  goto 154


state 90
	entry : type_specifier MAIN LPAREN RPAREN compound_stmt .  (3)

	.  reduce 3


state 91
	if_stmt : IF LPAREN . expr RPAREN stmt ELSE stmt
	if_stmt : IF LPAREN . expr RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 155
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 92
	label_stmt : CASE COLON . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 156
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 93
	label_stmt : DEFAULT COLON . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 157
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 94
	for_stmt : FOR LPAREN . expr SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	SEMICOLON  shift 158

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 159
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 95
	do_while_stmt : DO stmt . WHILE LPAREN expr RPAREN SEMICOLON

	WHILE  shift 160


state 96
	while_stmt : WHILE LPAREN . expr RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 161
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 97
	break_stmt : BREAK SEMICOLON .  (104)

	.  reduce 104


state 98
	continue_stmt : CONTINUE SEMICOLON .  (103)

	.  reduce 103


state 99
	goto_stmt : GOTO ID . SEMICOLON

	SEMICOLON  shift 162


state 100
	factor : ID .  (76)

	.  reduce 76


state 101
	return_stmt : RETURN SEMICOLON .  (105)

	.  reduce 105


state 102
	expr : expr . COMMA assign_expr
	return_stmt : RETURN expr . SEMICOLON

	SEMICOLON  shift 163
	COMMA  shift 122


state 103
	label_stmt : ID COLON . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 164
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 104
	factor : LPAREN . expr RPAREN

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 114
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 105
	unary_expr : PLUSPLUS factor .  (70)

	.  reduce 70


state 106
	unary_expr : MINUSMINUS factor .  (71)

	.  reduce 71


state 107
	unary_expr : NOT factor .  (66)

	.  reduce 66


state 108
	unary_expr : NEG factor .  (67)

	.  reduce 67


state 109
	unary_expr : STAR factor .  (68)

	.  reduce 68


state 110
	unary_expr : PLUS factor .  (65)

	.  reduce 65


state 111
	unary_expr : MINUS factor .  (64)

	.  reduce 64


state 112
	unary_expr : AND factor .  (69)

	.  reduce 69


state 113
	unary_expr : LPAREN type_specifier . RPAREN factor
	unary_expr : LPAREN type_specifier . pointer RPAREN factor

	STAR  shift 165
	RPAREN  shift 166

	pointer  goto 167


state 114
	expr : expr . COMMA assign_expr
	factor : LPAREN expr . RPAREN

	RPAREN  shift 168
	COMMA  shift 122


state 115
	input_stmt : INPUT SHIFTRIGHT . expr SEMICOLON

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 169
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 116
	input_stmt : INPUT LPAREN . expr RPAREN SEMICOLON

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 170
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 117
	output_stmt : OUTPUT SHIFTLEFT . expr SEMICOLON

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 171
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 118
	output_stmt : OUTPUT LPAREN . expr RPAREN SEMICOLON

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 172
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 119
	and_expr : and_expr AND . equal_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	shift_expr  goto 66
	equal_expr  goto 174
	add_expr  goto 68
	factor  goto 70
	compare_expr  goto 71
	mul_expr  goto 74


state 120
	logical_or : logical_or LOGOR . logical_and

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	unary_expr  goto 173
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 175
	mul_expr  goto 74


state 121
	expr_stmt : expr SEMICOLON .  (108)

	.  reduce 108


state 122
	expr : expr COMMA . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 176
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 123
	assign_expr : unary_expr PLUSASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 177
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 124
	assign_expr : unary_expr MINUSASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 178
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 125
	assign_expr : unary_expr MULASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 179
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 126
	assign_expr : unary_expr OVERASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 180
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 127
	assign_expr : unary_expr MODASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 181
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 128
	assign_expr : unary_expr LSHIFTASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 182
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 129
	assign_expr : unary_expr RSHIFTASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 183
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 130
	assign_expr : unary_expr ANDASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 184
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 131
	assign_expr : unary_expr XORASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 185
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 132
	assign_expr : unary_expr ORASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 186
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 133
	assign_expr : unary_expr ASSIGN . assign_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	unary_expr  goto 64
	assign_expr  goto 187
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 134
	shift_expr : shift_expr SHIFTLEFT . add_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	add_expr  goto 188
	factor  goto 70
	mul_expr  goto 74


state 135
	shift_expr : shift_expr SHIFTRIGHT . add_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	add_expr  goto 189
	factor  goto 70
	mul_expr  goto 74


state 136
	equal_expr : equal_expr EQUAL . compare_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	shift_expr  goto 66
	add_expr  goto 68
	factor  goto 70
	compare_expr  goto 190
	mul_expr  goto 74


state 137
	equal_expr : equal_expr NOTEQUAL . compare_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	shift_expr  goto 66
	add_expr  goto 68
	factor  goto 70
	compare_expr  goto 191
	mul_expr  goto 74


state 138
	add_expr : add_expr PLUS . mul_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	factor  goto 70
	mul_expr  goto 192


state 139
	add_expr : add_expr MINUS . mul_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	factor  goto 70
	mul_expr  goto 193


state 140
	or_expr : or_expr OR . xor_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	unary_expr  goto 173
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 194
	mul_expr  goto 74


state 141
	unary_expr : factor PLUSPLUS .  (72)

	.  reduce 72


state 142
	unary_expr : factor MINUSMINUS .  (73)

	.  reduce 73


state 143
	compare_expr : compare_expr GREEQU . shift_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	shift_expr  goto 195
	add_expr  goto 68
	factor  goto 70
	mul_expr  goto 74


state 144
	compare_expr : compare_expr SMAEQU . shift_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	shift_expr  goto 196
	add_expr  goto 68
	factor  goto 70
	mul_expr  goto 74


state 145
	compare_expr : compare_expr GREAT . shift_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	shift_expr  goto 197
	add_expr  goto 68
	factor  goto 70
	mul_expr  goto 74


state 146
	compare_expr : compare_expr SMALL . shift_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 173
	shift_expr  goto 198
	add_expr  goto 68
	factor  goto 70
	mul_expr  goto 74


state 147
	xor_expr : xor_expr XOR . and_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 199
	unary_expr  goto 173
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	factor  goto 70
	compare_expr  goto 71
	mul_expr  goto 74


state 148
	logical_and : logical_and LOGAND . or_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	unary_expr  goto 173
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 200
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	mul_expr  goto 74


state 149
	mul_expr : mul_expr STAR . unary_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 201
	factor  goto 70


state 150
	mul_expr : mul_expr OVER . unary_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 202
	factor  goto 70


state 151
	mul_expr : mul_expr MOD . unary_expr

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	unary_expr  goto 203
	factor  goto 70


state 152
	stmts : stmt stmts .  (111)

	.  reduce 111


state 153
	compound_stmt : LBRACE stmts RBRACE .  (110)

	.  reduce 110


state 154
	entry : type_specifier MAIN LPAREN VOID RPAREN compound_stmt .  (5)

	.  reduce 5


state 155
	expr : expr . COMMA assign_expr
	if_stmt : IF LPAREN expr . RPAREN stmt ELSE stmt
	if_stmt : IF LPAREN expr . RPAREN stmt

	RPAREN  shift 204
	COMMA  shift 122


state 156
	label_stmt : CASE COLON stmt .  (100)

	.  reduce 100


state 157
	label_stmt : DEFAULT COLON stmt .  (101)

	.  reduce 101


state 158
	for_stmt : FOR LPAREN SEMICOLON . expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	SEMICOLON  shift 205

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 206
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 159
	expr : expr . COMMA assign_expr
	for_stmt : FOR LPAREN expr . SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON expr SEMICOLON expr RPAREN stmt

	SEMICOLON  shift 207
	COMMA  shift 122


state 160
	do_while_stmt : DO stmt WHILE . LPAREN expr RPAREN SEMICOLON

	LPAREN  shift 208


state 161
	expr : expr . COMMA assign_expr
	while_stmt : WHILE LPAREN expr . RPAREN stmt

	RPAREN  shift 209
	COMMA  shift 122


state 162
	goto_stmt : GOTO ID SEMICOLON .  (102)

	.  reduce 102


state 163
	return_stmt : RETURN expr SEMICOLON .  (106)

	.  reduce 106


state 164
	label_stmt : ID COLON stmt .  (99)

	.  reduce 99


state 165
	pointer : STAR .  (16)
	pointer : STAR . pointer

	STAR  shift 165
	.  reduce 16

	pointer  goto 210


state 166
	unary_expr : LPAREN type_specifier RPAREN . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 211


state 167
	unary_expr : LPAREN type_specifier pointer . RPAREN factor

	RPAREN  shift 212


state 168
	factor : LPAREN expr RPAREN .  (80)

	.  reduce 80


state 169
	expr : expr . COMMA assign_expr
	input_stmt : INPUT SHIFTRIGHT expr . SEMICOLON

	SEMICOLON  shift 213
	COMMA  shift 122


state 170
	expr : expr . COMMA assign_expr
	input_stmt : INPUT LPAREN expr . RPAREN SEMICOLON

	RPAREN  shift 214
	COMMA  shift 122


state 171
	expr : expr . COMMA assign_expr
	output_stmt : OUTPUT SHIFTLEFT expr . SEMICOLON

	SEMICOLON  shift 215
	COMMA  shift 122


state 172
	expr : expr . COMMA assign_expr
	output_stmt : OUTPUT LPAREN expr . RPAREN SEMICOLON

	RPAREN  shift 216
	COMMA  shift 122


state 173
	mul_expr : unary_expr .  (59)

	.  reduce 59


state 174
	equal_expr : equal_expr . NOTEQUAL compare_expr
	and_expr : and_expr AND equal_expr .  (44)
	equal_expr : equal_expr . EQUAL compare_expr

	EQUAL  shift 136
	NOTEQUAL  shift 137
	.  reduce 44


state 175
	logical_or : logical_or LOGOR logical_and .  (36)
	logical_and : logical_and . LOGAND or_expr

	LOGAND  shift 148
	.  reduce 36


state 176
	expr : expr COMMA assign_expr .  (22)

	.  reduce 22


state 177
	assign_expr : unary_expr PLUSASSIGN assign_expr .  (25)

	.  reduce 25


state 178
	assign_expr : unary_expr MINUSASSIGN assign_expr .  (26)

	.  reduce 26


state 179
	assign_expr : unary_expr MULASSIGN assign_expr .  (27)

	.  reduce 27


state 180
	assign_expr : unary_expr OVERASSIGN assign_expr .  (28)

	.  reduce 28


state 181
	assign_expr : unary_expr MODASSIGN assign_expr .  (29)

	.  reduce 29


state 182
	assign_expr : unary_expr LSHIFTASSIGN assign_expr .  (30)

	.  reduce 30


state 183
	assign_expr : unary_expr RSHIFTASSIGN assign_expr .  (31)

	.  reduce 31


state 184
	assign_expr : unary_expr ANDASSIGN assign_expr .  (32)

	.  reduce 32


state 185
	assign_expr : unary_expr XORASSIGN assign_expr .  (33)

	.  reduce 33


state 186
	assign_expr : unary_expr ORASSIGN assign_expr .  (34)

	.  reduce 34


state 187
	assign_expr : unary_expr ASSIGN assign_expr .  (24)

	.  reduce 24


state 188
	add_expr : add_expr . MINUS mul_expr
	shift_expr : shift_expr SHIFTLEFT add_expr .  (54)
	add_expr : add_expr . PLUS mul_expr

	PLUS  shift 138
	MINUS  shift 139
	.  reduce 54


state 189
	add_expr : add_expr . MINUS mul_expr
	shift_expr : shift_expr SHIFTRIGHT add_expr .  (55)
	add_expr : add_expr . PLUS mul_expr

	PLUS  shift 138
	MINUS  shift 139
	.  reduce 55


state 190
	compare_expr : compare_expr . SMALL shift_expr
	compare_expr : compare_expr . SMAEQU shift_expr
	equal_expr : equal_expr EQUAL compare_expr .  (46)
	compare_expr : compare_expr . GREEQU shift_expr
	compare_expr : compare_expr . GREAT shift_expr

	GREEQU  shift 143
	SMAEQU  shift 144
	GREAT  shift 145
	SMALL  shift 146
	.  reduce 46


state 191
	equal_expr : equal_expr NOTEQUAL compare_expr .  (47)
	compare_expr : compare_expr . SMALL shift_expr
	compare_expr : compare_expr . SMAEQU shift_expr
	compare_expr : compare_expr . GREEQU shift_expr
	compare_expr : compare_expr . GREAT shift_expr

	GREEQU  shift 143
	SMAEQU  shift 144
	GREAT  shift 145
	SMALL  shift 146
	.  reduce 47


state 192
	mul_expr : mul_expr . OVER unary_expr
	mul_expr : mul_expr . MOD unary_expr
	mul_expr : mul_expr . STAR unary_expr
	add_expr : add_expr PLUS mul_expr .  (57)

	STAR  shift 149
	OVER  shift 150
	MOD  shift 151
	.  reduce 57


state 193
	add_expr : add_expr MINUS mul_expr .  (58)
	mul_expr : mul_expr . OVER unary_expr
	mul_expr : mul_expr . MOD unary_expr
	mul_expr : mul_expr . STAR unary_expr

	STAR  shift 149
	OVER  shift 150
	MOD  shift 151
	.  reduce 58


state 194
	xor_expr : xor_expr . XOR and_expr
	or_expr : or_expr OR xor_expr .  (40)

	XOR  shift 147
	.  reduce 40


state 195
	shift_expr : shift_expr . SHIFTRIGHT add_expr
	shift_expr : shift_expr . SHIFTLEFT add_expr
	compare_expr : compare_expr GREEQU shift_expr .  (51)

	SHIFTLEFT  shift 134
	SHIFTRIGHT  shift 135
	.  reduce 51


state 196
	compare_expr : compare_expr SMAEQU shift_expr .  (52)
	shift_expr : shift_expr . SHIFTRIGHT add_expr
	shift_expr : shift_expr . SHIFTLEFT add_expr

	SHIFTLEFT  shift 134
	SHIFTRIGHT  shift 135
	.  reduce 52


state 197
	shift_expr : shift_expr . SHIFTRIGHT add_expr
	shift_expr : shift_expr . SHIFTLEFT add_expr
	compare_expr : compare_expr GREAT shift_expr .  (49)

	SHIFTLEFT  shift 134
	SHIFTRIGHT  shift 135
	.  reduce 49


state 198
	compare_expr : compare_expr SMALL shift_expr .  (50)
	shift_expr : shift_expr . SHIFTRIGHT add_expr
	shift_expr : shift_expr . SHIFTLEFT add_expr

	SHIFTLEFT  shift 134
	SHIFTRIGHT  shift 135
	.  reduce 50


state 199
	and_expr : and_expr . AND equal_expr
	xor_expr : xor_expr XOR and_expr .  (42)

	AND  shift 119
	.  reduce 42


state 200
	logical_and : logical_and LOGAND or_expr .  (38)
	or_expr : or_expr . OR xor_expr

	OR  shift 140
	.  reduce 38


state 201
	mul_expr : mul_expr STAR unary_expr .  (60)

	.  reduce 60


state 202
	mul_expr : mul_expr OVER unary_expr .  (61)

	.  reduce 61


state 203
	mul_expr : mul_expr MOD unary_expr .  (62)

	.  reduce 62


state 204
	if_stmt : IF LPAREN expr RPAREN . stmt ELSE stmt
	if_stmt : IF LPAREN expr RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 217
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 205
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	RPAREN  shift 218

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 219
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 206
	expr : expr . COMMA assign_expr
	for_stmt : FOR LPAREN SEMICOLON expr . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON expr . SEMICOLON RPAREN stmt

	SEMICOLON  shift 220
	COMMA  shift 122


state 207
	for_stmt : FOR LPAREN expr SEMICOLON . SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . expr SEMICOLON expr RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	SEMICOLON  shift 221

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 222
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 208
	do_while_stmt : DO stmt WHILE LPAREN . expr RPAREN SEMICOLON

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 223
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 209
	while_stmt : WHILE LPAREN expr RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 224
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 210
	pointer : STAR pointer .  (17)

	.  reduce 17


state 211
	unary_expr : LPAREN type_specifier RPAREN factor .  (74)

	.  reduce 74


state 212
	unary_expr : LPAREN type_specifier pointer RPAREN . factor

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	LPAREN  shift 104

	factor  goto 225


state 213
	input_stmt : INPUT SHIFTRIGHT expr SEMICOLON .  (97)

	.  reduce 97


state 214
	input_stmt : INPUT LPAREN expr RPAREN . SEMICOLON

	SEMICOLON  shift 226


state 215
	output_stmt : OUTPUT SHIFTLEFT expr SEMICOLON .  (98)

	.  reduce 98


state 216
	output_stmt : OUTPUT LPAREN expr RPAREN . SEMICOLON

	SEMICOLON  shift 227


state 217
	if_stmt : IF LPAREN expr RPAREN stmt . ELSE stmt
	if_stmt : IF LPAREN expr RPAREN stmt .  (114)

	ELSE  shift 228
	.  reduce 114


state 218
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 229
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 219
	expr : expr . COMMA assign_expr
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr . RPAREN stmt

	RPAREN  shift 230
	COMMA  shift 122


state 220
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON . RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	RPAREN  shift 231

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 232
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 221
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON . RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON . expr RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	RPAREN  shift 233

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 234
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 222
	expr : expr . COMMA assign_expr
	for_stmt : FOR LPAREN expr SEMICOLON expr . SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON expr . SEMICOLON expr RPAREN stmt

	SEMICOLON  shift 235
	COMMA  shift 122


state 223
	expr : expr . COMMA assign_expr
	do_while_stmt : DO stmt WHILE LPAREN expr . RPAREN SEMICOLON

	RPAREN  shift 236
	COMMA  shift 122


state 224
	while_stmt : WHILE LPAREN expr RPAREN stmt .  (116)

	.  reduce 116


state 225
	unary_expr : LPAREN type_specifier pointer RPAREN factor .  (75)

	.  reduce 75


state 226
	input_stmt : INPUT LPAREN expr RPAREN SEMICOLON .  (95)

	.  reduce 95


state 227
	output_stmt : OUTPUT LPAREN expr RPAREN SEMICOLON .  (96)

	.  reduce 96


state 228
	if_stmt : IF LPAREN expr RPAREN stmt ELSE . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 237
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 229
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt .  (125)

	.  reduce 125


state 230
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 238
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 231
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 239
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 232
	expr : expr . COMMA assign_expr
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr . RPAREN stmt

	RPAREN  shift 240
	COMMA  shift 122


state 233
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 241
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 234
	expr : expr . COMMA assign_expr
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr . RPAREN stmt

	RPAREN  shift 242
	COMMA  shift 122


state 235
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON . RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON . expr RPAREN stmt

	ID  shift 100
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LPAREN  shift 54
	RPAREN  shift 243

	and_expr  goto 61
	logical_or  goto 62
	expr  goto 244
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74


state 236
	do_while_stmt : DO stmt WHILE LPAREN expr RPAREN . SEMICOLON

	SEMICOLON  shift 245


state 237
	if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt .  (115)

	.  reduce 115


state 238
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt .  (124)

	.  reduce 124


state 239
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt .  (123)

	.  reduce 123


state 240
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 246
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 241
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt .  (121)

	.  reduce 121


state 242
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 247
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 243
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 248
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 244
	expr : expr . COMMA assign_expr
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr . RPAREN stmt

	RPAREN  shift 249
	COMMA  shift 122


state 245
	do_while_stmt : DO stmt WHILE LPAREN expr RPAREN SEMICOLON .  (117)

	.  reduce 117


state 246
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt .  (122)

	.  reduce 122


state 247
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt .  (120)

	.  reduce 120


state 248
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt .  (119)

	.  reduce 119


state 249
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN . stmt

	CHAR  shift 2
	INT  shift 3
	VOID  shift 4
	IF  shift 32
	CASE  shift 33
	DEFAULT  shift 34
	FOR  shift 35
	DO  shift 36
	WHILE  shift 37
	BREAK  shift 38
	CONTINUE  shift 39
	GOTO  shift 40
	RETURN  shift 41
	STATIC  shift 5
	ID  shift 42
	NUM  shift 43
	CHARCONST  shift 44
	STRCONST  shift 45
	PLUSPLUS  shift 46
	MINUSMINUS  shift 47
	NOT  shift 48
	NEG  shift 49
	STAR  shift 50
	PLUS  shift 51
	MINUS  shift 52
	AND  shift 53
	LBRACE  shift 26
	LPAREN  shift 54
	SEMICOLON  shift 55
	INPUT  shift 56
	OUTPUT  shift 57

	type_specifier  goto 58
	compound_stmt  goto 59
	var_decl_stmt  goto 60
	var_decl  goto 11
	and_expr  goto 61
	logical_or  goto 62
	expr  goto 63
	unary_expr  goto 64
	assign_expr  goto 65
	shift_expr  goto 66
	equal_expr  goto 67
	add_expr  goto 68
	or_expr  goto 69
	factor  goto 70
	compare_expr  goto 71
	xor_expr  goto 72
	logical_and  goto 73
	mul_expr  goto 74
	stmt  goto 250
	do_while_stmt  goto 76
	break_stmt  goto 77
	return_stmt  goto 78
	input_stmt  goto 79
	label_stmt  goto 80
	goto_stmt  goto 81
	continue_stmt  goto 82
	expr_stmt  goto 83
	output_stmt  goto 84
	if_stmt  goto 85
	for_stmt  goto 86
	while_stmt  goto 87


state 250
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt .  (118)

	.  reduce 118


Rules never reduced
	decl_init : assign_expr  (18)


##############################################################################
# Summary
##############################################################################

State 0 contains 5 shift-reduce conflict(s)
State 6 contains 5 shift-reduce conflict(s)
State 6 contains 1 reduce-reduce conflict(s)
State 75 contains 1 reduce-reduce conflict(s)


75 token(s), 40 nonterminal(s)
126 grammar rule(s), 251 state(s)


##############################################################################
# End of File
##############################################################################
