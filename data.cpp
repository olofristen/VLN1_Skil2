#include <fstream>
#include <vector>
#include <QtSql>
#include <QtDebug>
#include "person.h"
#include "data.h"

// Database layer (ifstream/ofstream,read/write,...)

void Database::connectToDatabase()
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        QString dbSoC = "database.sqlite";
        db.setDatabaseName(dbSoC);

        db.open();

        QSqlQuery query(db);

        if (!db.open())
        {
            cout << "Unable to open database. Will create a new one!" << endl;

            query.exec("CREATE DATABASE database");
            query.exec("CREATE TABLE 'scientists' ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL UNIQUE, 'Name' TEXT NOT NULL , 'Gender' TEXT NOT NULL , 'DOB' INTEGER, 'DOD' INTEGER, 'Bio' TEXT)");
            query.exec("CREATE TABLE \"computers\" (\"ID\" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE, \"Name\" TEXT NOT NULL , \"Type\" INTEGER NOT NULL ,\"BuildYear\" INTEGER, \"Built\" CHAR NOT NULL)");
            query.exec("CREATE TABLE \"link\" (\"SID\" INTEGER NOT NULL PRIMARY KEY, \"CID\" INTEGER NOT NULL)");
        }
}

vector<Person> Database::read_from_DB()
{

    /*vector<Person> v;

    ifstream file;
    file.open("database.csv");

    if(file.is_open())
    {
        while(!file.eof())
        {
            Person a;
            a.readData(file);       //

            v.push_back(a);
        }
        v.erase(v.end()-1);     //Skip the last newline ('\n') character, it would make a new (empty) person class
    }
    else
        cerr << "Unable to open file" << endl;

    file.close();
    return v;*/

}

void Database::write_to_DB(vector<Person> v)
{
    ofstream file;
    file.open("database.csv", ios::out);

    if(file.is_open())
    {
        for(unsigned int i = 0; i < v.size(); i++) {

            file << v[i].getname() << endl;
            file << v[i].getgender() << endl;
            file << v[i].getbirthyear() << endl;
            file << v[i].getdeathyear() << endl;
            file << v[i].getbio() << endl;
        }

    }
    else
        cerr << "Unable to open file";

    file.close();
}
