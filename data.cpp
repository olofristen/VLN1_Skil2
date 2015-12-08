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

unsigned int Database::addNewScientist(Person P)
{
    QSqlQuery query(db);
    QString q = "CREATE TABLE IF NOT EXISTS scientists ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT, 'Name' TEXT NOT NULL , 'Gender' TEXT NOT NULL , 'DOB' INTEGER, 'DOD' INTEGER, 'Bio' TEXT)";
    query.exec(q);

    query.prepare("INSERT INTO scientists (Name, Gender, DOB, DOD, Bio ) VALUES(:name,:gender,:dob,:dod,:bio)");
    query.bindValue(":name", QString::fromStdString(P.getName()));
    query.bindValue(":gender", QString::fromStdString(P.getGender()));
    query.bindValue(":dob", P.getBirthYear());
    query.bindValue(":dod", P.getDeathYear());
    query.bindValue(":bio", QString::fromStdString(P.getBio()));

    query.exec();
    query.prepare("SELECT ID FROM scientists WHERE Name = :name");        //4
    query.bindValue(":name", QString::fromStdString(P.getName()));
    query.exec();
    if(query.next())
    {
        return query.value("ID").toInt();
   }
}

unsigned int Database::addNewComputer(Computer C)
{
    QSqlQuery query(db);
    QString q = "CREATE TABLE IF NOT EXISTS computers ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT, 'Name' TEXT NOT NULL , 'Type' TEXT NOT NULL, 'WB' BOOL NOT NULL, 'BuildYear' INTEGER, 'Info' TEXT NOT NULL)";
    query.exec(q);

    query.prepare("INSERT INTO computers (Name, Type, WB, BuildYear, Info) VALUES(:name,:type,:wb,:buildyear,:info)");
    query.bindValue(":name", QString::fromStdString(C.getName()));
    query.bindValue(":type", QString::fromStdString(C.getType()));
    query.bindValue(":wb", C.getWasBuilt());
    query.bindValue(":buildyear", C.getBuildYear());
    query.bindValue(":info", QString::fromStdString(C.getInfo()));
    query.exec();

    query.prepare("SELECT ID FROM computers WHERE Name = :name");        //4
    query.bindValue(":name", QString::fromStdString(C.getName()));

    query.exec();
    if(query.next())
    {
        return query.value("ID").toInt();
   }
}

void Database::addNewLink(pair<Person, Computer> link)
{
    QSqlQuery query(db);
    QString q = "CREATE TABLE links ('SID' INTEGER, 'CID' INTEGER, FOREIGN KEY (SID) REFERENCES scientists(ID), FOREIGN KEY (CID) REFERENCES computers(ID), PRIMARY KEY(SID, CID))";
    query.exec(q);

    query.prepare("INSERT INTO links (SID, CID) VALUES (:sid, :cid)");

    query.bindValue(":sid", link.first.getId());
    query.bindValue(":cid", link.second.getId());
    query.exec();

}


vector<Person> Database::readScientistFromDb()
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

vector<Computer> Database::readComputerFromDb()
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
vector<pair<Person, Computer>> Database::readLinkFromDb()   //VIRKAR ÓMÆGAD!
{
    vector<pair<Person, Computer>> vlink;

    QSqlQuery query(db);
    QString q = "SELECT * FROM links L, scientists S, computers C WHERE S.ID = L.SID AND C.ID = L.CID";
    query.exec(q);
    while(query.next())
    {
        //int ID = query.value("S.ID").toUInt();
        string name = query.value(3).toString().toStdString();
        string gender = query.value(4).toString().toStdString();
        int birthYear = query.value(5).toInt();
        int deathYear = query.value(6).toInt();
        string bio = query.value(7).toString().toStdString();
        Person P = Person(name, gender, birthYear, deathYear, bio);
        P.setId(query.value(2).toInt());

        //ID = query.value("ID").toInt();
        name = query.value(9).toString().toStdString();
        string type = query.value(10).toString().toStdString();
        bool wasBuilt = query.value(11).toBool();
        int buildYear = query.value(12).toInt();
        string info = query.value(13).toString().toStdString();
        Computer C = Computer(name, type, wasBuilt, buildYear, info);
        C.setId(query.value(8).toInt());

        vlink.push_back(make_pair(P,C));
    }
    return vlink;
}
