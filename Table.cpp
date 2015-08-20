//
//
//  on 15/03/13.
//  . All rights reserved.
//

#include "Database.h"
#include <map>
#include <iostream>
#include "Table.h"
#include <algorithm>
#include "File.h"
#include <vector>
#include <string>
#include <iomanip>

Table::Table(int in_row, int in_col, string initValue): row(in_row), col(in_col), select_row(0), select_col(0) {

    table.resize(row);

    vector<string> tb_row(col,initValue);
    for (int i = 0; i < row; i++) {
        table[i] = tb_row;
    }
}

Table::Table(int in_row, int in_col, int initValue): row(in_row), col(in_col), select_row(0), select_col(0) {
    table.resize(row);

    vector<int> tb_row(col,initValue);
    for (int i = 0; i < row; i++) {
//        table[i] = tb_row;
    }
}

Table::Table(int in_side, double initValue): row(in_side), col(in_side), select_row(0), select_col(0) {
    table.resize(row);

   /* vector<string> tb_row(col,initValue);
    for (int i = 0; i < col; i++) {
        table[i] = tb_row;
    } */
}

Table::Table(int in_row, int in_col): row(in_row), col(in_col), select_row(0), select_col(0) {
    table.resize(row);

    vector<double> tb_row(col,0);
    for (int i = 0; i < row; i++) {
//        table[i] = tb_row;
    }

}

Table::Table():row(0), col(0), select_row(0), select_col(0) {

}



void Table::select(int in_row, int in_col) {
    select_row = in_row;
    select_col = in_col;
}

void Table::insert(double value) {
    table[select_row][select_col] = value;
}

void Table::insert(int in_row, int in_col, double value) {
    table[in_row][in_col] = value;
}

void Table::deleteRow(int rowIndex) {
    table.erase(table.begin()+rowIndex);
}

void Table::deleteCol(class Database& db,int colIndex, string table_name) {



        if (db.mymap.count(table_name)>0)
        {

        db.it=db.mymap.find(table_name);
        for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {
                    db.t->erase(db.t->begin() + colIndex);
                }
        db.column_names[table_name].erase(db.column_names[table_name].begin()+colIndex);
        }
        else
        cout << "table doesn't exist! \n";

}

void Table::addCol(class Database& db,int colIndex,string table_name) {

      cout << "Enter the column name: ";
      string txt;
      cin >> txt;

       if (db.mymap.count(table_name)>0)
       {   db.column_names[table_name].insert(db.column_names[table_name].begin() + colIndex, txt);
           db.it=db.mymap.find(table_name);
        for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {
                    db.t->insert(db.t->begin() + colIndex,"000");
                }
       }
        else
        cout << "table doesn't exist! \n";


}

void Table::addRow(class Database& db,int rowIndex,string table_name) {

  /*  int no;

    for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {
            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {
                    no = db.t->size();
                    cout << no;
                }
        } */

      cout << "Enter the row name: ";
      string txt;
      cin >> txt;

       vector<string> myvector(db.column_names[table_name].size(),"000");

        if (db.mymap.count(table_name)>0)
        {
            db.row_names[table_name].insert(db.row_names[table_name].begin() + rowIndex, txt);
             db.it=db.mymap.find(table_name);
        db.it -> second.table.insert(db.it->second.table.begin()+ rowIndex, myvector);
        }

        else
        cout << "table doesn't exist! \n";



    }

    void Table::addRow2(class Database& db,string table_name,int no_of_columns) {

  /*  int no;

    for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {
            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {
                    no = db.t->size();
                    cout << no;
                }
        } */




      vector<string> myvector(no_of_columns,"000");

        if (db.mymap.count(table_name)>0)
        {

             db.it=db.mymap.find(table_name);
        db.it->second.table.push_back(myvector);
        }

        else
        cout << "table doesn't exist! \n";



    }

void Table::deleteRow(class Database& db,int rowIndex,string table_name) {


        if (db.mymap.count(table_name)>0)
        {
            db.it=db.mymap.find(table_name);
        db.it->second.table.erase(db.it->second.table.begin() + rowIndex);
        db.row_names[table_name].erase(db.row_names[table_name].begin()+ rowIndex);
        }

        else
        cout << "table doesn't exist! \n";


}

void Table::printRow(class Database& db,string table_name) {

        //  db.it=db.mymap.find("ent");
         //   db.it->second.table[5-1][4]="m";

        if (db.mymap.count(table_name)>0)
        {


        db.it=db.mymap.find(table_name);
        cout <<"\n"<< "Table name: ";

            cout  << db.it -> first << endl;
            cout << "Enter the row name: ";
            string txt;
            cin >> txt;
            cout << "\n";



            for (int i=0;i< db.column_names[table_name].size();i++)
                {
            cout <<setw(10) << db.column_names[table_name][i] ;
                }
            cout << "\n";


            db.tc = find(db.row_names[table_name].begin(),db.row_names[table_name].end(),txt);
            int rowIndex=distance(db.row_names[table_name].begin(), db.tc);

            db.t = db.it->second.table.begin()+rowIndex;
            cout << db.row_names[table_name][rowIndex] ;


            for (db.tc = db.t->begin(); db.tc != db.t->end(); db.tc++)
                        {
                            cout <<setw(10) << *db.tc ;
                        }

        }
        else
        cout << "table doesn't exist! \n";






        }

