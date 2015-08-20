#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include "Database.h"
using namespace std;
class interface
{
    public:
        interface();
        string table_name;

        string file_temporary_sorted="sorted.txt";
        string file_temporary_unsorted="unsorted.txt";

        map<string, Database > data;


        string file_sorted_original="sorted_original.txt";
        string file_unsorted_original="unsorted_original.txt";

        string file_sorted_original_edited="sorted_original_edited.txt";
        string file_unsorted_original_edited="unsorted_original_edited.txt";
        vector<string>::iterator iter_table_names;

        void createDatabase(string database_name);
        void interfaceOptions();
        void copyFile();
        void check_input(int input);
        int  getInt();
        string  getStr();


    friend class File;
    protected:
    private:
};

#endif // INTERFACE_H
