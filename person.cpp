#include "person.h"

bool Person::operator < (const Person &r) {
     return this->name < r.name;
}

Person::Person()
{
    ID = 0;
    name = " ";
    gender = " ";
    birthYear = 0;
    deathYear = 0;
    bio = " ";
}

Person::Person(string name, string gender, int birthYear, int deathYear, string bio)
{
    this->name = name;
    this->gender = gender;
    this->birthYear = birthYear;
    this->deathYear = deathYear;
    this->bio = bio;
}

Person::Person(QSqlQuery query)
{
    readData(query);
}

string Person::getname()
{
    return name;
}

string Person::getgender()
{
    return gender;
}

int Person::getbirthyear()
{
    return birthYear;
}

int Person::getdeathyear()
{
    return deathYear;
}

string Person::getbio()
{
    return bio;
}
int Person::getID()
{
    return ID;
}

ostream& operator << (ostream& out, const Person& P)
{
    out << "ID: "  << P.ID << endl;
    out << "Name: " << P.name << endl
         << "Gender: " << P.gender << endl
         << "Year of birth: " << P.birthYear << endl;
    if(P.deathYear == -1) {
        out << "Alive and well!" << endl;
    }
    else {
        out << "Year of death: " << P.deathYear << endl;
    }
    out << endl << "Bio: " << P.bio << endl
         << "------------------------------------------------------------------" << endl;
    return out;
}

void Person::readData(QSqlQuery query)
{
    ID = query.value("ID").toUInt();
    name = query.value("Name").toString().toStdString();
    gender = query.value("Gender").toString().toStdString();
    birthYear = query.value("DOB").toUInt();
    deathYear = query.value("DOD").toUInt();
    bio = query.value("Bio").toString().toStdString();
}
void Person::setID(int id)
{
    ID = id;
}
