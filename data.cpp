#include "person.h"
#include "data.h"
#include <QString>

// Database layer (ifstream/ofstream,read/write,...)

Database::Database()        // Database búinn til/opnaður í constructor
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbSoC = "database.sqlite";
    db.setDatabaseName(dbSoC);

    db.open();
    cout << "opening db..." << endl;
}

Database::~Database() {
    if(db.open()) {
        db.close();
        cout << "closing db..." << endl;
    }
}

void Database::add_new_scientist(Person P) {

    QSqlQuery query(db);
    QString q = "CREATE TABLE IF NOT EXISTS scientists ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT UNIQUE, 'Name' TEXT NOT NULL , 'Gender' TEXT NOT NULL , 'DOB' INTEGER, 'DOD' INTEGER, 'Bio' TEXT)";
    query.exec(q);

    query.prepare("INSERT INTO scientists (Name, Gender, DOB, DOD, Bio ) VALUES(:name,:gender,:dob,:dod,:bio)");
    query.bindValue(":name", QString::fromStdString(P.getname()));
    query.bindValue(":gender", QString::fromStdString(P.getgender()));
    query.bindValue(":dob", P.getbirthyear());
    query.bindValue(":dod", P.getdeathyear());
    query.bindValue(":bio", QString::fromStdString(P.getbio()));
    query.exec();
}

void Database::add_new_computer(Computer C) {

    QSqlQuery query(db);
    QString q = "CREATE TABLE IF NOT EXISTS computers ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT UNIQUE, 'Name' TEXT NOT NULL , 'Type' TEXT NOT NULL, 'WB' BOOL NOT NULL, 'BuildYear' INTEGER, 'Info' TEXT NOT NULL)";
    query.exec(q);

    query.prepare("INSERT INTO computers (Name, Type, WB, BuildYear, Info) VALUES(:name,:type,:wb,:buildyear,:info)");
    query.bindValue(":name", QString::fromStdString(C.getname()));
    query.bindValue(":type", QString::fromStdString(C.gettype()));
    query.bindValue(":wb", C.getwasbuilt());
    query.bindValue(":buildyear", C.getbuildyear());
    query.bindValue(":info", QString::fromStdString(C.getinfo()));
    query.exec();
}

vector<Person> Database::read_Scientist_from_DB()
{

    vector<Person> v;

    Database();

    if(db.is_open())
    {
        while(!db.eof())
        {
            Person a;
            a.readData(db);       //

            v.push_back(a);
        }
        v.erase(v.end()-1);     //Skip the last newline ('\n') character, it would make a new (empty) person class
    }
    else
        cerr << "Unable to open file" << endl;

    db.close();
    return v;

}

vector<Computer> Database::read_Computer_from_DB()
{

    vector<Computer> ve;

    Database();

    if(db.is_open())
    {
        while(!db.eof())
        {
            Computer a;
            a.readData(file);       //

            ve.push_back(a);
        }
        ve.erase(ve.end()-1);     //Skip the last newline ('\n') character, it would make a new (empty) person class
    }
    else
        cerr << "Unable to open file" << endl;

    db.close();
    return ve;

}

void Database::write_to_DB(vector<Person> v)
{
    Database();

    if(db.is_open())
    {
        for(unsigned int i = 0; i < v.size(); i++)
        {
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

void Database::write_to_DB(vector<Computer> ve)
{
    ofstream file;
    file.open("database.csv", ios::out);

    if(file.is_open())
    {
        for(unsigned int i = 0; i < ve.size(); i++) {

            file << ve[i].getname() << endl;
            file << ve[i].getbuildyear() << endl;
            file << ve[i].gettype() << endl;
            file << ve[i].getwasbuilt() << endl;
        }

    }
    else
        cerr << "Unable to open file";

    file.close();
}
