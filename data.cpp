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

Database::~Database() {
    if(db.isOpen()) {
        db.close();
        //cout << "closing db..." << endl;
    }
}

void Database::add_new_scientist(Person P) {

    QSqlQuery query(db);
    QString q = "CREATE TABLE IF NOT EXISTS scientists ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT , 'Name' TEXT NOT NULL , 'Gender' TEXT NOT NULL , 'DOB' INTEGER, 'DOD' INTEGER, 'Bio' TEXT)";
    query.exec(q);

    query.prepare("INSERT INTO scientists (Name, Gender, DOB, DOD, Bio ) VALUES(:name,:gender,:dob,:dod,:bio)");
    query.bindValue(":name", QString::fromStdString(P.getname()));
    query.bindValue(":gender", QString::fromStdString(P.getgender()));
    query.bindValue(":dob", P.getbirthyear());
    query.bindValue(":dod", P.getdeathyear());
    query.bindValue(":bio", QString::fromStdString(P.getbio()));
    query.exec();

    // VIRKAR!! Setur inn í Database-inn! JÍÍÍHAAA!

}

void Database::add_new_computer(Computer C) {

    QSqlQuery query(db);
    QString q = "CREATE TABLE IF NOT EXISTS computers ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT , 'Name' TEXT NOT NULL , 'BY' INTEGER, 'TYPE' TEXT NOT NULL, 'WB' TEXT NOT NULL)";
    query.exec(q);

    query.prepare("INSERT INTO computers (Name, BY, TYPE, WB ) VALUES(:name,:by,:type,:wb)");
    query.bindValue(":name", QString::fromStdString(C.getname()));
    query.bindValue(":by", C.getbuildyear());
    query.bindValue(":type", QString::fromStdString(C.gettype()));
    query.bindValue(":wb", QString::fromStdString(C.getwasbuilt()));
    query.exec();

    // VIRKAR!! Setur inn í Database-inn! JÍÍÍHAAA!

}
/* QSqlQuery query(db);

    if (!db.open())
    {
        cout << "Unable to open database. Will create a new one!" << endl;

        query.exec("CREATE TABLE 'scientists' ('ID' INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL UNIQUE, 'Name' TEXT NOT NULL , 'Gender' TEXT NOT NULL , 'DOB' INTEGER, 'DOD' INTEGER, 'Bio' TEXT)");
        query.exec("CREATE TABLE \"computers\" (\"ID\" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE, \"Name\" TEXT NOT NULL , \"Type\" INTEGER NOT NULL ,\"BuildYear\" INTEGER, \"Built\" CHAR NOT NULL)");
        query.exec("CREATE TABLE \"link\" (\"SID\" INTEGER NOT NULL PRIMARY KEY, \"CID\" INTEGER NOT NULL)");
    }
    */

vector<Person> Database::read_Scientist_from_DB()
{
    vector<Person> scientists;

    QSqlQuery query(db);
    query.exec("SELECT * FROM scientists");

    if(db.isOpen())
    {
        while(query.next()){
            Person sci;
            sci.readData(query);

            scientists.push_back(sci);
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
        while(query.next()){
            Computer comp;
            comp.readData(query);
            computer.push_back(comp);
        }
    }
    else {
        cerr << "Unable to open database!" << endl;
    }

    return computer;
}