void Table::printCol(class Database& db) {

 cout <<"\n"<< "Table names: ";
     for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {

            cout  << setw(10) << db.it -> first ;

        }
        cout << "\nEnter the table name: ";
       cin >> table_name;

        if (db.mymap.count(table_name)>0)
        {


        db.it=db.mymap.find(table_name);
       printTable2(db,"db1",table_name);

            cout << "Enter the column name: ";
            string txt;
            cin >> txt;


            db.tc = find(db.column_names[table_name].begin(),db.column_names[table_name].end(),txt);
            int colIndex= distance(db.column_names[table_name].begin(), db.tc);


            cout << "\n" << db.column_names[table_name][colIndex] <<endl;


            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {
                    db.tc = db.t->begin()+colIndex;
                    cout << *db.tc<< endl;
                }
        }
        else
        cout << "table doesn't exist! \n";



}

void Table::editTable(Database& db,int row,int col, string value, string table_name)

{


        if (db.mymap.count(table_name)>0)
        {

            db.it=db.mymap.find(table_name);
          //  cout << "here";
        db.it->second.table[row][col]= value;
        }

        else
        cout << "table doesn't exist! \n";



}

void Table::editTable2(Database& db,int row,int col, string value,string table_name)
{

        if (db.mymap.count(table_name)>0)
        {

            db.it=db.mymap.find(table_name);
           // cout << "here";
        db.it->second.table[row][col]= value;
        }

        else
        cout << "table doesn't exist! \n";



}

 void Table::printDatabase(class Database& db, string n)
{

/*
int nob=0;

for (db.tc = db.row_names.begin(); db.tc != db.row_names.end(); db.tc++)
                        {

                            if ( db.tc->length() > nob )
                                {
                                    nob = db.tc->size();
                                }
                        }

for (db.tc = db.column_names.begin(); db.tc != db.column_names.end(); db.tc++)
                        {

                            if ( db.tc->length() > nob )
                                {
                                    nob = db.tc->size();
                                }
                        } */


          //  cout << "max element at: " << distance(db.row_names.begin(),max_element(db.row_names.begin(),db.row_names.end(),myfn) ) << "\n";
           // int row_size = db.row_names[distance(db.row_names.begin(),max_element(db.row_names.begin(),db.row_names.end()) )].size();
          //  cout << row_size;
           // int nob = row_size;
          //  cout<<nob;

    cout << endl;
    cout <<"in database: "<< n << endl;


   // int no=0;

          //  db.it=db.mymap.find("ent");
         //   db.it->second.table[5-1][4]="m";




    for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {

       // cout <<j<<endl;
      //  db.t = db.it->second.table.begin();

            //    int no_of_columns = db.t-> size();


            cout <<"\n"<< "Table name: ";
            cout  << db.it -> first << endl;

            cout << setw(10) << "-" ;
//cout <<db.column_names[db.it -> first].size();
            for (int i=0;i < db.column_names[db.it -> first].size() ;i++)
            {
              cout <<  setw(10) <<  db.column_names[db.it -> first][i] ;
            }
            cout << "\n";
            //cout<< "done";
          //  begin_column_names += no_of_columns;

            int j=0;
            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {

                    cout<< setw(10)<<   db.row_names[db.it -> first][j] ;


                    for (db.tc = db.t->begin(); db.tc != db.t->end(); db.tc++)
                        {
                            cout << setw(10)<<  *db.tc ;
                        }
                    j++;
                    cout << endl;
                }
        cout << endl;

        }


}


void Table::printTable(class Database &db, string n)
 {

     cout <<"\n"<< "Table names: ";
     for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
     {
          cout  << setw(10) << db.it -> first ;
     }

     cout << endl;
     cout <<"in database: "<< n << endl;
     cout << "Enter the table name: ";
     cin >> table_name;

     if (db.mymap.count(table_name)>0)
     {

        db.it=db.mymap.find(table_name);
        cout <<"\n"<< "Table name: ";
        cout  << db.it -> first << endl;
        cout << setw(10) << "-" ;

        for (int i=0;i < db.column_names[table_name].size() ;i++)
        {
            cout <<setw(10) << db.column_names[table_name][i] ;
        }
        cout << "\n";

        int i=0;
        for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
        {
            cout<< setw(10)<<   db.row_names[table_name][i] ;

            i++;
            for (db.tc = db.t->begin(); db.tc != db.t->end(); db.tc++)
            {
                cout << setw(10)<<  *db.tc ;
            }
            cout << endl;

        }
    }
    else cout << "table doesn't exist! \n";

}

