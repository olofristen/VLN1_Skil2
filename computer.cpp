#include "computer.h"

bool Computer::operator < (const Computer &r) {
     return this->name < r.name;
}

Computer::Computer() {
    name = " ";
    type = " ";
    wasBuilt = " ";
    buildYear = 0;
    info = " ";
}

Computer::Computer(string name, string type, bool wasBuilt, int buildYear, string info)
{
    this->name = name;
    this->type = type;
    this->wasBuilt = wasBuilt;
    this->buildYear = buildYear;
    this->info = info;
}

string Computer::getname()
{
    return name;
}

int Computer::getbuildyear()
{
    return buildYear;
}

string Computer::gettype()
{
    return type;
}

bool Computer::getwasbuilt()
{
    return wasBuilt;
}

string Computer::getinfo()
{
    return info;
}

ostream& operator << (ostream& out, const Computer& C)
{
    cout << "Name: " << C.name << endl
         << "Made in: " << C.buildYear << endl
         << "Type: " << C.type << endl;
    if(C.wasBuilt == false) {
        out << "This computer was only a thought!" << endl;
    }
    else {
        out << "Yes, this computer was built. " << endl;
    }
        out << "------------------------------------------------------------------" << endl;
        return out;
}
/*void Computer::readData(ifstream& file)
{
    string tempBuilt;
    getline(file, name);
    getline(file, tempBuilt);
    getline(file, type);
    getline(file, wasBuilt);
    getline(file, info)
    buildYear = atoi(tempBuilt.c_str());
}*/

//void Computer::displayData()
