#include "symbol_table.h"

vector<Symbol *> table; //symbol table

Symbol *newEntry(char *id);
Symbol *lookup_table(char *id);
Symbol *lookup_table(int pos);
Symbol *insert_table(char *id);
void printSymTable();

/* create new symbol table entry */
Symbol *newEntry(char *id)
{
    Symbol *temp = new Symbol;
    temp->idname = id;
    temp->base_type = Void;
    temp->pointer = 0;
    temp->islocal = true;
    temp->isstatic = false;
    temp->decled = false;
    temp->isinited = false;
    temp->redecl = false;
    return temp;
}

/* look up symbol table */
Symbol *lookup_table(char *id)
{
    int i;
    for (int i = 0; i < table.size(); i++)
    {
        if (strcmp(table[i]->idname, id) == 0)
            return table[i];
    }
    return NULL;
}

/* look up symbol table */
Symbol *lookup_table(int pos)
{
    if (pos < 0 || pos >= table.size())
        return NULL;
    return table[pos];
}

/* insert into symbol table */
Symbol *insert_table(char *id)
{
    if (lookup_table(id) == NULL)
    {
        Symbol *temp = newEntry(id);
        table.push_back(temp);
        return temp;
    }
    return NULL;
}

void printSymTable()
{
    cout << "Symbol Table: " << endl;
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i]->base_type == Integer)
        {
            cout << i << " " << table[i]->idname << " type: int"
                 << " pointer: " << table[i]->pointer << " islocal: " << table[i]->islocal
                 << " isstatic: " << table[i]->isstatic << " decled: " << table[i]->decled
                 << " isinited: " << table[i]->isinited << " redecl: " << table[i]->redecl << endl;
        }
        else if (table[i]->base_type == Char)
        {
            cout << i << " " << table[i]->idname << " type: char"
                 << " pointer: " << table[i]->pointer << " islocal: " << table[i]->islocal
                 << " isstatic: " << table[i]->isstatic << " decled: " << table[i]->decled
                 << " isinited: " << table[i]->isinited << " redecl: " << table[i]->redecl << endl;
        }
        else if (table[i]->base_type == Double)
        {
            cout << i << " " << table[i]->idname << " type: double"
                 << " pointer: " << table[i]->pointer << " islocal: " << table[i]->islocal
                 << " isstatic: " << table[i]->isstatic << " decled: " << table[i]->decled
                 << " isinited: " << table[i]->isinited << " redecl: " << table[i]->redecl << endl;
        }
        else if (table[i]->base_type == Float)
        {
            cout << i << " " << table[i]->idname << " type: float"
                 << " pointer: " << table[i]->pointer << " islocal: " << table[i]->islocal
                 << " isstatic: " << table[i]->isstatic << " decled: " << table[i]->decled
                 << " isinited: " << table[i]->isinited << " redecl: " << table[i]->redecl << endl;
        }
        else if (table[i]->base_type == Short)
        {
            cout << i << " " << table[i]->idname << " type: short"
                 << " pointer: " << table[i]->pointer << " islocal: " << table[i]->islocal
                 << " isstatic: " << table[i]->isstatic << " decled: " << table[i]->decled
                 << " isinited: " << table[i]->isinited << " redecl: " << table[i]->redecl << endl;
        }
        else if (table[i]->base_type == Void)
        {
            cout << i << " " << table[i]->idname << " type: void"
                 << " pointer: " << table[i]->pointer << " islocal: " << table[i]->islocal
                 << " isstatic: " << table[i]->isstatic << " decled: " << table[i]->decled
                 << " isinited: " << table[i]->isinited << " redecl: " << table[i]->redecl << endl;
        }
    }
}