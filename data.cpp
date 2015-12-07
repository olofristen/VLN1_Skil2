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
    //cout << "opening db..." << endl;
}

Database::~Database()
{
    if(db.isOpen()) {
        db.close();
        //cout << "closing db..." << endl;
    }
}

void Database::add_new_scientist(Person P)
{
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

void Database::add_new_computer(Computer C)
{
    QSqlQuery query(db);
    QString q = "CREATE TABLE IF NOT EXISTS computers ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT, 'Name' TEXT NOT NULL , 'Type' TEXT NOT NULL, 'WB' BOOL NOT NULL, 'BuildYear' INTEGER, 'Info' TEXT NOT NULL)";
    query.exec(q);

    query.prepare("INSERT INTO computers (Name, Type, WB, BuildYear, Info) VALUES(:name,:type,:wb,:buildyear,:info)");
    query.bindValue(":name", QString::fromStdString(C.getname()));
    query.bindValue(":type", QString::fromStdString(C.gettype()));
    query.bindValue(":wb", C.getwasbuilt());
    query.bindValue(":buildyear", C.getbuildyear());
    query.bindValue(":info", QString::fromStdString(C.getinfo()));
    query.exec();
}

void Database::add_new_link(pair<Person, Computer> link)
{
    QSqlQuery query(db);
    QString q = "CREATE TABL<E links ('SID' INTEGER, 'CID' INTEGER, FOREIGN KEY (SID) REFERENCES scientists(ID), FOREIGN KEY (CID) REFERENCES computers(ID), PRIMARY KEY(SID, CID))";
    query.exec(q);

    query.prepare("INSERT INTO links (SID, CID) VALUES ((SELECT ID FROM scientists WHERE Name LIKE '%:sname%'), (SELECT ID FROM computers WHERE Name LIKE '%:cname%'))");

    query.bindValue(":sname", QString::fromStdString(link.first.getname()));
    query.bindValue(":cname", QString::fromStdString(link.second.getname()));
    query.exec();
}


vector<Person> Database::read_Scientist_from_DB()
{
    vector<Person> scientists;
    QSqlQuery query(db);
    query.exec("SELECT * FROM scientists");

    if(db.isOpen())
    {
        while(query.next()){
            scientists.push_back(Person(query));        // So beautiful..
        }
    }
    else {
        cerr << "Unable to open database!" << endl;
    }

    return scientists;
}

vector<Computer> Database::read_Computer_from_DB()
{
    vector<Computer> computer;

    QSqlQuery query(db);
    query.exec("SELECT * FROM computers");

    if(db.isOpen())
    {
        while(query.next())
        {
            computer.push_back(Computer(query));        // Oh, so pretty...
        }
    }
    else {
        cerr << "Unable to open database!" << endl;
    }

    return computer;
}
