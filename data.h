#ifndef DATA_H
#define DATA_H

#include "person.h"
#include "computer.h"
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
    void add_new_computer(Computer C);
    void write_to_DB(vector<Person> v);
    void write_to_DB(vector<Computer> ve);
    void connectToDatabase();
    vector<Person> read_Scientist_from_DB();
    vector<Computer> read_Computer_from_DB();

};


#endif // DATA_H
