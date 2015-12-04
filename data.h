#ifndef DATA_H
#define DATA_H

#include "person.h"
#include <vector>
#include <fstream>
#include <QtDebug>
#include <QtSql>

class Database {

// Klasi fyrir gagnalagið.  Skrifar út í skrá frá vektor og úr skrá í vektor.
// Vektorinn síðan tekinn og sendur inn í domain-lagið.

private:
    QSqlDatabase db;
public:
    Database();
    ~Database();
    void add_new_scientist(Person P);
    void write_to_DB(vector<Person> v);
    void connectToDatabase();
    vector<Person> read_from_DB();

};


#endif // DATA_H
