#include "computer.h"

bool Computer::operator < (const Computer &r) {
     return this->name < r.name;
}

Computer::Computer() {
    name = " ";
    type = " ";
    wasBuilt = false;
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
    out << "Name: " << C.name << endl
         << "Type: " << C.type << endl;
    if(C.wasBuilt == false)
    {
        out << "Built: This computer was never built, but it was designed in " << C.buildYear << endl;
    }
    else
    {
        out << "Built: This computer was built in " << C.buildYear << endl;
    }

    out << "Info: " << C.info << endl;
    out << "------------------------------------------------------------------" << endl;

    return out;
}

void Computer::readData(QSqlQuery query)
{
    name = query.value("Name").toString().toStdString();
    buildYear = query.value("BuildYear").toUInt();
    type = query.value("Type").toString().toStdString();
    wasBuilt = query.value("WB").toBool();
    info = query.value("Info").toString().toStdString();
}
