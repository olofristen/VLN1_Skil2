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
        string getname();
        string getgender();
        string getbio();
        int getbirthyear();
        int getdeathyear();
        int getID();
        void setID(int id);

        friend bool sortbyyearofbirth (const Person& a, const Person &b);
        friend bool sortbyyearofdeath (const Person& a, const Person &b);
        friend bool sortbygender (const Person& a, const Person &b);
        bool operator < (const Person& r);
        
        friend ostream& operator << (ostream& out, const Person& P);


};


#endif // PERSON_H
