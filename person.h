#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QString>
#include <QtSql>

using namespace std;

// Klasi sem geymir upplýsingar um hverja einustu persónu, þ.e. nafn, kyn, fæðingar- og dánarár og stutt æviágrip ef við á.
class Person
{
    private:
        int ID;
        string name;
        string gender;
        int birthYear;
        int deathYear;
        string bio;

        void readData(QSqlQuery query);

    public:
        Person();
        Person (string name, string gender, int birthYear, int deathYear, string bio);
        Person(QSqlQuery query);
        string getName();
        string getGender();
        string getBio();
        int getBirthYear();
        int getDeathYear();
        int getId();
        void setId(int id);

        friend bool sortByYearOfBirth (const Person& a, const Person &b);
        friend bool sortByYearOfDeath (const Person& a, const Person &b);
        friend bool sortByGender (const Person& a, const Person &b);
        bool operator < (const Person& r);
        
        friend ostream& operator << (ostream& out, const Person& P);
};


#endif // PERSON_H
