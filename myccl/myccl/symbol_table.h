#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include "TreeNode.h"
using namespace std;

struct Symbol
{
    char *idname;
    ExpType base_type;
    int pointer;
    int entryno;
    Attr val;
    bool islocal;
    bool isstatic;
    bool decled;
    bool isinited;
    bool redecl;
};