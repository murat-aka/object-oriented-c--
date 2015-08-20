#include <stdlib.h>
#include "Database.h"
#include "Table.h"
#include <iostream>
#include "interface.h"
#include "Unsorted_map.h"
#include "SortedTable.h"
#include "Ascii.h"
#include "File.h"
#include <fstream>

#include <string>
#include <sstream>
#include <locale>
#include <iomanip>
#include <limits>
using namespace std;

 Database db1;
 File fb1;
 Table tb1;
 SortedTable st1;

void interface::createDatabase(string database_name)
{
    Database db1;
    data[database_name]=db1;
}

int interface::getInt()
{
	int x = 0;

	while(!(cin >> x)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Invalid input.  Try again: ";
	}

	return x;
}

string interface::getStr()
{
	string x = "0";

	while(!(cin >> x)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Invalid input.  Try again: ";
	}

	return x;
}

void interface::check_input(int input)
{
    if (input == 23)
    {
        Ascii a1;
        interfaceOptions();
    }

    if (input == 0)
    {
        fb1.clearFile(file_temporary_sorted);
        fb1.clearFile(file_temporary_unsorted);
        fb1.saveFile(db1,file_temporary_sorted);
        fb1.save_unsorted(db1,file_temporary_unsorted);
        cout<<"\nThanks for using DATABASE 2013\n";
        exit(1)  ;
    }


}


interface::interface()
{
    ifstream ifile("unsorted_original.txt");
    if (!ifile)
    {
        ofstream myfile;
        myfile.open ("unsorted_original.txt");
        myfile.close();
    }

    int s=fb1.check_if_file_is_empty(file_temporary_unsorted.c_str());
    cout <<s;
    if(s!=0)
    copyFile();

   while(1)
    {
        Ascii a;
        cout << "Enter 00 at anytime to EXIT"  << endl;
        cout << "Enter 23 at anytime to RESTART\n"  << endl;


        system("PAUSE");

        Ascii b;

        interfaceOptions();

    }
}


