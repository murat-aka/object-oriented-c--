#ifndef UNSORTED_MAP_H
#define UNSORTED_MAP_H

// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;
class Unsorted_map
{
    public:
        Unsorted_map();
         Unsorted_map(class Database&,vector<string>& table_names);
        vector<string>::iterator iter_table_names;

        friend class interface;

    protected:
    private:
};

#endif // UNSORTED_MAP_H
