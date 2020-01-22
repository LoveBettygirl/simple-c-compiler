#pragma once
#define MAXCHILDREN 10

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

enum NodeKind
{
    StmtK,
    ExpK,
    DeclK,
    FuncDefK,
    InitK,
    SpciK,
    PointK,
    ArrayK,
    StaticK,
    VardK,
    ParamK,
    CaseK,
    DefaultK
};
enum StmtKind
{
    IfK,
    WhileK,
    ForK,
    DoWhileK,
    ContK,
    BreakK,
    RetK,
    CompK,
    GotoK,
    LabelK,
    InputK,
    OutputK
};
enum ExpKind
{
    OpK,
    ConstK,
    IdK,
    CastK,
    FunccK
};
enum SpciKind
{
    TypeK,
    StructK,
    UnionK
};
enum DeclKind
{
    VarK,
    FuncK
};
enum ExpType
{
    Void,
    Integer,
    Char,
    Float,
    Double,
    Short,
    Boolean,
    Str
}; //data types for check

union Attr {
    int op;
    int intval;
    double douval;
    float floatval;
    char charval;
    short shortval;
    void *pval;
    char *strval;
    char *idname;
};

union Kind {
    StmtKind stmt;
    ExpKind exp;
    DeclKind decl;
    SpciKind spci;
};

struct Label {
	struct {
		string true_label; //only for boolean expr
		string false_label;
	};
	struct {
		string begin_label;
		string next_label; //next label generated for preparation (next stmt)
	};
};

struct TreeNode
{
    TreeNode *child[MAXCHILDREN];
    TreeNode *sibling;
    int nodeno;
    NodeKind nodekind; //main kind
    Kind kind;         //sub kind
    Attr attr;
    bool boolval;
    ExpType type; //used by constant or id or var declaration
    int pointer;
    char *errmsg;
    Label label;
    int tempvar;
    //int arraydim; //0 1 2, only support up to 2 dimensions
    //int arraylow; //low dimension
    //int arrayhigh; //high dimension
};