void interface::interfaceOptions()
{
    cout<<" 1. Read File\n";
    cout<<" 2. Load File \n";
    cout<<" 3. Table\n";
    cout<<" 4. Row\n";
    cout<<" 5. Column\n";
    cout<<" 6. Database\n\n";

    cout<<"00. EXIT\n";
    cout<<"23. RESTART\n\n";


    cout<<"Selection: ";

    int input ;
    int choice;
    int col;


    input= getInt();

    check_input(input);
    if(input <0 or input > 6)
    {
        cout <<  "Selection not found \n\n";
        interfaceOptions();
    }


    switch ( input )
    {

        case 1:
        {
            cout << "1) original file  \n2) edited file\n";
            cout << "Choose: ";
            choice = getInt();
            check_input(choice);
            switch(choice)
            {
                case 1:
                fb1.readFile(file_unsorted_original);
                break;
                case 2:
                fb1.readFile(file_unsorted_original_edited);
                break;
            }
        }


        break;

        case 2:
        {
            cout << "1) original file  \n2) edited file\n";
            cout << "Choose: ";
            choice = getInt();
            check_input(choice);
            switch(choice)
            {
                case 1:
                fb1.loadFile(db1,file_unsorted_original);
                fb1.readFile(file_unsorted_original);
                break;
                case 2:
                fb1.loadFile(db1,file_unsorted_original_edited);
                fb1.readFile(file_unsorted_original_edited);
                break;
                cout <<  "Selection not found \n\n";
            }

        }
        break;

        case 3:
            cout<<" 7. create Table\n";
            cout<<" 8. edit Table\n";
            cout<<" 9. delete Table\n";
            cout<<"10. print Table\n";
            cout<<"Selection: ";
            input=getInt();
            check_input(input);
        break;

        case 4:
            cout<<"11. add Row\n";
            cout<<"12. swap Row\n";
            cout<<"13. delete Row\n";
            cout<<"14. print Row\n";
            cout<<"Selection: ";
            input=getInt();
            check_input(input);
        break;

        case 5:
            cout<<"15. add Column\n";
            cout<<"16. delete Column\n";
            cout<<"17. print Column\n";
            cout<<"Selection: ";
            input=getInt();
            check_input(input);
        break;

        case 6:
            cout<<"18. Save unsorted Database\n";
            cout<<"19. Print unsorted Database\n";
            cout<<"20. Save sorted Database\n";
            cout<<"21. Print sorted Database\n";
            cout<<"22. delete Database\n";
            cout<<"Selection: ";
            input=getInt();
            check_input(input);
        break;

    }

    switch ( input )
    {
        case 7:
        {
            cout<<"enter table name: ";
            table_name=getStr();
            cout <<"Enter number of rows and then columns. \n";
            cout <<"Enter number of rows: ";
            int row;
            row=getInt();
            cout <<"Enter number of columns: ";
            int col;
            col=getInt();
            db1.createTable(table_name, row , col, "est");
            fb1.saveFile(db1,file_temporary_sorted);

        }
        break;

        case 8:
        {

            cout <<"\n"<< "Table names: ";
            for ( db1.it = db1.mymap.begin(); db1.it != db1.mymap.end(); db1.it++)
            {
                cout  << setw(10) << db1.it -> first ;
            }
            cout << "\nEnter the table name: ";
             table_name=getStr();
            if (db1.mymap.count(table_name)>0)
            {
                tb1.printTable2(db1,"db1",table_name);
                cout << "\nEnter the  row number and column number to edit: \n";
                cout << "row no: ";
                int row;
                 row=getInt();
                cout << "column no: ";
                int col;
                col=getInt();
                cout << "Change to: ";
                string change;
                cin>>change;
                tb1.editTable2(db1, row-1 , col-1 , change, table_name );
                tb1.printTable2(db1,"db1",table_name);
            }
            else cout << "table doesn't exist! \n";
        }
        break;

        case 16:
        {
            string table_name;
            cout <<"\n"<< "Table names: ";
            for ( db1.it = db1.mymap.begin(); db1.it != db1.mymap.end(); db1.it++)
            {
                cout  << setw(10) << db1.it -> first ;
            }
            cout << "\nEnter the table name: ";
             table_name=getStr();
            tb1.printTable2(db1, "db1", table_name);
            cout << "enter the column number to delete: ";
             col=getInt();
            tb1.deleteCol(db1,col-1, table_name);
            tb1.printTable2(db1, "db1", table_name);
        }break;

        case 17:
        {
            tb1.printCol(db1);
        }
        break;

        case 15:
        {
            cout <<"\n"<< "Table names: ";
            for ( db1.it = db1.mymap.begin(); db1.it != db1.mymap.end(); db1.it++)
            {
                cout  << setw(10) << db1.it -> first ;
            }
            string table_name;
            cout << "\nEnter the table name: ";
            table_name=getStr();
            tb1.printTable2(db1, "db1", table_name);
            cout << "enter the column number: ";
            col = getInt();
            tb1.addCol(db1,col-1,table_name);
            tb1.printTable2(db1, "db1", table_name);
        }
        break;

        case 14:
        {
            cout <<"\n"<< "Table names: ";
            for ( db1.it = db1.mymap.begin(); db1.it != db1.mymap.end(); db1.it++)
            {
                cout  << setw(10) << db1.it -> first ;
            }

            string table_name;
            cout << "\nEnter the table name: ";
            table_name=getStr();
            tb1.printTable2(db1, "db1", table_name);
            tb1.printRow(db1,table_name);
        }
        break;

        case 11:
        {
            cout <<"\n"<< "Table names: ";
            for ( db1.it = db1.mymap.begin(); db1.it != db1.mymap.end(); db1.it++)
            {
                cout  << setw(10) << db1.it -> first ;
            }

            string table_name;
            cout << "\nEnter the table name: ";
            table_name=getStr();
            tb1.printTable2(db1, "db1", table_name);
            cout << "enter the row number: ";
            col=getInt();
            tb1.addRow(db1, col-1,table_name);
            tb1.printTable2(db1, "db1", table_name);
        }
        break;

        case 10:
            tb1.printTable(db1,"db1");
        break;


        case 13:
        {
            cout <<"\n"<< "Table names: ";
            for ( db1.it = db1.mymap.begin(); db1.it != db1.mymap.end(); db1.it++)
            {
                cout  << setw(10) << db1.it -> first ;
            }

            string table_name;
            cout << "\nEnter the table name: ";
            table_name=getStr();
            tb1.printTable2(db1, "db1", table_name);
            cout << "enter the row number: ";
            col = getInt();
            tb1.deleteRow(db1, col-1,table_name);
            tb1.printTable2(db1, "db1", table_name);

        }
        break;

        case 12:
            tb1.swapRow(db1);
        break;

        case 9:
            tb1.deleteTable(db1);
        break;


        case 22:

            db1.mymap.clear();
            db1.column_names.clear();
            db1.row_names.clear();

        break;

        case 19:
        {
            for (iter_table_names=db1.table_names.begin(); iter_table_names!=db1.table_names.end(); ++iter_table_names)
            tb1.printTable2(db1,"db1", *iter_table_names);
        }
        break;

        case 18:
        {
            fb1.clearFile( file_unsorted_original);
            fb1.save_unsorted(db1,file_unsorted_original);
            fb1.readFile(file_unsorted_original);
        }
        break;

        case 21:
            st1.sort_tables(db1);
            st1.print_sorted_tables(db1);
        break;

        case 20:
            fb1.clearFile( file_sorted_original);
            st1.sort_tables(db1);
            fb1.save_sorted_tables(db1,st1,file_sorted_original);
        break;




    }
}


void interface::copyFile()
{
  /* stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream */
    ifstream ifile("unsorted_original_edited.txt");
    if (!ifile)
    {
        ofstream myfile;
        myfile.open ("unsorted_original_edited.txt");
        myfile.close();
    }

    ifstream ifs("unsorted.txt", std::ios::binary);
    ofstream ofs("unsorted_original_edited.txt", std::ios::binary);
    ofs << ifs.rdbuf();
    ifs.close();
    ofs.close();

    /* ifstream read("sorted.txt");
    bool isEmpty = read.peek() == EOF;
    cout  << "test is empty = " << isEmpty<<endl;
    read.close();
    if(isEmpty=0)
    {

    }
    */
}
