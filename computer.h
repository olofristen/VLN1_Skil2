#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QtDebug>
#include <QtSql>

using namespace std;

class Computer
{
    private:
        int ID;
        string name;
        string type;
        bool wasBuilt;
        int buildYear;
        string info;

        void readData(QSqlQuery query);

    public:
        Computer();
        Computer(string name, string type, bool wasBuilt, int buildYear, string info);
        Computer(QSqlQuery q);

        string getName();
        int getBuildYear();
        string getType();
        bool getWasBuilt();
        string getInfo();
        int getId();
        void setId(int id);

        friend bool sortByYearOfBuilt(const Computer& a, const Computer &b);
        friend bool sortByType(const Computer& a, const Computer &b);
        friend bool sortByWasBuilt(const Computer& a, const Computer &b);
        bool operator < (const Computer& r);

        friend ostream& operator << (ostream& out, const Computer& C);

};

#endif // COMPUTER_H
