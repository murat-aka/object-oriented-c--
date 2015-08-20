#ifndef DATABASE_H
#define DATABASE_H


#include "Table.h"
#include "interface.h"
#include <string>
#include <map>
using namespace std;

class Database
{
    public:
    map<string, Table >::iterator it;

     map<string, vector<string>  >::iterator itr;



    vector<vector<string> >::iterator t;
    vector<string>::iterator tc;
    vector<string>::iterator iter_row_names;

 vector<string> table_names;


    vector<string> c_names;
    vector<string> r_names;

    map<string, Table > mymap;
    map<string, Table > copy_of_mymap;
    map<string, vector<string>  > row_names;
    map<string, vector<string>  > copy_of_row_names;
    map<string, vector<string>  > column_names;

    void createTable(string name, int in_row, int in_col) ;
    void createTable(string name, int in_row, int in_col, string value) ;
    void createTable(string name, int in_row, int in_col, int value) ;
    void InitialiseTable(string tableName, int value);
    void editTable(string key, int row, int col, string value);
    void printDatabase(string n);

    void createTable2(string name, int in_row, int in_col, string value);

    void deleteTable(string tableName);
    void deleteDatabase(class Database&);
   // ~Database();
    friend class Table;
    friend class SortedTable;
};


#endif // DATABASE_H
