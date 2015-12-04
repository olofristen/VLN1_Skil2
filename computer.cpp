#include "computer.h"

bool Computer::operator < (const Computer &r) {
     return this->name < r.name;
}


Computer::Computer() {
    name = " ";
    buildYear = 0;
    type = 0;
    wasBuilt = 0;
}
Computer::Computer(string name, int buildyear, int type, bool wasBuilt)
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
int Computer::gettype() {
    return type;
}
bool Computer::getwasbuilt() {
    return wasBuilt;
}
void Computer::displayData()
{
    cout << "Name: " << getname() << endl
         << "Made in: " << getbuildyear() << endl
         << "Type: " << gettype() << endl;
    if(getwasbuilt() == -1) {
        cout << "This computer was only a thought!" << endl;
    }
    else {
        cout << "Yes, this computer was built. " << endl;
    }
        cout << "------------------------------------------------------------------" << endl;
}
/*void Computer::readData(ifstream& file)
{
    string tempBuilt, tempType, tempWasbuilt;
    getline(file, name);
    getline(file, tempBuilt);
    getline(file, tempType);
    getline(file, wasBuilt);
    builtYear = atoi(tempBuilt.c_str());
    type = atoi(tempType.c_str());
    wasBuilt = atoi(tempWasbuilt.c_str());
}*/

