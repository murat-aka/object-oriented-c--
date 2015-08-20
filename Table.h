#ifndef TABLE_H
#define TABLE_H


#include "Database.h"
#include <map>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

 class Table
{

    public:
    int row, col;
    string table_name;
    vector<vector<string> > table;
    vector<vector<string> > table2;


    int select_row, select_col;

    public:
    Table();
    Table(int in_side, double initValue);
    Table(int in_row, int in_col, string initValue);
    Table(int in_row, int in_col, int initValue);
    Table(int in_row, int in_col);
    void select(int in_row, int in_col);
    void insert(double value);
    void insert(int in_row, int in_col, double value);
    void deleteRow(int rowIndex);
    void deleteCol(class Database&, int colIndex, string table_name);
    void addCol(class Database&, int colIndex,string table_name);
    void addRow(class Database& db,int rowIndex, string table_name);
     void addRow2(class Database& db,string table_name, int no_of_columns);
    void deleteRow(class Database& db,int rowIndex, string table_name);
    void insertRow(vector<string> tableRow, int rowIndex);
    void printRow(class Database& db,string table_name);
    void printCol(class Database& db);
    void editTable(Database& db, int row, int col, string value, string table_name);
    void editTable2(Database& db,int row,int col, string value,string table_name);
    void printDatabase( class Database& db1, string n);
    void printTable(class Database &db, string n);
    void printTable2(class Database &db, string n, string table_name);
    void swapRow(class Database& db);
    void deleteTable(class Database& db);


    friend class Database;
};

ostream& operator<< (ostream& s, Table &tb1);

#endif // TABLE_H
