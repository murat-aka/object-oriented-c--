#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include <map>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
class SortedTable
{
    public:

        map<string, vector<string>  > new_table;
        map<string, map<string, vector<string>  >  > new_map;
        map<string, map<string, vector<string>  >  > ::iterator iter_new_map;
        SortedTable();

        void sort_tables(class Database& db1);
        void print_sorted_tables(class Database& db1);

    protected:
    private:
};

#endif // SORTEDTABLE_H
