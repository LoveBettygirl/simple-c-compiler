#include "TreeNode.h"
#include "symbol_table.h"
#include "myparser.h"

int nodecount = 0;
int tempvarcount = 0;
int labelcount = 0;
extern unordered_map<int, char *> opmap;
extern TreeNode *root;

/* Create nodes */
TreeNode *newIDNode();
TreeNode *newTypeNode(ExpType type);
TreeNode *newStaticNode();
TreeNode *newCaseNode();
TreeNode *newDefaultNode();
TreeNode *newConstNode();
TreeNode *newVarNode();
TreeNode *newStmtNode(StmtKind kind);
TreeNode *newOpNode(int op);
TreeNode *newFuncCallNode();
TreeNode *newForceCastNode();
TreeNode *newDeclNode(DeclKind kind);
TreeNode *newPointerNode();

/* Print tree and type check */
void ShowNode(TreeNode *p);
void Display(TreeNode *p);
void Traverse(TreeNode *p);
bool checkBool(TreeNode *t);
bool illegalType(ExpType type, int pointer);
char *typeStr(TreeNode *t);
bool checkInt(TreeNode *t);
int typeCheck(TreeNode *t);
void typeError(TreeNode *t, char *errmsg);

/* Generate code */
string new_label();                    //complete
void stmt_get_label(TreeNode *t);      //complete
void expr_get_label(TreeNode *t);      //complete
void get_label();                      //complete
void recursive_get_label(TreeNode *t); //complete
void gen_code(ostream &out);           //complete
void gen_header(ostream &out);         //complete
void get_temp_var(TreeNode *t);        //complete
void gen_decl(ostream &out, TreeNode *t);
void recursive_gen_code(ostream &out, TreeNode *t); //complete
void expr_gen_code(ostream &out, TreeNode *t);
void stmt_gen_code(ostream &out, TreeNode *t); //complete

extern Symbol *newEntry(char *id);
extern Symbol *lookup_table(char *id);
extern Symbol *lookup_table(int pos);
extern Symbol *insert_table(char *id);
extern void printSymTable();

int prior[] = { 0, 4, 1, 5, 8, 2, 1, 5 };

/* ID Declaration */
TreeNode *newIDNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = IdK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Type Specifier */
TreeNode *newTypeNode(ExpType type)
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = SpciK;
		t->kind.spci = TypeK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = type;
		t->errmsg = NULL;
	}
	return t;
}

/* Static */
TreeNode *newStaticNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = StaticK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Case */
TreeNode *newCaseNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = CaseK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Default */
TreeNode *newDefaultNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = DefaultK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Const Declaration */
TreeNode *newConstNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = ConstK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

void ShowNode(TreeNode *p)
{
	if (!p)
		return;
	cout << setiosflags(ios::left) << setw(3) << p->nodeno << ": ";
	if (p->errmsg)
	{
		cerr << p->errmsg << endl;
		cout << endl;
		printSymTable();
		exit(0);
	}
	if (p->nodekind == StmtK)
	{
		if (p->kind.stmt == IfK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "if statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == WhileK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "while statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == ForK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "for statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == DoWhileK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "do-while statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == ContK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "continue statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == BreakK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "break statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == RetK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "return statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == CompK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "compound statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == GotoK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "goto statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == InputK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "input statement,"
				<< setw(25) << buf << "Children: ";
		}
		else if (p->kind.stmt == OutputK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "output statement,"
				<< setw(25) << buf << "Children: ";
		}
	}
	else if (p->nodekind == ExpK)
	{
		if (p->kind.exp == OpK)
		{
			char *opstr = opmap[p->attr.op];
			char buf1[50], buf2[50];
			sprintf(buf1, "op: %s,", opstr);
			sprintf(buf2, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "Expr," << setw(25) << buf1 << setw(25) << buf2 << "Children: ";
		}
		else if (p->kind.exp == IdK)
		{
			char buf1[50], buf2[50];
			sprintf(buf1, "symbol: %s,", p->attr.idname);
			sprintf(buf2, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "ID Declaration," << setw(25) << buf1 << setw(25) << buf2 << "Children: ";
		}
		else if (p->kind.exp == ConstK)
		{
			if (p->type == Integer)
			{
				char buf1[50], buf2[50];
				sprintf(buf1, "value: %d,", p->attr.intval);
				sprintf(buf2, "type: %s,", typeStr(p));
				cout << setiosflags(ios::left) << setw(25) << "Const Declaration,"
					<< setw(25) << buf1 << setw(25) << buf2 << "Children: ";
			}
			else if (p->type == Char)
			{
				char buf1[50], buf2[50];
				sprintf(buf1, "value: %d,", int(p->attr.charval));
				sprintf(buf2, "type: %s,", typeStr(p));
				cout << setiosflags(ios::left) << setw(25) << "Const Declaration,"
					<< setw(25) << buf1 << setw(25) << buf2 << "Children: ";
			}
			else if (p->type == Double)
			{
				char buf1[50], buf2[50];
				sprintf(buf1, "value: %g,", p->attr.douval);
				sprintf(buf2, "type: %s,", typeStr(p));
				cout << setiosflags(ios::left) << setw(25) << "Const Declaration,"
					<< setw(25) << buf1 << setw(25) << buf2 << "Children: ";
			}
			else if (p->type == Float)
			{
				char buf1[50], buf2[50];
				sprintf(buf1, "value: %gf,", p->attr.floatval);
				sprintf(buf2, "type: %s,", typeStr(p));
				cout << setiosflags(ios::left) << setw(25) << "Const Declaration,"
					<< setw(25) << buf1 << setw(25) << buf2 << "Children: ";
			}
			else if (p->type == Str)
			{
				char buf1[50], buf2[50];
				sprintf(buf1, "value: %s,", p->attr.strval);
				sprintf(buf2, "type: %s,", typeStr(p));
				cout << setiosflags(ios::left) << setw(25) << "Const Declaration,"
					<< setw(25) << buf1 << setw(25) << buf2 << "Children: ";
			}
			else if (p->type == Short)
			{
				char buf1[50], buf2[50];
				sprintf(buf1, "value: %d,", p->attr.shortval);
				sprintf(buf2, "type: %s,", typeStr(p));
				cout << setiosflags(ios::left) << setw(25) << "Const Declaration,"
					<< setw(25) << buf1 << setw(25) << buf2 << "Children: ";
			}
		}
		else if (p->kind.exp == FunccK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "Func call,"
				<< setw(25) << buf
				<< "Children: ";
		}
		else if (p->kind.exp == CastK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << p->nodeno << setw(25) << "Force cast,"
				<< setw(25) << buf
				<< "Children: ";
		}
	}
	else if (p->nodekind == DeclK)
	{
		if (p->kind.decl == VarK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "Var Declaration,"
				<< setw(25) << buf
				<< "Children: ";
		}
		else if (p->kind.decl == FuncK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "Func Declaration,"
				<< setw(25) << buf
				<< "Children: ";
		}
	}
	else if (p->nodekind == FuncDefK)
	{
		char buf[50];
		sprintf(buf, "type: %s,", typeStr(p));
		cout << setiosflags(ios::left) << setw(25) << "Func Definition,"
			<< setw(25) << buf
			<< "Children: ";
	}
	else if (p->nodekind == SpciK)
	{
		if (p->kind.spci == TypeK)
		{
			char buf[50];
			sprintf(buf, "type: %s,", typeStr(p));
			cout << setiosflags(ios::left) << setw(25) << "Type Specifier,"
				<< setw(25) << buf
				<< "Children: ";
		}
		else if (p->kind.spci == StructK)
		{
			cout << setiosflags(ios::left) << setw(25) << "Struct Specifier,"
				<< "Children: ";
		}
		else if (p->kind.spci == UnionK)
		{
			cout << setiosflags(ios::left) << setw(25) << "Union Specifier,"
				<< "Children: ";
		}
	}
	else if (p->nodekind == InitK)
	{
		cout << setiosflags(ios::left) << setw(25) << "Initializer,"
			<< "Children: ";
	}
	else if (p->nodekind == PointK)
	{
		char buf[50];
		sprintf(buf, "dim: %d,", p->pointer);
		cout << setiosflags(ios::left) << setw(25) << "Pointer," << setw(25) << buf << "Children: ";
	}
	/*else if(p->nodekind==ArrayK)
	{
	char buf[50];
	sprintf(buf, "dim: %d,", p->arraydim);
	cout << setiosflags(ios::left) << setw(25) << "Array,"<<setw(25)<<buf<<"Children: ";
	}*/
	else if (p->nodekind == StaticK)
	{
		char buf[50];
		sprintf(buf, "type: %s,", typeStr(p));
		cout << setiosflags(ios::left) << setw(25) << "Static,"
			<< setw(25) << buf
			<< "Children: ";
	}
	else if (p->nodekind == VardK)
	{
		char buf[50];
		sprintf(buf, "type: %s,", typeStr(p));
		cout << setiosflags(ios::left) << setw(25) << "Var,"
			<< setw(25) << buf
			<< "Children: ";
	}
	else if (p->nodekind == ParamK)
	{
		char buf[50];
		sprintf(buf, "type: %s,", typeStr(p));
		cout << setiosflags(ios::left) << setw(25) << "Param,"
			<< setw(25) << buf
			<< "Children: ";
	}
	else if (p->nodekind == CaseK)
	{
		char buf[50];
		sprintf(buf, "type: %s,", typeStr(p));
		cout << setiosflags(ios::left) << setw(25) << "Case,"
			<< setw(25) << buf
			<< "Children: ";
	}
	else if (p->nodekind == DefaultK)
	{
		char buf[50];
		sprintf(buf, "type: %s,", typeStr(p));
		cout << setiosflags(ios::left) << setw(25) << "Default,"
			<< setw(25) << buf
			<< "Children: ";
	}

	for (int i = 0; i < MAXCHILDREN; i++)
	{
		if (p->child[i])
		{
			cout << p->child[i]->nodeno << " ";
			TreeNode *temp = p->child[i]->sibling;
			while (temp)
			{
				cout << temp->nodeno << " ";
				temp = temp->sibling;
			}
		}
	}
	cout << endl;
}

/* Display the tree */
void Display(TreeNode *p)
{
	if (!p)
		return;
	TreeNode *temp;
	for (int i = 0; i < MAXCHILDREN; i++)
	{
		if (p->child[i])
		{
			Display(p->child[i]);
		}
	}
	ShowNode(p);
	temp = p->sibling;
	if (temp)
	{
		Display(temp);
	}
	return;
}

/* Display the tree */
void Traverse(TreeNode *p)
{
	if (!p)
		return;
	TreeNode *temp;
	for (int i = 0; i < MAXCHILDREN; i++)
	{
		if (p->child[i])
		{
			Traverse(p->child[i]);
		}
	}
	typeCheck(p);
	get_temp_var(p);
	//get_temp_var(p);
	temp = p->sibling;
	if (temp)
	{
		Traverse(temp);
	}
	return;
}

/* Struct or union */
/*TreeNode *newStructUnionNode(SpciKind kind)
{
TreeNode * t = new TreeNode;
int i;
if (t==NULL)
printf("Out of memory error at line %d\n",nodecount);
else {
for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;//initialize child node
t->sibling = NULL;//initialize sibling node
t->nodekind = SpciK;
t->kind.spci = kind;
t->nodeno = nodecount++;
}
return t;
}*/

/* Var */
TreeNode *newVarNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL; //initialize child node
		t->sibling = NULL;      //initialize sibling node
		t->nodekind = VardK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Param */
/*TreeNode *newParamNode()
{
TreeNode * t = new TreeNode;
int i;
if (t==NULL)
printf("Out of memory error at line %d\n",nodecount);
else {
for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;//initialize child node
t->sibling = NULL;//initialize sibling node
t->nodekind = ParamK;
t->nodeno = nodecount++;
}
return t;
}*/

/* xxx statement */
TreeNode *newStmtNode(StmtKind kind)
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL; //initialize child node
		t->sibling = NULL;      //initialize sibling node
		t->nodekind = StmtK;
		t->kind.stmt = kind;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Expr */
TreeNode *newOpNode(int op)
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = OpK;
		t->attr.op = op;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
		//get_temp_var(t);
	}
	return t;
}

