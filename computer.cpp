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
void Computer::readData(QSqlQuery query)
{
    name = query.value("Name").toString().toStdString();
    buildYear = query.value("BY").toUInt();
    type = query.value("TYPE").toString().toStdString();
    wasBuilt = query.value("WB").toString().toStdString();
}

//void Computer::displayData()
