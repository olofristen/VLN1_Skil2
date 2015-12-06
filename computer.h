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
        int buildYear;
        string type;
        string wasBuilt;
    public:
        Computer();
        Computer(string name, int buildYear, string type, string wasBuilt);
        void readData(QSqlQuery query);
        void displayData();
        void searchData();
        string getname();
        int getbuildyear();
        string gettype();
        string getwasbuilt();

        friend bool sortbyyearofbuilt(const Computer& a, const Computer &b);
        friend bool sortbytype(const Computer& a, const Computer &b);
        friend bool sortbywasBuilt(const Computer& a, const Computer &b);
        bool operator < (const Computer& r);

        friend ostream& operator << (ostream& out, const Computer& C);

};

#endif // COMPUTER_H