/* Func Define */
/*TreeNode *newFuncDefNode()
{
TreeNode * t = new TreeNode;
int i;
if (t==NULL)
printf("Out of memory error at line %d\n",nodecount);
else {
for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;//initialize child node
t->sibling = NULL;//initialize sibling node
t->nodekind = FuncDefK;
t->nodeno = nodecount++;
}
return t;
}*/

/* Function call */
TreeNode *newFuncCallNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = FunccK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Force cast */
TreeNode *newForceCastNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = CastK;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Declaration */
TreeNode *newDeclNode(DeclKind kind)
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = DeclK;
		t->kind.decl = kind;
		t->nodeno = nodecount++;
		t->pointer = 0;
		t->type = Void;
		t->errmsg = NULL;
	}
	return t;
}

/* Pointer */
TreeNode *newPointerNode()
{
	TreeNode *t = new TreeNode;
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", nodecount);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = PointK;
		t->nodeno = nodecount++;
		t->type = Void;
		t->pointer = 0;
		t->pointer = 1;
		t->errmsg = NULL;
	}
	return t;
}

/* Array */
/*TreeNode *newArrayNode()
{
TreeNode * t = new TreeNode;
int i;
if (t==NULL)
printf("Out of memory error at line %d\n",nodecount);
else {
for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
t->sibling = NULL;
t->nodekind = ArrayK;
t->nodeno = nodecount++;
t->type = Void;
t->pointer = 0;
t->arraylow = 0;
t->arrayhigh = 0;
}
return t;
}*/

/* initializer */
/*TreeNode *newInitNode()
{
TreeNode * t = new TreeNode;
int i;
if (t==NULL)
printf("Out of memory error at line %d\n",nodecount);
else {
for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;//initialize child node
t->sibling = NULL;//initialize sibling node
t->nodekind = InitK;
t->nodeno = nodecount++;
}
return t;
}*/

bool checkBool(TreeNode *t)
{
	if (!t)
		return false;
	if (t->nodekind != ExpK)
		return false;
	return true;
}

bool illegalType(TreeNode *t)
{
	if (!t)
		return true;
	if (t->type == Void && t->pointer == 0)
		return true;
	return false;
}

bool illegalType(ExpType type, int pointer)
{
	if (type == Void && pointer == 0)
		return true;
	return false;
}

char *typeStr(TreeNode *t)
{
	string temp;
	if (t->type == Void)
	{
		temp = "void";
	}
	else if (t->type == Integer)
	{
		temp = "int";
	}
	else if (t->type == Char)
	{
		temp = "char";
	}
	else if (t->type == Float)
	{
		temp = "float";
	}
	else if (t->type == Double)
	{
		temp = "double";
	}
	else if (t->type == Short)
	{
		temp = "short";
	}
	else if (t->type == Boolean)
	{
		return "bool";
	}
	else if (t->type == Str)
	{
		return "char*";
	}
	for (int i = 0; i < t->pointer; i++)
	{
		temp += "*";
	}
	char *p = new char[temp.length() + 1];
	strcpy(p, temp.c_str());
	return p;
}

bool checkInt(TreeNode *t)
{
	if (t->pointer > 0)
		return false;
	if (t->type != Integer && t->type != Char && t->type != Boolean)
	{
		return false;
	}
	return true;
}

