#include "File.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>
#include "Database.h"
#include "interface.h"
#include "Unsorted_map.h"
#include "SortedTable.h"
#include <iomanip>
 File::File()
 {

 }
  File t;
void File::clearFile(string file_name)
{

    fstream myfile ;

    myfile.open(file_name.c_str(), std::fstream::out | std::fstream::trunc);
    myfile.close();

}
void File::file( string s,string file_name)
{

    fstream myfile(file_name.c_str(), std::ios::in | std::ios::out | std::ios::ate);

    if (myfile.is_open())
    {
        myfile << s;
        myfile.close();
    }
    else cout << "Unable to open file";

}


void File::save_sorted_tables(class Database& db,class SortedTable& st1,string file_name)
{
      for ( st1.iter_new_map = st1.new_map.begin(); st1.iter_new_map != st1.new_map.end(); st1.iter_new_map++)
      {

          string newline = st1.iter_new_map -> first;
          t.file ( "\n Table name: " + newline + "\n" ,file_name);

          for ( int i=0;i < db.column_names[newline].size() ;i++)
          {
              t.file ( "            " + db.column_names[newline][i],file_name );
          }

          t.file ( "\n",file_name);

          for ( db.itr = st1.iter_new_map->second.begin(); db.itr != st1.iter_new_map->second.end(); db.itr++)
          {

              t.file ( db.itr -> first,file_name );
              for(db.tc = db.itr->second.begin(); db.tc!=db.itr->second.end(); ++db.tc)
              {
                 t.file ( "           " + *db.tc ,file_name);
              }
              t.file ( "\n",file_name);
          }
          t.file ( "\n",file_name);

    }
}

void File::save_unsorted(class Database &db,string file_name)
{

    for (int i = 0; i < db.table_names.size(); i++)
        {

          string newline = db.table_names[i];

            t.file ( "\n Table name: " + newline + "\n" ,file_name);

                for ( int i=0;i < db.column_names[newline].size() ;i++)
            {

               t.file ( "            " + db.column_names[newline][i],file_name );

            }

            t.file ( "\n",file_name);

            int i=0;
            db.it = db.mymap.find(newline);
            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {


                    t.file ( db.row_names[newline][i],file_name );


                    for (db.tc = db.t->begin(); db.tc != db.t->end(); db.tc++)
                        {

                            t.file ( "           " + *db.tc ,file_name);
                        }
                    i++;

                    t.file ( "\n",file_name);
                }

        t.file ( "\n",file_name);

        }

}



void File::readFile(string file_name)

{
    fstream myfile;
    string line;
    myfile.open (file_name.c_str());
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            cout << line << endl;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}


int File::check_if_file_is_empty(string file_name)
{

    string line;
    vector<string> v;
    fstream myfile;
    myfile.open (file_name.c_str());
        while(getline(myfile, line))
        {
            v.push_back(line);
        }
    myfile.close();
    return v.size();
}



void File::loadFile(class Database &db, string file_name)
{

    vector<string> v;
    string line;
    string table_name;
    int counter;
    int row_counter=0;
    vector<string> tokens;
    fstream myfile;
    myfile.open (file_name.c_str());
    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            string str(line);
            string buf; // Have a buffer string
            stringstream ss(str); // Insert the string into a stream
            while (ss >> buf)
            {
                tokens.push_back(buf);
            }

            int found=line.find("Table name:");
            if(found != -1)
            {
                string name = tokens[2];
                table_name=name;
                db.createTable2(name, 0 , 0, "000");
                counter=0;
            }

            if(counter == 1)
            {
                for(int i = 0; i < tokens.size(); i++)
                {
                    db.column_names[table_name].push_back(tokens[i]);
                }
            }

            if(counter > 1 and tokens.size() != 0)
            {
                Table tb2;
                tb2.addRow2(db,table_name,tokens.size()-1 );
                db.row_names[table_name].push_back(tokens[0]);
                for(int i = 0; i < tokens.size()-1; i++)
                {
                    tb2.editTable2(db,counter-2,i, tokens[i+1], table_name);
                }
            }
            tokens.resize(0);
            counter++;
        }

    }
    myfile.close();

}

void File::saveFile(class Database &db, string file_name)
{


  /*  int i=0;
    for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {
            t.file ( "\n Table name: " + db.it -> first + "\n" );

            for (int i=0;i < db.column_names.size() ;i++)
            {
              t.file ( "   " + db.column_names[i] +  " ");
            }

            t.file ( "\n" );


            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {
                    t.file ( db.row_names[i] + " " );
                    i++;
                    for (db.tc = db.t->begin(); db.tc != db.t->end(); db.tc++)
                        {
                            t.file(*db.tc+"  ");
                        }

                    t.file("\n");
                }
        }
        t.file("\n"); */


    /*    int nob=0;

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
                        }


          //  cout << "max element at: " << distance(db.row_names.begin(),max_element(db.row_names.begin(),db.row_names.end(),myfn) ) << "\n";
           // int row_size = db.row_names[distance(db.row_names.begin(),max_element(db.row_names.begin(),db.row_names.end()) )].size();
          //  cout << row_size;
           // int nob = row_size;
          //  cout<<nob;

  //  cout << endl;
//    cout <<"in database: "<< n << endl; */


   // int no=0;

          //  db.it=db.mymap.find("ent");
         //   db.it->second.table[5-1][4]="m";

 //   int i=0,j=0;
 //    int table_no;
 //   int begin_column_names=0;
//    table_no=j;
    for ( db.it = db.mymap.begin(); db.it != db.mymap.end(); db.it++)
        {
   //     j++;
       // cout <<j<<endl;
     //   db.t = db.it->second.table.begin();


      //         int no_of_columns = db.t->size();







       //     cout <<"\n"<< "Table name: ";
        //    cout  << db.it -> first << endl;
          string newline = db.it -> first;
//find (myvector.begin(), myvector.end(), 30)


           // db.it=find(db.mymap.begin(),db.mymap.end(), newline);
        //   db.it=db.mymap.find(newline);

        //    int map_index=distance(db.mymap.begin(),db.mymap.find("city"));
        //    cout <<"this" << map_index;

            t.file ( "\n Table name: " + newline + "\n" ,file_name);
         /*   for(int i = 0; i < db.column_names.size(); i++)
            {
                cout << db.column_names[i];
            }
*/

           // for ( int i=begin_column_names;i < begin_column_names+no_of_columns ;i++)
                for ( int i=0;i < db.column_names[newline].size() ;i++)
            {
            //    cout << db.column_names[i];
            //  cout <<  setw(nob) << right <<  db.column_names[i] ;
               t.file ( "            " + db.column_names[newline][i],file_name );

            }
         //   cout << "\n";
            t.file ( "\n",file_name);
      //      begin_column_names += no_of_columns;
            int i=0;
            for(db.t = db.it->second.table.begin(); db.t!=db.it->second.table.end(); ++db.t)
                {

                //    cout<< setw(nob)<< right<<  db.row_names[i] ;
                    t.file ( db.row_names[newline][i],file_name );


                    for (db.tc = db.t->begin(); db.tc != db.t->end(); db.tc++)
                        {
                          //  cout << setw(nob)<<right<<  *db.tc ;
                            t.file ( "           " + *db.tc ,file_name);
                        }
                    i++;
                  //  cout << endl;
                    t.file ( "\n",file_name);
                }
       // cout << endl;
        t.file ( "\n",file_name);

        }
//cout <<"done";
}
