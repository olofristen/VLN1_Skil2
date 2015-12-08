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
        string getname();
        int getbuildyear();
        string gettype();
        bool getwasbuilt();
        string getinfo();

        friend bool sortbyyearofbuilt(const Computer& a, const Computer &b);
        friend bool sortbytype(const Computer& a, const Computer &b);
        friend bool sortbywasBuilt(const Computer& a, const Computer &b);
        bool operator < (const Computer& r);

        friend ostream& operator << (ostream& out, const Computer& C);

};

#endif // COMPUTER_H
