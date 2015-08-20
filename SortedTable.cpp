#include "SortedTable.h"
#include "Database.h"
#include <algorithm>
   // std::sort
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

SortedTable::SortedTable()
{
    //ctor
}


void SortedTable::sort_tables(class Database& db1)
{

   for(db1.it = db1.mymap.begin(); db1.it != db1.mymap.end(); ++db1.it)
   {
                int  i=0;
                for(db1.t = db1.it->second.table.begin(); db1.t!=db1.it->second.table.end(); ++db1.t)
                {
                    new_table[db1.row_names[db1.it->first][i]] = *db1.t;
                    i++;
                }
                new_map[db1.it->first]=new_table;
                new_table.clear();
   }

}


void SortedTable::print_sorted_tables(class Database& db)
{

    for ( iter_new_map = new_map.begin(); iter_new_map != new_map.end(); iter_new_map++)
    {
            cout <<"\n"<< "Table name: ";
            cout  << iter_new_map -> first << endl;
            cout << setw(10) << " " ;

            for (int i=0;i < db.column_names[iter_new_map -> first].size() ;i++)
            {
              cout <<  setw(10) <<  db.column_names[iter_new_map -> first][i] ;
            }
            cout << "\n";

         for ( db.itr = iter_new_map->second.begin(); db.itr != iter_new_map->second.end(); db.itr++)
        {
            cout<< setw(10)<< db.itr -> first;
            for(db.tc = db.itr->second.begin(); db.tc!=db.itr->second.end(); ++db.tc)
                {
                    cout<< setw(10)<< *db.tc;
                }
            cout << endl;
        }
    }


}




