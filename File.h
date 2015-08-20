#ifndef FILE_H
#define FILE_H

#include "interface.h"
#include <string>
#include <vector>

using namespace std;
class File
{

    public:
        File();
        void file( string s,string file_name);
        void readFile(string file_name);
        void clearFile(string file_name);
        void saveFile(class Database &db,string file_name);
        void save_unsorted(class Database &db, string file_name);
        void save_sorted_tables(class Database& db,class SortedTable& st1, string file_name);
        void loadFile(class Database &db,string file_name);
        int check_if_file_is_empty(string file_name);
           string file_name1="example.txt";
           string file_name2="unsorted.txt";
    protected:
    private:
};

#endif // FILE_H
