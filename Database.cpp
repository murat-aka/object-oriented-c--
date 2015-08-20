#include <iostream>
#include <istream>
#include "Database.h"
#include "File.h"
#include <fstream>
#include <sstream>



void Database::createTable(string name, int in_row, int in_col) {

    Table tb1(in_row , in_col);
    mymap[name]=tb1;

    }

/*Database::~Database()
{

} */

    void Database::deleteDatabase(Database&)
{




}

void Database::createTable(string name, int in_row, int in_col, string value) {

    Table tb1(in_row , in_col, value);
    mymap[name]=tb1;
 table_names.push_back(name);


     for (int i=1; i<= in_col; i++)
  {

      cout << "Enter the column names: ";
      string txt;
      cin >> txt;
      c_names.push_back(txt);

      column_names[name]=c_names;

  }
c_names.resize(0);
cout << endl;
for (int i=1; i<= in_row; i++)
{
      cout << "Enter the name for row "<< i << " :";
      string txt;
      cin >> txt;
       r_names.push_back(txt);

      row_names[name]=r_names;
}
r_names.resize(0);
    }
void Database::createTable2(string name, int in_row, int in_col, string value) {

    Table tb1(in_row , in_col, value);
    mymap[name]=tb1;
    table_names.push_back(name);

   }

void Database::deleteTable(string tableName){


}

void Database::InitialiseTable(string key, int value){


          /*  it=mymap.find(key);

            for(t = it->second.table.begin(); t!=it->second.table.end(); ++t)
                {
                    for (tc = t->begin(); tc != t->end(); tc++)
                        {
                                *tc=value;
                        }
                } */
}

void Database::editTable(string key, int row, int col, string value){

            it=mymap.find(key);
            it->second.table[row-1][col-1]=value;

}

void Database::printDatabase(string n){

cout <<"in database: "<< n << endl;
cout << endl;
    for ( it =mymap.begin(); it != mymap.end(); it++)
        {

            cout << "Table name: " << endl;
            cout << it -> first << endl;

            for(t = it->second.table.begin(); t!=it->second.table.end(); ++t)
                {
                    for (tc = t->begin(); tc != t->end(); tc++)
                        {
                            cout << *tc << "  ";
                        }
                    cout << endl;
                }

        } cout << endl;
}



