#include "person.h"

bool Person::operator < (const Person &r) {
     return this->name < r.name;
}


Person::Person()
{
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


string Person::getname() {
    return name;
}
string Person::getgender() {
    return gender;
}
int Person::getbirthyear() {
    return birthYear;
}
int Person::getdeathyear() {
    return deathYear;
}
string Person::getbio() {
    return bio;
}


ostream& operator << (ostream& out, const Person& P)
{
    out << "Name: " << P.name << endl
         << "Gender: " << P.gender << endl
         << "Year of birth: " << P.birthYear << endl;
    if(P.deathYear == -1) {
        out << "Blive and well!" << endl;
    }
    else {
        out << "Year of death: " << P.deathYear << endl;
    }
    out << endl << "Bio: " << P.bio << endl
         << "------------------------------------------------------------------" << endl;
    return out;
}

void Person::readData(ifstream& file)
{
    string tempBirth, tempDeath;
    getline(file, name);
    getline(file, gender);
    getline(file, tempBirth);
    getline(file, tempDeath);
    getline(file, bio);
    birthYear = atoi(tempBirth.c_str());
    deathYear = atoi(tempDeath.c_str());
}


