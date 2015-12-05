#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Computer
{
    private:
        string name;
        string type;
        bool wasBuilt;
        int buildYear;
        string info;
    public:
        Computer();
        Computer(string name, string type, bool wasBuilt, int buildYear, string info);
        void readData(ifstream& file);
        void displayData();
        void searchData();
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
