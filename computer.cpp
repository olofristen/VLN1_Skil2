#include "computer.h"

bool Computer::operator < (const Computer &r) {
     return this->name < r.name;
}


Computer::Computer() {
    name = " ";
    buildYear = 0;
    type = " ";
    wasBuilt = " ";
}
Computer::Computer(string name, int buildyear, string type, string wasBuilt)
{
    this->name = name;
    this->buildYear = buildyear;
    this->type = type;
    this->wasBuilt = wasBuilt;
}
string Computer::getname() {
    return name;
}
int Computer::getbuildyear() {
    return buildYear;
}
string Computer::gettype() {
    return type;
}
string Computer::getwasbuilt() {
    return wasBuilt;
}

ostream& operator << (ostream& out, const Computer& C)
{
    cout << "Name: " << C.name << endl
         << "Made in: " << C.buildYear << endl
         << "Type: " << C.type << endl;
    if(C.wasBuilt == "N") {
        out << "This computer was only a thought!" << endl;
    }
    else {
        out << "Yes, this computer was built. " << endl;
    }
        out << "------------------------------------------------------------------" << endl;
        return out;
}
void Computer::readData(ifstream& file)
{
    string tempBuilt;
    getline(file, name);
    getline(file, tempBuilt);
    getline(file, type);
    getline(file, wasBuilt);
    buildYear = atoi(tempBuilt.c_str());
}

//void Computer::displayData()