int typeCheck(TreeNode *t)
{
	if (t->nodekind == StmtK)
	{
		if (t->kind.stmt == IfK || t->kind.stmt == WhileK)
		{
			if (t->child[0]->type != Boolean)
			{
				char *errmsg = new char[100];
				if (t->kind.stmt == IfK)
				{
					sprintf(errmsg, "The type of if statement test is not boolean, at node: %d", t->child[0]->nodeno);
				}
				else if (t->kind.stmt == WhileK)
				{
					sprintf(errmsg, "The type of while statement test is not boolean, at node: %d", t->child[0]->nodeno);
				}
				typeError(t, errmsg);
				return -1;
			}
			/*else
			{
			if (t->child[0]->type != Boolean)
			{
			if (t->child[0]->type == Integer && t->child[0]->kind.exp == ConstK)
			{
			int temp = t->child[0]->attr.intval;
			t->child[0]->boolval = (bool)temp;
			}
			else if (t->child[0]->type == Char && t->child[0]->kind.exp == ConstK)
			{
			char temp = t->child[0]->attr.charval;
			t->child[0]->boolval = (bool)temp;
			}
			t->child[0]->type = Boolean;
			}
			}*/
		}
		else if (t->kind.stmt == DoWhileK)
		{
			if (t->child[1]->type != Boolean)
			{
				char *errmsg = new char[100];
				sprintf(errmsg, "The type of do-while statement test is not boolean, at node: %d", t->child[1]->nodeno);
				typeError(t, errmsg);
				return -1;
			}
			/*else
			{
			if (t->child[1]->type != Boolean)
			{
			if (t->child[1]->type == Integer && t->child[1]->kind.exp == ConstK)
			{
			int temp = t->child[1]->attr.intval;
			t->child[1]->boolval = (bool)temp;
			}
			else if (t->child[1]->type == Char && t->child[1]->kind.exp == ConstK)
			{
			char temp = t->child[1]->attr.charval;
			t->child[1]->boolval = (bool)temp;
			}
			t->child[1]->type = Boolean;
			}
			}*/
		}
		else if (t->kind.stmt == ForK)
		{
			if (t->child[1] && t->child[1]->type != Boolean)
			{
				char *errmsg = new char[100];
				sprintf(errmsg, "The type of for statement test is not boolean, at node: %d", t->child[1]->nodeno);
				typeError(t, errmsg);
				return -1;
			}
			/*else if (t->child[1])
			{
			if (t->child[1]->type != Boolean)
			{
			if (t->child[1]->type == Integer && t->child[1]->kind.exp == ConstK)
			{
			int temp = t->child[1]->attr.intval;
			t->child[1]->boolval = (bool)temp;
			}
			else if (t->child[1]->type == Char && t->child[1]->kind.exp == ConstK)
			{
			char temp = t->child[1]->attr.charval;
			t->child[1]->boolval = (bool)temp;
			}
			t->child[1]->type = Boolean;
			}
			}*/
		}
		else if (t->kind.stmt == OutputK)
		{
			/*if (!checkInt(t->child[0]))
			{
			char *errmsg = new char[100];
			sprintf(errmsg, "The type '%s' is not supported to declare at node: %d", typeStr(t->child[0]),t->child[0]->nodeno);
			typeError(t, errmsg);
			return -1;
			}
			if (t->child[0]->type == Boolean)
			{
			if (t->child[0]->kind.exp == ConstK)
			{
			bool temp = t->child[0]->boolval;
			t->child[0]->attr.intval = (int)temp;
			}
			t->child[0]->type = Integer;
			}*/
			if (t->child[0]->type != Integer && t->child[0]->type != Char)
			{
				char *errmsg = new char[100];
				sprintf(errmsg, "The output type of output statement is %s, at node: %d", typeStr(t->child[0]), t->child[0]->nodeno);
				typeError(t, errmsg);
				return -1;
			}
		}
		else if (t->kind.stmt == InputK)
		{
			if (t->child[0]->nodekind == ExpK && t->child[0]->kind.exp == IdK)
			{
				Symbol *sym = lookup_table(t->child[0]->attr.idname);
				if (sym)
				{
					sym->isinited = true;
				}
			}
			else
			{
				char *errmsg = new char[100];
				sprintf(errmsg, "lvalue required as input statement, at node: %d", t->child[0]->nodeno);
				typeError(t, errmsg);
				return -1;
			}
		}
	}

	if (t->nodekind == DeclK)
	{
		ExpType type;
		TreeNode *tt;
		if (t->kind.decl == VarK)
		{
			if (t->child[0]->nodekind == StaticK)
			{
				type = t->child[1]->type;
				tt = t->child[2];
				while (tt != NULL)
				{
					if (tt->nodekind == VardK)
					{
						if (tt->child[1]->type != t->type)
						{
							char *errmsg = new char[100];
							sprintf(errmsg, "Initialization type '%s' is not consistent to declaration type '%s', at node: %d", typeStr(tt->child[1]), typeStr(t), tt->child[1]->nodeno);
							typeError(t, errmsg);
							return -1;
						}
						else
						{
							tt->type = t->type;
							Symbol *sym = lookup_table(tt->child[0]->attr.idname);
							if (sym)
							{
								sym->isinited = true;
							}
						}
						/*tt->type = type;
						for (int i = MAXCHILDREN - 1; i >= 0; i--)
						{
						if (tt->child[i])
						{
						if ((i == 2 || i == 3) && (tt->child[i]->type != type))
						{
						if (!checkInt(tt->child[i]))
						{
						char *errmsg = new char[100];
						sprintf(errmsg, "The type '%s' is not supported to declare", typeStr(tt->child[i]));
						typeError(t, errmsg);
						return -1;
						}
						if (type == Integer)
						{
						if (tt->child[i]->type == Char)
						{
						if (tt->child[i]->kind.exp == ConstK)
						{
						char temp = tt->child[i]->attr.charval;
						tt->child[i]->attr.intval = (int)temp;
						}
						}
						else if (tt->child[i]->type = Boolean)
						{
						if (tt->child[i]->kind.exp == ConstK)
						{
						bool temp = tt->child[i]->boolval;
						tt->child[i]->attr.intval = (int)temp;
						}
						}
						}
						else if (type == Char)
						{
						if (tt->child[i]->type == Integer)
						{
						int temp = tt->child[i]->attr.intval;
						tt->child[i]->attr.charval = (char)temp;
						}
						else if (tt->child[i]->type = Boolean)
						{
						bool temp = tt->child[i]->boolval;
						tt->child[i]->attr.charval = (char)temp;
						}
						}
						}
						break;
						}
						}*/
					}
					tt = tt->sibling;
				}
			}
			else
			{
				type = t->child[0]->type;
				tt = t->child[1];
				while (tt != NULL)
				{
					if (tt->nodekind == VardK)
					{
						if (tt->child[1]->type != t->type)
						{
							char *errmsg = new char[100];
							sprintf(errmsg, "Initialization type '%s' is not consistent to declaration type '%s', at node: %d", typeStr(tt->child[1]), typeStr(t), tt->child[1]->nodeno);
							typeError(t, errmsg);
							return -1;
						}
						else
						{
							tt->type = t->type;
						}

						/*tt->type = type;
						for (int i = MAXCHILDREN - 1; i >= 0; i--)
						{
						if (tt->child[i])
						{
						if ((i == 2 || i == 3) && (tt->child[i]->type != type))
						{
						if (!checkInt(tt->child[i]))
						{
						char *errmsg = new char[100];
						sprintf(errmsg, "The type '%s' is not supported to declare", typeStr(tt->child[i]));
						typeError(t, errmsg);
						return -1;
						}
						if (type == Integer)
						{
						if (tt->child[i]->type == Char)
						{
						if (tt->child[i]->kind.exp == ConstK)
						{
						char temp = tt->child[i]->attr.charval;
						tt->child[i]->attr.intval = (int)temp;
						}
						}
						else if (tt->child[i]->type = Boolean)
						{
						if (tt->child[i]->kind.exp == ConstK)
						{
						bool temp = tt->child[i]->boolval;
						tt->child[i]->attr.intval = (int)temp;
						}
						}
						}
						else if (type == Char)
						{
						if (tt->child[i]->type == Integer)
						{
						int temp = tt->child[i]->attr.intval;
						tt->child[i]->attr.charval = (char)temp;
						}
						else if (tt->child[i]->type = Boolean)
						{
						bool temp = tt->child[i]->boolval;
						tt->child[i]->attr.charval = (char)temp;
						}
						}
						}
						break;
						}
						}*/
					}
					tt = tt->sibling;
				}
			}
		}
	}

	if (t->nodekind == ExpK)
	{
		if (t->kind.exp == IdK)
		{
			Symbol *sym = lookup_table(t->attr.idname);
			if (!sym->decled)
			{
				char *errmsg = new char[100];
				sprintf(errmsg, "'%s' was not declared in this scope", t->attr.idname);
				typeError(t, errmsg);
				return -1;
			}
			if (illegalType(sym->base_type, sym->pointer))
			{
				//variable or field 'v' declared void
				char *errmsg = new char[100];
				sprintf(errmsg, "Variable or field '%s' declared void", t->attr.idname);
				typeError(t, errmsg);
				return -1;
			}
			t->type = sym->base_type;
			t->pointer = sym->pointer;
			/*if (sym->redecl)
			{
			char *errmsg = new char[100];
			sprintf("Redeclaration of '%s'", t->addr.idname);
			typeError(t, errmsg);
			return -1;
			}*/
		}

		if (t->kind.exp == OpK)
		{
			switch (t->attr.op)
			{
			case PLUS:
			case MINUS:
			case MUL:
			case OVER:
			case MOD:
			case SHIFTLEFT:
			case SHIFTRIGHT:
			case AND:
			case OR:
			case XOR:
				if (t->child[0]->type != t->child[1]->type)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				else
				{
					t->type = t->child[0]->type;
				}
				if (t->child[0]->type != Integer && t->child[0]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[1]->type != Integer && t->child[1]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				for (int i = 0; i < MAXCHILDREN; i++)
				{
					if (t->child[i] == NULL)
						continue;
					if (t->child[i]->nodekind == ExpK && t->child[i]->kind.exp == IdK)
					{
						Symbol *sym = lookup_table(t->child[i]->attr.idname);
						if (sym)
						{
							if (!sym->isinited)
							{
								char *errmsg = new char[100];
								sprintf(errmsg, "The variable '%s' is used before initialized, at node: %d", t->child[i]->attr.idname, t->child[i]->nodeno);
								typeError(t, errmsg);
								return -1;
							}
						}
					}
				}
				return 0;
				/*int pr0, pr1;
				t->type = pr0 > pr1 ? t->child[0]->type : t->child[1]->type; //force cast
				if (!checkInt(t->child[0]) || !checkInt(t->child[1]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s'", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}
				if (pr0 == pr1)
				{
				t->child[0]->type = t->child[1]->type = t->type;
				}
				else
				{
				if (pr0 > pr1)
				{
				if (t->child[0]->type == Integer && t->child[1]->type == Char)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				char temp = t->child[1]->attr.charval;
				t->child[1]->attr.intval = (int)temp;
				}
				t->child[1]->type = Integer;
				}
				else if (t->child[0]->type == Integer && t->child[1]->type == Boolean)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[1]->attr.intval = (int)temp;
				}
				t->child[1]->type = Integer;
				}
				else if (t->child[0]->type == Char && t->child[1]->type == Boolean)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[1]->attr.charval = (char)temp;
				}
				t->child[1]->type = Char;
				}
				}
				else
				{
				if (t->child[1]->type == Integer && t->child[0]->type == Char)
				{
				if (t->child[0]->kind.exp == ConstK)
				{
				char temp = t->child[0]->attr.charval;
				t->child[0]->attr.intval = (int)temp;
				}
				t->child[0]->type = Integer;
				}
				else if (t->child[1]->type == Integer && t->child[0]->type == Boolean)
				{
				if (t->child[0]->kind.exp == ConstK)
				{
				bool temp = t->child[0]->boolval;
				t->child[0]->attr.intval = (int)temp;
				}
				t->child[0]->type = Integer;
				}
				else if (t->child[1]->type == Char && t->child[0]->type == Boolean)
				{
				if (t->child[0]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[0]->attr.charval = (char)temp;
				}
				t->child[0]->type = Char;
				}
				}
				}
				return 0;*/

			case SMALL:
			case GREAT:
			case GREEQU:
			case SMAEQU:
			case EQUAL:
			case NOTEQUAL:
				t->type = Boolean;
				if (t->child[0]->type != t->child[1]->type)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[0]->type != Integer && t->child[0]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[1]->type != Integer && t->child[1]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				for (int i = 0; i < MAXCHILDREN; i++)
				{
					if (t->child[i] == NULL)
						continue;
					if (t->child[i]->nodekind == ExpK && t->child[i]->kind.exp == IdK)
					{
						Symbol *sym = lookup_table(t->child[i]->attr.idname);
						if (sym)
						{
							if (!sym->isinited)
							{
								char *errmsg = new char[100];
								sprintf(errmsg, "The variable '%s' is used before initialized, at node: %d", t->child[i]->attr.idname, t->child[i]->nodeno);
								typeError(t, errmsg);
								return -1;
							}
						}
					}
				}
				return 0;
				//int pr0, pr1;
				/*t->type = pr0 > pr1 ? t->child[0]->type : t->child[1]->type; //force cast
				if (!checkInt(t->child[0]) || !checkInt(t->child[1]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s'", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}
				if (pr0 == pr1)
				{
				t->child[0]->type = t->child[1]->type = t->type;
				}
				else
				{
				if (pr0 > pr1)
				{
				if (t->child[0]->type == Integer && t->child[1]->type == Char)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				char temp = t->child[1]->attr.charval;
				t->child[1]->attr.intval = (int)temp;
				}
				t->child[1]->type = Integer;
				}
				else if (t->child[0]->type == Integer && t->child[1]->type == Boolean)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[1]->attr.intval = (int)temp;
				}
				t->child[1]->type = Integer;
				}
				else if (t->child[0]->type == Char && t->child[1]->type == Boolean)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[1]->attr.charval = (char)temp;
				}
				t->child[1]->type = Char;
				}
				}
				else
				{
				if (t->child[1]->type == Integer && t->child[0]->type == Char)
				{
				if (t->child[0]->kind.exp == ConstK)
				{
				char temp = t->child[0]->attr.charval;
				t->child[0]->attr.intval = (int)temp;
				}
				t->child[0]->type = Integer;
				}
				else if (t->child[1]->type == Integer && t->child[0]->type == Boolean)
				{
				if (t->child[0]->kind.exp == ConstK)
				{
				bool temp = t->child[0]->boolval;
				t->child[0]->attr.intval = (int)temp;
				}
				t->child[0]->type = Integer;
				}
				else if (t->child[1]->type == Char && t->child[0]->type == Boolean)
				{
				if (t->child[0]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[0]->attr.charval = (char)temp;
				}
				t->child[0]->type = Char;
				}
				}
				}
				t->type = Boolean;
				return 0;*/

				//complete
			case LOGOR:
			case LOGAND:
				t->type = Boolean;
				if (t->child[0]->type != Boolean || t->child[1]->type != Boolean)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				for (int i = 0; i < MAXCHILDREN; i++)
				{
					if (t->child[i] == NULL)
						continue;
					if (t->child[i]->nodekind == ExpK && t->child[i]->kind.exp == IdK)
					{
						Symbol *sym = lookup_table(t->child[i]->attr.idname);
						if (sym)
						{
							if (!sym->isinited)
							{
								char *errmsg = new char[100];
								sprintf(errmsg, "The variable '%s' is used before initialized, at node: %d", t->child[i]->attr.idname, t->child[i]->nodeno);
								typeError(t, errmsg);
								return -1;
							}
						}
					}
				}
				return 0;
				/*if (!checkInt(t->child[0]) || !checkInt(t->child[1]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s'", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}
				if (t->child[0]->type != Boolean)
				{
				if (t->child[0]->type == Integer && t->child[0]->kind.exp == ConstK)
				{
				int temp = t->child[0]->attr.intval;
				t->child[0]->boolval = (bool)temp;
				}
				else if (t->child[0]->type == Char && t->child[0]->kind.exp == ConstK)
				{
				char temp = t->child[0]->attr.charval;
				t->child[0]->boolval = (bool)temp;
				}
				t->child[0]->type = Boolean;
				}
				if (t->child[1]->type != Boolean)
				{
				if (t->child[1]->type == Integer && t->child[1]->kind.exp == ConstK)
				{
				int temp = t->child[1]->attr.intval;
				t->child[1]->boolval = (bool)temp;
				}
				else if (t->child[1]->type == Char && t->child[1]->kind.exp == ConstK)
				{
				char temp = t->child[1]->attr.charval;
				t->child[1]->boolval = (bool)temp;
				}
				t->child[1]->type = Boolean;
				}
				//t->pointer = 0;
				return 0;*/

				//complete
			case NOT:
				t->type = Boolean;
				if (t->child[0]->type != Boolean)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s', at node: %d", typeStr(t->child[0]), opmap[t->attr.op], t->child[0]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[0]->nodekind == ExpK && t->child[0]->kind.exp == IdK)
				{
					Symbol *sym = lookup_table(t->child[0]->attr.idname);
					if (sym)
					{
						if (!sym->isinited)
						{
							char *errmsg = new char[100];
							sprintf(errmsg, "The variable '%s' is used before initialized, at node: %d", t->child[0]->attr.idname, t->child[0]->nodeno);
							typeError(t, errmsg);
							return -1;
						}
					}
				}
				return 0;
				/*if (!checkInt(t->child[0]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s'", typeStr(t->child[0]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}
				if (t->child[0]->type != Boolean)
				{
				if (t->child[0]->type == Integer && t->child[0]->kind.exp == ConstK)
				{
				int temp = t->child[0]->attr.intval;
				t->child[0]->boolval = (bool)temp;
				}
				else if (t->child[0]->type == Char && t->child[0]->kind.exp == ConstK)
				{
				char temp = t->child[0]->attr.charval;
				t->child[0]->boolval = (bool)temp;
				}
				t->child[0]->type = Boolean;
				}
				return 0;*/

				//complete
			case ASSIGN:
				t->type = t->child[0]->type;
				if (t->child[0]->type != t->child[1]->type)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[0]->type != Integer && t->child[0]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[1]->type != Integer && t->child[1]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s', at node: %d %d", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op], t->child[0]->nodeno, t->child[1]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[0]->nodekind == ExpK && t->child[0]->kind.exp == IdK)
				{
					Symbol *sym = lookup_table(t->child[0]->attr.idname);
					if (sym)
					{
						sym->isinited = true;
					}
				}
				else
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "lvalue required as left operand of assignment");
					typeError(t, errmsg);
					return -1;
				}
				return 0;
				/*if (!checkInt(t->child[0]) || !checkInt(t->child[1]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' and '%s' to binary 'operator%s'", typeStr(t->child[0]), typeStr(t->child[1]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}
				if (t->child[0]->nodekind == ExpK && t->child[0]->kind.exp == IdK)
				{
				}
				else
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "lvalue required as left operand of assignment");
				typeError(t, errmsg);
				return -1;
				}
				if (t->child[0]->type != t->child[1]->type)
				{
				if (t->child[0]->type == Integer)
				{
				if (t->child[1]->type == Char)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				char temp = t->child[1]->attr.charval;
				t->child[1]->attr.intval = (int)temp;
				}
				}
				else if (t->child[1]->type == Boolean)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[1]->attr.intval = (int)temp;
				}
				}
				t->child[1]->type = Integer;
				}
				else if (t->child[0]->type == Char)
				{
				if (t->child[1]->type == Integer)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				int temp = t->child[1]->attr.intval;
				t->child[1]->attr.charval = (char)temp;
				}
				}
				else if (t->child[1]->type == Boolean)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				bool temp = t->child[1]->boolval;
				t->child[1]->attr.charval = (char)temp;
				}
				}
				t->child[1]->type = Char;
				}
				else if (t->child[0]->type == Boolean)
				{
				if (t->child[1]->type == Integer)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				int temp = t->child[1]->attr.intval;
				t->child[1]->boolval = (bool)temp;
				}
				}
				else if (t->child[1]->type == Char)
				{
				if (t->child[1]->kind.exp == ConstK)
				{
				char temp = t->child[1]->attr.charval;
				t->child[1]->boolval = (bool)temp;
				}
				}
				t->child[1]->type = Boolean;
				}
				}
				return 0;*/

			case PLUSU:
			case MINUSU:
				if (t->child[0]->type != Integer && t->child[0]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s', at node: %d", typeStr(t->child[0]), opmap[t->attr.op], t->child[0]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				if (t->child[0]->nodekind == ExpK && t->child[0]->kind.exp == IdK)
				{
					Symbol *sym = lookup_table(t->child[0]->attr.idname);
					if (sym)
					{
						if (!sym->isinited)
						{
							char *errmsg = new char[100];
							sprintf(errmsg, "The variable '%s' is used before initialized, at node: %d", t->child[0]->attr.idname, t->child[0]->nodeno);
							typeError(t, errmsg);
							return -1;
						}
					}
				}
				/*if (!checkInt(t->child[0]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s'", typeStr(t->child[0]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}
				t->type = t->child[0]->type; //force cast
				return 0;*/

			case PLUSPLUSL:
			case PLUSPLUSR:
			case MINUSMINUSL:
			case MINUSMINUSR:
				if (t->child[0]->type != Integer && t->child[0]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s', at node: %d", typeStr(t->child[0]), opmap[t->attr.op], t->child[0]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				/*if (!checkInt(t->child[0]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s'", typeStr(t->child[0]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}*/
				if (t->child[0]->nodekind == ExpK && t->child[0]->kind.exp == IdK)
				{
					Symbol *sym = lookup_table(t->child[0]->attr.idname);
					if (sym)
					{
						if (!sym->isinited)
						{
							char *errmsg = new char[100];
							sprintf(errmsg, "The variable '%s' is used before initialized, at node: %d", t->child[0]->attr.idname, t->child[0]->nodeno);
							typeError(t, errmsg);
							return -1;
						}
					}
				}
				else
				{
					char *errmsg = new char[100];
					if (t->attr.op == PLUSPLUSL || t->attr.op == PLUSPLUSR)
					{
						sprintf(errmsg, "lvalue required as increment operand");
						typeError(t, errmsg);
						return -1;
					}
					else
					{
						sprintf(errmsg, "lvalue required as decrement operand");
						typeError(t, errmsg);
						return -1;
					}
				}
				t->type = t->child[0]->type; //force cast
				return 0;

			case NEG:
				if (t->child[0]->type != Integer && t->child[0]->type != Char)
				{
					char *errmsg = new char[100];
					sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s', at node: %d", typeStr(t->child[0]), opmap[t->attr.op], t->child[0]->nodeno);
					typeError(t, errmsg);
					return -1;
				}
				/*if (!checkInt(t->child[0]))
				{
				char *errmsg = new char[100];
				sprintf(errmsg, "Invalid operands of types '%s' to binary 'operator%s'", typeStr(t->child[0]), opmap[t->attr.op]);
				typeError(t, errmsg);
				return -1;
				}*/
				if (t->child[0]->nodekind == ExpK && t->child[0]->kind.exp == IdK)
				{
					Symbol *sym = lookup_table(t->child[0]->attr.idname);
					if (sym)
					{
						if (!sym->isinited)
						{
							char *errmsg = new char[100];
							sprintf(errmsg, "The variable '%s' is used before initialized, at node: %d", t->child[0]->attr.idname, t->child[0]->nodeno);
							typeError(t, errmsg);
							return -1;
						}
					}
				}
				t->type = t->child[0]->type; //force cast
				return 0;
			}
		}

		if (t->kind.exp == CastK)
		{
			if (illegalType(t->type, t->pointer))
			{
				char *errmsg = new char[100];
				sprintf(errmsg, "Illegal destination cast type: void");
				typeError(t, errmsg);
				return -1;
			}
			return 0;
		}
	}
	return 0;
}

void typeError(TreeNode *t, char *errmsg)
{
	t->errmsg = errmsg;
}

string new_label()
{
	char buf[50];
	sprintf(buf, "L%d", labelcount++);
	string temp(buf);
	return temp;
}

void stmt_get_label(TreeNode *t)
{
	if (!t)
		return;
	if (t->nodekind != StmtK)
		return;
	switch (t->kind.stmt)
	{
	case WhileK:
	{
		TreeNode *e = t->child[0]; //Boolean expr
		TreeNode *s = t->child[1]; //while

		if (t->label.begin_label == "")
		{
			t->label.begin_label = new_label();
		}

		s->label.next_label = t->label.begin_label;
		//循环体的下一条语句的标签是while语句开始的标签，因为每次循环体执行完之后都要先判断一下条件

		s->label.begin_label = e->label.true_label = new_label();
		if (t->label.next_label == "") //一定要保证label的有序性
		{
			t->label.next_label = new_label();
		}

		e->label.false_label = t->label.next_label;
		//如果判断条件为假，则跳转出循环体，执行while语句的下一条语句

		if (t->sibling)
		{
			t->sibling->label.begin_label = t->label.next_label;
		}

		//递归地生成expr中嵌套bool表达式的标签，以及while循环体内部语句的标签
		if (e)
		{
			recursive_get_label(e);
		}
		if (s)
		{
			recursive_get_label(s);
		}
	}
	break;

	case DoWhileK:
	{
		TreeNode *s = t->child[0]; //while
		TreeNode *e = t->child[1]; //Boolean expr

		if (t->label.begin_label == "")
		{
			t->label.begin_label = new_label();
		}

		e->label.true_label = t->label.begin_label;
		if (t->label.next_label == "")
		{
			t->label.next_label = new_label();
		}

		e->label.false_label = t->label.next_label;

		if (t->sibling)
		{
			t->sibling->label.begin_label = t->label.next_label;
		}

		if (s)
		{
			recursive_get_label(s);
		}
		if (e)
		{
			recursive_get_label(e);
		}
	}
	break;

	case IfK:
	{
		TreeNode *e = t->child[0];  //Boolean expr
		TreeNode *s1 = t->child[1]; //if
		TreeNode *s2 = t->child[2]; //else

		e->label.true_label = new_label();
		s1->label.begin_label = e->label.true_label;

		if (s2) //如果该if语句有匹配的else（标签对应假值标签）
		{
			e->label.false_label = new_label();
		}

		if (t->label.next_label == "")
		{
			t->label.next_label = new_label();
			//如果该if语句没有兄弟结点（在compound stmt中没有下一条语句）
			//也需要有next_label，因为对应结束进程的函数调用（ExitProcess）
		}
		s1->label.next_label = t->label.next_label;
		if (t->sibling)
		{
			//该if语句（在compound stmt中）的下一条语句的标签
			t->sibling->label.begin_label = t->label.next_label;
		}

		if (s2) //如果该if语句有匹配的else（标签对应假值标签）
		{
			s2->label.begin_label = e->label.false_label;
			s2->label.next_label = t->label.next_label;
		}
		else //如果没有，则false_label是该if语句（在compound stmt中）的下一条语句的标签
		{
			e->label.false_label = t->label.next_label;
		}
		//递归地生成expr中嵌套bool表达式的标签，以及if、else分支里面语句的标签
		if (e)
		{
			recursive_get_label(e);
		}
		if (s1)
		{
			recursive_get_label(s1);
		}
		if (s2)
		{
			recursive_get_label(s2);
		}
	}
	break;

	case ForK:
	{
		TreeNode *e1 = t->child[0]; //expr 1
		TreeNode *e2 = t->child[1]; //expr 2 (Boolean expr)
		TreeNode *e3 = t->child[2]; //expr 3
		TreeNode *s = t->child[3];  //for

		if (e1)
		{
			if (e1->label.next_label == "")
			{
				e1->label.next_label = new_label();
			}
		}
		else
		{
			if (t->label.begin_label == "")
			{
				t->label.begin_label = new_label();
			}
		}

		if (e2)
		{
			e2->label.true_label = new_label();
		}
		/*if (e3)
		{
		e3->label.begin_label = new_label();
		}*/

		if (t->label.next_label == "")
		{
			t->label.next_label = new_label();
		}

		if (e1 && e2 && e3)
		{
			//e1->label.begin_label = t->label.begin_label;
			s->label.begin_label = e2->label.true_label; //真值出口
														 //s->label.next_label = e3->label.begin_label;
			e3->label.next_label = e1->label.next_label;
			e2->label.false_label = t->label.next_label; //假值出口
		}
		else if (e1 && e2 && !e3)
		{
			//e1->label.begin_label = t->label.begin_label;
			s->label.begin_label = e2->label.true_label; //真值出口
			s->label.next_label = e1->label.next_label;
			e2->label.false_label = t->label.next_label; //假值出口
		}
		else if (e1 && !e2 && e3)
		{
			//e1->label.begin_label = t->label.begin_label;
			s->label.begin_label = e1->label.next_label;
			//s->label.next_label = e3->label.begin_label;
			e3->label.next_label = s->label.begin_label;
		}
		else if (e1 && !e2 && !e3)
		{
			//e1->label.begin_label = t->label.begin_label;
			s->label.begin_label = e1->label.next_label;
			s->label.next_label = s->label.begin_label;
		}
		else if (!e1 && e2 && e3)
		{
			s->label.begin_label = e2->label.true_label; //真值出口
														 //s->label.next_label = e3->label.begin_label;
			e3->label.next_label = t->label.begin_label;
			e2->label.false_label = t->label.next_label; //假值出口
		}
		else if (!e1 && e2 && !e3)
		{
			s->label.begin_label = e2->label.true_label; //真值出口
			s->label.next_label = t->label.begin_label;
			e2->label.false_label = t->label.next_label; //假值出口
		}
		else if (!e1 && !e2 && e3)
		{
			//s->label.next_label = e3->label.begin_label;
			e3->label.next_label = t->label.begin_label;
		}
		else if (!e1 && !e2 && !e3)
		{
			s->label.next_label = t->label.begin_label;
		}

		if (t->sibling)
		{
			t->sibling->label.begin_label = t->label.next_label;
		}

		if (e1)
		{
			recursive_get_label(e1);
		}
		if (e2)
		{
			recursive_get_label(e2);
		}
		if (e3)
		{
			recursive_get_label(e3);
		}
		if (s)
		{
			recursive_get_label(s);
		}
	}
	break;

	case CompK:
	{
		TreeNode *last; //The last stmt in compound stmt
		TreeNode *p;
		int i = 0;
		for (p = t->child[0]; p != NULL; p = p->sibling)
		{
			if (p->nodekind == DeclK && p->kind.decl == VarK) //跳过声明语句
			{
				continue;
			}
			/*if (i == 0)
			{
			p->label.begin_label = t->label.begin_label;
			}*/
			last = p;
			recursive_get_label(p); //递归地为复合语句的每一条语句生成标签
			i++;
		}

		t->label.next_label = last->label.next_label;
		if (t->sibling)
		{
			t->sibling->label.begin_label = t->label.next_label;
		}
	}
	break;
	}
}

void expr_get_label(TreeNode *t)
{
	if (!t)
		return;
	if (t->nodekind != ExpK)
		return;
	if (t->type != Boolean) //只对布尔表达式生成标签
		return;

	TreeNode *e1 = t->child[0];
	TreeNode *e2 = t->child[1];
	switch (t->attr.op)
	{
	case LOGAND:
		e1->label.true_label = new_label();                                   //第一个分量为真则需要看第二个分量的值
		e2->label.true_label = t->label.true_label;                           //必须是两个分量都为真，表达式的值才为真
		e1->label.false_label = e2->label.false_label = t->label.false_label; //只要第一个分量为假，表达式的值就为假，后面的表达式不再计算
		break;

	case LOGOR:
		e1->label.false_label = new_label();
		e2->label.false_label = t->label.false_label;
		e1->label.true_label = e2->label.true_label = t->label.true_label;
		break;

	case NOT:
		e1->label.true_label = t->label.false_label; //真值与假值出口相反
		e1->label.false_label = t->label.true_label;
		break;
	}
	if (e1)
		recursive_get_label(e1);
	if (e2)
		recursive_get_label(e2);
}

void recursive_get_label(TreeNode *t)
{
	if (!t)
		return;
	if (t->nodekind == StmtK)
		stmt_get_label(t);
	else if (t->nodekind == ExpK)
		expr_get_label(t);
}

void get_label()
{
	root->label.begin_label = "_start";
	recursive_get_label(root);
}

void gen_code(ostream &out)
{
	gen_header(out);
	TreeNode *p = root->child[0];
	//generate .data first
	if (p->nodekind == DeclK && p->kind.decl == VarK)
		gen_decl(out, p);
	out << endl
		<< endl
		<< ".code" << endl
		<< endl;
	recursive_gen_code(out, root);
	if (root->label.next_label != "")
	{
		out << root->label.next_label << ":" << endl;
	}
	out << "\tinvoke ExitProcess, 0" << endl;
	out << "end " << root->label.begin_label << endl; //end _start
}

void gen_header(ostream &out)
{
	out << ".586" << endl;
	out << ".model flat, stdcall" << endl;
	out << "option casemap :none" << endl;
	out << endl;
	out << "includelib \\masm32\\lib\\kernel32.lib" << endl;
	out << "includelib \\masm32\\lib\\user32.lib" << endl;
	out << "includelib \\masm32\\lib\\gdi32.lib" << endl;
	out << "includelib \\masm32\\lib\\msvcrt.lib" << endl;
	out << "includelib \\masm32\\lib\\masm32.lib" << endl;
	out << endl;
	out << "include \\masm32\\include\\kernel32.inc" << endl;
	out << "include \\masm32\\include\\user32.inc" << endl;
	out << "include \\masm32\\include\\gdi32.inc" << endl;
	out << "include \\masm32\\include\\windows.inc" << endl;
	out << "include \\masm32\\include\\msvcrt.inc" << endl;
	out << "include \\masm32\\include\\masm32.inc" << endl;
	out << "include \\masm32\\macros\\macros.asm" << endl;
}

void get_temp_var(TreeNode *t)
{
	if (!t)
		return;
	if (t->nodekind != ExpK) //临时变量仅用于算术表达式
		return;
	if (t->kind.exp != OpK)
		return;
	if (t->attr.op != PLUS && t->attr.op != MINUS && t->attr.op != MUL && t->attr.op != OVER && t->attr.op != AND && t->attr.op != OR && t->attr.op != MOD && t->attr.op != SHIFTLEFT && t->attr.op != SHIFTRIGHT &&
		t->attr.op != NEG && t->attr.op != MINUSU && t->attr.op != XOR && t->attr.op != MINUSMINUSL && t->attr.op != MINUSMINUSR
		&& t->attr.op != PLUSPLUSR && t->attr.op != PLUSPLUSL)
		return;

	TreeNode *arg1 = t->child[0];
	TreeNode *arg2 = t->child[1];

	//将不用的临时变量收回，实现临时变量重用（因为此时子表达式已经计算完了）
	if (arg1->kind.exp == OpK)
		tempvarcount--;
	if (arg2 && arg2->kind.exp == OpK)
		tempvarcount--;
	t->tempvar = tempvarcount;
	tempvarcount++; //分配临时变量
}

void gen_decl(ostream &out, TreeNode *t)
{
	if (!t)
		return;
	out << endl
		<< endl
		<< ".data" << endl;

	for (; t != NULL; t = t->sibling)
	{
		if (t->nodekind == DeclK && t->kind.decl == VarK)
		{
			for (TreeNode *p = t->child[1]; p; p = p->sibling)
			{
				if (p->nodekind == ExpK)
				{
					if (p->kind.exp == IdK)
					{
						Symbol *sym = lookup_table(p->attr.idname);
						if (sym)
						{
							if (p->type == Integer)
								out << "\t_" << sym->idname << " DWORD 0" << endl;
							else if (p->type == Char)
								out << "\t_" << sym->idname << " BYTE 0" << endl;
						}
					}
				}
			}
		}
	}

	//temp var
	for (int i = 0; i < tempvarcount; i++)
	{
		out << "\tt" << i << " DWORD 0" << endl;
	}
	out << "\tszInputInt BYTE \"\%d\",0" << endl;
	out << "\tszOutputInt BYTE \"\%d\",13,10,0" << endl;
	out << "\tszInputChar BYTE \"\%c\",0" << endl;
	out << "\tszOutputChar BYTE \"\%c\",13,10,0" << endl;
}

void recursive_gen_code(ostream &out, TreeNode *t)
{
	if (!t)
		return;
	if (t->nodekind == StmtK)
	{
		stmt_gen_code(out, t);
	}
	else if (t->nodekind == ExpK)
	{
		if (t->kind.exp == OpK)
		{
			expr_gen_code(out, t);
		}
	}
}

void expr_gen_code(ostream &out, TreeNode *t)
{
	if (!t)
		return;
	if (t->nodekind != ExpK)
		return;
	if (t->kind.exp != OpK)
		return;
	if (t->label.begin_label != "")
	{
		out << t->label.begin_label << ":" << endl;
	}
	TreeNode *e1 = t->child[0];
	TreeNode *e2 = t->child[1];
	switch (t->attr.op)
	{
		/* assign expr */
	case ASSIGN: //'='
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e2->kind.exp == IdK)
		{
			out << "_" << e2->attr.idname;
		}
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
		{
			out << "t" << e2->tempvar;
		}
		out << endl;
		out << "\tmov ";
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else
			out << "t" << e1->tempvar;

		if (t->type == Integer)
		{
			out << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << ", al" << endl;
		}
		break;

		/* arithmetic expr */
	case PLUS: //'+'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tadd eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tadd al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case MINUS: //'-'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tsub eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tsub al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case MUL: //'*'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
			if (e1->kind.exp == IdK)
				out << "_" << e1->attr.idname;
			else if (e1->kind.exp == ConstK)
			{
				if (e1->type == Integer)
				{
					out << e1->attr.intval;
				}
				else if (e1->type == Char)
				{
					out << (int)(e1->attr.charval);
				}
			}
			else
				out << "t" << e1->tempvar;
			out << endl;
			out << "\timul eax, ";
			if (e2->kind.exp == IdK)
				out << "_" << e2->attr.idname;
			else if (e2->kind.exp == ConstK)
			{
				if (e2->type == Integer)
				{
					out << e2->attr.intval;
				}
				else if (e2->type == Char)
				{
					out << (int)(e2->attr.charval);
				}
			}
			else
				out << "t" << e2->tempvar;
			out << endl;
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
			if (e1->kind.exp == IdK)
				out << "_" << e1->attr.idname;
			else if (e1->kind.exp == ConstK)
			{
				if (e1->type == Integer)
				{
					out << e1->attr.intval;
				}
				else if (e1->type == Char)
				{
					out << (int)(e1->attr.charval);
				}
			}
			else
				out << "t" << e1->tempvar;
			out << endl;
			out << "\tmov bl, ";
			if (e2->kind.exp == IdK)
				out << "_" << e2->attr.idname;
			else if (e2->kind.exp == ConstK)
			{
				if (e2->type == Integer)
				{
					out << e2->attr.intval;
				}
				else if (e2->type == Char)
				{
					out << (int)(e2->attr.charval);
				}
			}
			else
				out << "t" << e2->tempvar;
			out << endl;

			out << "\timul bl";
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case OVER: //'/'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
			if (e1->kind.exp == IdK)
				out << "_" << e1->attr.idname;
			else if (e1->kind.exp == ConstK)
			{
				if (e1->type == Integer)
				{
					out << e1->attr.intval;
				}
				else if (e1->type == Char)
				{
					out << (int)(e1->attr.charval);
				}
			}
			else
				out << "t" << e1->tempvar;
			out << endl;
			out << "\tcdq" << endl; //将eax的符号位赋给edx所有位（符号扩展），将edx和eax拼接起来组成被除数
			out << "\tidiv eax, ";
			if (e2->kind.exp == IdK)
				out << "_" << e2->attr.idname;
			else if (e2->kind.exp == ConstK)
			{
				if (e2->type == Integer)
				{
					out << e2->attr.intval;
				}
				else if (e2->type == Char)
				{
					out << (int)(e2->attr.charval);
				}
			}
			else
				out << "t" << e2->tempvar;
			out << endl;
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
			if (e1->kind.exp == IdK)
				out << "_" << e1->attr.idname;
			else if (e1->kind.exp == ConstK)
			{
				if (e1->type == Integer)
				{
					out << e1->attr.intval;
				}
				else if (e1->type == Char)
				{
					out << (int)(e1->attr.charval);
				}
			}
			else
				out << "t" << e1->tempvar;
			out << endl;
			out << "\tcbw" << endl;
			out << "\tmov bl, ";
			if (e2->kind.exp == IdK)
				out << "_" << e2->attr.idname;
			else if (e2->kind.exp == ConstK)
			{
				if (e2->type == Integer)
				{
					out << e2->attr.intval;
				}
				else if (e2->type == Char)
				{
					out << (int)(e2->attr.charval);
				}
			}
			else
				out << "t" << e2->tempvar;
			out << endl;
			out << "\tidiv bl";
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case MOD: //'%'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
			if (e1->kind.exp == IdK)
				out << "_" << e1->attr.idname;
			else if (e1->kind.exp == ConstK)
			{
				if (e1->type == Integer)
				{
					out << e1->attr.intval;
				}
				else if (e1->type == Char)
				{
					out << (int)(e1->attr.charval);
				}
			}
			else
				out << "t" << e1->tempvar;
			out << endl;
			out << "\tcdq" << endl; //将eax的符号位赋给edx所有位（符号扩展），将edx和eax拼接起来组成被除数
			out << "\tidiv eax, ";
			if (e2->kind.exp == IdK)
				out << "_" << e2->attr.idname;
			else if (e2->kind.exp == ConstK)
			{
				if (e2->type == Integer)
				{
					out << e2->attr.intval;
				}
				else if (e2->type == Char)
				{
					out << (int)(e2->attr.charval);
				}
			}
			else
				out << "t" << e2->tempvar;
			out << endl;
			out << "\tmov t" << t->tempvar << ", edx" << endl; //注意：余数应从edx中取
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
			if (e1->kind.exp == IdK)
				out << "_" << e1->attr.idname;
			else if (e1->kind.exp == ConstK)
			{
				if (e1->type == Integer)
				{
					out << e1->attr.intval;
				}
				else if (e1->type == Char)
				{
					out << (int)(e1->attr.charval);
				}
			}
			else
				out << "t" << e1->tempvar;
			out << endl;
			out << "\tcbw" << endl;
			out << "\tmov bl, ";
			if (e2->kind.exp == IdK)
				out << "_" << e2->attr.idname;
			else if (e2->kind.exp == ConstK)
			{
				if (e2->type == Integer)
				{
					out << e2->attr.intval;
				}
				else if (e2->type == Char)
				{
					out << (int)(e2->attr.charval);
				}
			}
			else
				out << "t" << e2->tempvar;
			out << endl;
			out << "\tidiv bl";
			out << "\tmov t" << t->tempvar << ", ah" << endl;
		}
		break;

	case SHIFTRIGHT: //'>>'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tsar eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tsar al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case SHIFTLEFT: //'<<'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tshl eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tshl al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case AND: //'&'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tand eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tand al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case OR: //'|'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tor eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tor al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case XOR: //'^'
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\txor eax, ";
		}
		else if (t->type == Char)
		{
			out << "\txor al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

		/* relational expr */
	case SMALL:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (e1->type == Integer)
		{
			out << "\tcmp eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tcmp al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		out << "\tjl " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case GREAT:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (e1->type == Integer)
		{
			out << "\tcmp eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tcmp al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		out << "\tjg " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case SMAEQU:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (e1->type == Integer)
		{
			out << "\tcmp eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tcmp al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		out << "\tjle " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case GREEQU:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (e1->type == Integer)
		{
			out << "\tcmp eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tcmp al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		out << "\tjge " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case EQUAL:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (e1->type == Integer)
		{
			out << "\tcmp eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tcmp al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		out << "\tje " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case NOTEQUAL:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (e1->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (e2->type == Integer)
		{
			out << "\tcmp eax, ";
		}
		else if (e2->type == Char)
		{
			out << "\tcmp al, ";
		}
		if (e2->kind.exp == IdK)
			out << "_" << e2->attr.idname;
		else if (e2->kind.exp == ConstK)
		{
			if (e2->type == Integer)
			{
				out << e2->attr.intval;
			}
			else if (e2->type == Char)
			{
				out << (int)(e2->attr.charval);
			}
		}
		else
			out << "t" << e2->tempvar;
		out << endl;
		out << "\tjne " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

		/* unary expr */
	case PLUSU:
		recursive_gen_code(out, e1);
		/*out << "\tmov eax, ";
		if (e1->kind.exp == IdK)
		out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
		if (e1->type == Integer)
		{
		out << e1->attr.intval;
		}
		else if (e1->type == Char)
		{
		out << (int)(e1->attr.charval);
		}
		}
		else
		out << "t" << e1->tempvar;
		out << endl;
		out << "\tmov t" << t->tempvar << ", eax" << endl;*/
		break;

	case MINUSU:
		recursive_gen_code(out, e1);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tneg eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tneg al" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

		//后置和前置++/--的区别是前者是将变量原值的副本作为表达式的值，但是变量加1/减1后的值会赋给变量
		//后者是变量会被赋上加1/减1后的值，变量加1/减1后的值同时作为表达式的值
	case PLUSPLUSR:
		recursive_gen_code(out, e1);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov ecx, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov cl, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tinc ecx" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tinc cl" << endl;
		}
		if (t->type == Integer) //保存在变量中
		{
			out << "\tmov _" << e1->attr.idname << ", ecx" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov _" << e1->attr.idname << ", cl" << endl;
		}
		if (t->type == Integer) //表达式值（临时变量）仍存变量原值
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case PLUSPLUSL:
		recursive_gen_code(out, e1);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tinc eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tinc al" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov _" << e1->attr.idname << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov _" << e1->attr.idname << ", al" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case MINUSMINUSR:
		recursive_gen_code(out, e1);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tmov ecx, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov cl, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tdec ecx" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tdec cl" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov _" << e1->attr.idname << ", ecx" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov _" << e1->attr.idname << ", cl" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case MINUSMINUSL:
		recursive_gen_code(out, e1);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tdec eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tdec al" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov _" << e1->attr.idname << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov _" << e1->attr.idname << ", al" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

	case NEG:
		recursive_gen_code(out, e1);
		if (t->type == Integer)
		{
			out << "\tmov eax, ";
		}
		else if (t->type == Char)
		{
			out << "\tmov al, ";
		}
		if (e1->kind.exp == IdK)
			out << "_" << e1->attr.idname;
		else if (e1->kind.exp == ConstK)
		{
			if (e1->type == Integer)
			{
				out << e1->attr.intval;
			}
			else if (e1->type == Char)
			{
				out << (int)(e1->attr.charval);
			}
		}
		else
			out << "t" << e1->tempvar;
		out << endl;
		if (t->type == Integer)
		{
			out << "\tnot eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tnot al" << endl;
		}
		if (t->type == Integer)
		{
			out << "\tmov t" << t->tempvar << ", eax" << endl;
		}
		else if (t->type == Char)
		{
			out << "\tmov t" << t->tempvar << ", al" << endl;
		}
		break;

		/* logical expr */
	case LOGOR:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		out << e1->label.false_label << ":" << endl;
		recursive_gen_code(out, e2);
		break;

	case LOGAND:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		out << e1->label.true_label << ":" << endl;
		recursive_gen_code(out, e2);
		break;

	case NOT:
		/*if (t->label.begin_label != "")
		{
		out << t->label.begin_label << ":" << endl;
		}*/
		recursive_gen_code(out, e1);
		break;
	}
}

void stmt_gen_code(ostream &out, TreeNode *t)
{
	if (!t)
		return;
	if (t->nodekind != StmtK)
		return;
	//所有标签都要自己打
	if (t->label.begin_label != "")
		out << t->label.begin_label << ":" << endl;
	if (t->kind.stmt == CompK)
	{
		for (TreeNode *p = t->child[0]; p; p = p->sibling)
			recursive_gen_code(out, p);
	}
	else if (t->kind.stmt == WhileK)
	{
		recursive_gen_code(out, t->child[0]);
		recursive_gen_code(out, t->child[1]);
		out << "\tjmp " << t->label.begin_label << endl;
	}
	else if (t->kind.stmt == ForK)
	{
		TreeNode *e1 = t->child[0];
		TreeNode *e2 = t->child[1];
		TreeNode *e3 = t->child[2];
		TreeNode *s = t->child[3];

		if (e1 && e2 && e3)
		{
			recursive_gen_code(out, e1);
			out << e1->label.next_label << ":" << endl;
			recursive_gen_code(out, e2);
			recursive_gen_code(out, s);
			recursive_gen_code(out, e3);
			out << "\tjmp " << e1->label.next_label << endl;
		}
		else if (e1 && e2 && !e3)
		{
			recursive_gen_code(out, e1);
			out << e1->label.next_label << ":" << endl;
			recursive_gen_code(out, e2);
			recursive_gen_code(out, s);
			out << "\tjmp " << e1->label.next_label << endl;
		}
		else if (e1 && !e2 && e3)
		{
			recursive_gen_code(out, e1);
			recursive_gen_code(out, s);
			recursive_gen_code(out, e3);
			out << "\tjmp " << e1->label.next_label << endl;
		}
		else if (e1 && !e2 && !e3)
		{
			recursive_gen_code(out, e1);
			recursive_gen_code(out, s);
			out << "\tjmp " << e1->label.next_label << endl;
		}
		else if (!e1 && e2 && e3)
		{
			recursive_gen_code(out, e2);
			recursive_gen_code(out, s);
			recursive_gen_code(out, e3);
			out << "\tjmp " << t->label.begin_label << endl;
		}
		else if (!e1 && e2 && !e3)
		{
			recursive_gen_code(out, e2);
			recursive_gen_code(out, s);
			out << "\tjmp " << t->label.begin_label << endl;
		}
		else if (!e1 && !e2 && e3)
		{
			recursive_gen_code(out, s);
			recursive_gen_code(out, e3);
			out << "\tjmp " << t->label.begin_label << endl;
		}
		else if (!e1 && !e2 && !e3)
		{
			recursive_gen_code(out, s);
			out << "\tjmp " << t->label.begin_label << endl;
		}
	}
	else if (t->kind.stmt == IfK)
	{
		recursive_gen_code(out, t->child[0]);
		recursive_gen_code(out, t->child[1]);
		if (t->child[2])
		{
			out << "\tjmp " << t->label.next_label << endl;
			recursive_gen_code(out, t->child[2]);
		}
	}
	else if (t->kind.stmt == DoWhileK)
	{
		recursive_gen_code(out, t->child[0]);
		recursive_gen_code(out, t->child[1]);
		out << "\tjmp " << t->label.begin_label << endl;
	}
	else if (t->kind.stmt == InputK)
	{
		TreeNode *v = t->child[0];
		recursive_gen_code(out, v);
		if (v->nodekind == ExpK)
		{
			if (v->kind.exp == IdK)
			{
				Symbol *sym = lookup_table(v->attr.idname);
				if (sym->base_type == Integer)
				{
					out << "\tinvoke crt_scanf,offset szInputInt,addr _" << sym->idname << endl;
					out << "\tinvoke crt_getchar" << endl; //清空输入缓冲区
				}
				else if (sym->base_type == Char)
				{
					out << "\tinvoke crt_scanf,offset szInputChar,addr _" << sym->idname << endl;
					out << "\tinvoke crt_getchar" << endl; //清空输入缓冲区
				}
			}
		}
	}
	else if (t->kind.stmt == OutputK)
	{
		TreeNode *v = t->child[0];
		recursive_gen_code(out, v);
		if (v->nodekind == ExpK)
		{
			TreeNode *v = t->child[0];
			if (v->kind.exp == IdK)
			{
				Symbol *sym = lookup_table(v->attr.idname);
				if (sym->base_type == Integer)
				{
					out << "\tinvoke crt_printf,offset szOutputInt,_" << sym->idname << endl;
				}
				else if (sym->base_type == Char)
				{
					out << "\tinvoke crt_printf,offset szOutputChar,_" << sym->idname << endl;
				}
			}
			else if (v->kind.exp == ConstK)
			{
				if (v->type == Integer)
				{
					out << "\tinvoke crt_printf,offset szOutputInt," << v->attr.intval << endl;
				}
				else if (v->type == Char)
				{
					out << "\tinvoke crt_printf,offset szOutputChar," << (int)(v->attr.charval) << endl;
				}
			}
			else if (v->kind.exp == OpK)
			{
				if (v->type == Integer)
				{
					out << "\tinvoke crt_printf,offset szOutputInt,t" << v->tempvar << endl;
				}
				else if (v->type == Char)
				{
					out << "\tinvoke crt_printf,offset szOutputChar,t" << v->tempvar << endl;
				}
			}
		}
	}
}