#include "Unsorted_map.h"
#include "Database.h"
#include "Table.h"
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
Database db3;
Table tb3;
Unsorted_map::Unsorted_map()
{
    //ctor
}


 Unsorted_map::Unsorted_map(class Database& db1,vector<string>& table_names)
{


   //  sort (table_names.begin(), table_names.end());

for (iter_table_names=table_names.begin(); iter_table_names!=table_names.end(); ++iter_table_names)
     tb3.printTable2(db1,"db1", *iter_table_names) ;
  std::cout << '\n';
}