void Table::printTable2(class Database &db, string n, string table_name)
 {

    cout << endl;
    cout <<"in database: "<< n << endl;



            db.it=db.mymap.find(table_name);
            cout <<"\n"<< "Table name: ";
            cout  << db.it -> first << endl;
            cout << setw(10) << " " ;
       //     for (int i=begin_column_names;i < (begin_column_names) + db.it->second.table.begin()->size() ;i++)
       for (int i=0;i < db.column_names[table_name].size() ;i++)
            {
              cout <<setw(10) << db.column_names[table_name][i] ;
            }
            cout << "\n";



            int i=0;
            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {
                    cout<< setw(10)<<   db.row_names[table_name][i] ;

                    i++;
                    for (db.tc = db.t->begin(); db.tc != db.t->end(); db.tc++)
                        {
                            cout << setw(10)<<  *db.tc ;
                        }
                    cout << endl;
                }


}

void Table::swapRow(class Database& db) {

        //  db.it=db.mymap.find("ent");
         //   db.it->second.table[5-1][4]="m";
         // cout <<"\n"<< "Table names: ";
         cout <<"\n"<< "Table names: ";
     for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {

            cout  << setw(10) << db.it -> first ;

        }

       cout << "\nEnter the table name: ";
       cin >> table_name;


        if (db.mymap.count(table_name)>0)
        {
           Table tb1;
           tb1.printTable2(db,"db1",table_name);



         //   cout << "\nEnter the row name followed by the row number. \n";
            cout << "Enter the row name: ";
            string txt;
            cin >> txt;

       //      int begin_column_names=0;
       //      int begin_row_names=0;
           /*  for ( db.it = db.mymap.begin(); db.it != db.mymap.find(table_name); db.it++)
                {
/*
                    db.t = db.it->second.table.begin();

                int no_of_columns = db.t-> size();
                int no_of_rows= db.it->second.table.size();

            begin_column_names += no_of_columns;
            begin_row_names += no_of_rows;

                } cout << begin_row_names;

         /*     cout << "Enter the row number: ";
            int row_index;
            cin >> row_index; */
            cout << "Enter the row name to swap with: ";
             string txt1;
            cin >> txt1;
            /*
            cout << "Enter the row number to swap with: ";
            int row_index2;
            cin >> row_index2; */
            cout << "\n";


            db.tc = find(db.row_names[table_name].begin(),db.row_names[table_name].end(),txt);
            int rowIndex=distance(db.row_names[table_name].begin(), db.tc);
           // cout << rowIndex;
          //  int mapIndex=rowIndex-begin_row_names;

            db.tc = find(db.row_names[table_name].begin(),db.row_names[table_name].end(),txt1);
            int rowIndex2=distance(db.row_names[table_name].begin(), db.tc);
           // cout << rowIndex2;
         //   cout << begin_row_names;

         //   int mapIndex2=rowIndex2-begin_row_names;
         //   cout << mapIndex2;
       //         cout<<"mapIndex: "<<mapIndex;

            std::iter_swap( &db.row_names[table_name][ rowIndex ], &db.row_names[table_name][ rowIndex2 ] );

          //  cout<<"rowIndex: "<<rowIndex;
          // db.t = db.it->second.table.begin()+ rowIndex;
         //  std::iter_swap( db.it->second.table.begin()+ row_index-1, db.it->second.table.begin()+(row_index2-1) );
           std::iter_swap( db.it->second.table.begin()+ rowIndex, db.it->second.table.begin()+(rowIndex2) );
            /* db.t3(->db.t);
            db.t2 = db.it->second.table.begin()+1;

            db.row_names[rowIndex]=txt;
            db.row_names[rowIndex]=db.row_names[rowIndex+1];
            db.row_names[rowIndex+1]=txt;
            *db.t=*db.t2;
            *db.t2=*db.t3; */

            cout<<"done\n";
              tb1.printTable2(db,"db1",table_name);


        }
        else
        cout << "table doesn't exist! \n";

        }

void Table::deleteTable(class Database& db)
{

cout <<"\n"<< "Table names: ";
     for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {

            cout  << setw(10) << db.it -> first ;

        }

    cout << "\nEnter the table name to be deleted: ";
       cin >> table_name;

        if (db.mymap.count(table_name)>0)
        {

        db.it=db.mymap.find(table_name);
        db.mymap.erase(db.it);
        cout << table_name << " deleted ";
        }
        else
        cout << "table doesn't exist! \n";

}


void Table::insertRow(vector<string> tableRow, int rowIndex) {
   table.insert(table.begin() + rowIndex, tableRow);
}



/* ostream& operator<< (ostream& s, Table &tb1)
 {

    for(tb1.t = tb1.it -> second.table.begin(); tb1.t!= tb1.it -> second.table.end(); ++tb1.t)
                {
                    for (db1.tc = db1.t->begin(); db1.tc != db1.t->end(); db1.tc++)
                        {
                            s <<*db1.tc;

                        }
                    s << endl;
                }
    return s;

} */

