#include "domain.h"

bool sortbyyearofbirth (const Person& a, const Person &b)
{
    return a.birthYear < b.birthYear;
}

bool sortbygender (const Person& a, const Person &b)
{
    return a.gender < b.gender;
}

bool sortbyyearofdeath (const Person& a, const Person &b)
{
    return a.deathYear < b.deathYear;

}

bool sortbyyearofbuilt (const Computer& a, const Computer &b)
{
    return a.buildYear < b.buildYear;
}

bool sortbytype (const Computer& a, const Computer &b)
{
    return a.type < b.type;
}

bool sortbywasBuilt (const Computer& a, const Computer &b)
{
    return a.wasBuilt < b.wasBuilt;
}

Domain::Domain()
{
    v = DB.read_Scientist_from_DB();
    ve = DB.read_Computer_from_DB();
    //vlink = DB.read_link_from_DB();
}

int Domain::scientistsSize() {
    return v.size();
}
int Domain::computersSize() {
    return ve.size();
}

void Domain::add_new_person(string name, string gender, int birthyear, int deathyear, string bio)
{     // Bætir nýrri persónu inn i vektorinn...
    Person newP = Person(name, gender, birthyear, deathyear, bio);
    newP.setID(DB.add_new_scientist(newP));
    v.push_back(newP);
}

void Domain::add_new_computer(string name, int buildYear, string type, bool wasBuilt, string info)
{     // Bætir nýrri tölvu inn i vektorinn...

    Computer newC = Computer(name, type, wasBuilt, buildYear, info);
    newC.setID(DB.add_new_computer(newC));
    ve.push_back(newC);
}

void Domain::add_new_link(Person p, Computer c)
{     // Bætir nýrri tölvu inn i vektorinn...
    pair<Person, Computer> link = make_pair(p,c);
    vlink.push_back(link);
    DB.add_new_link(link);
}


vector<Person> Domain::sort_and_displayScientist(string sortMenu)
{        // sorterar vektorinn...
    do{
        if(sortMenu.compare("1") == 0) {
            sort(v.begin(), v.end());
        }
        else if(sortMenu.compare("2") == 0) {
            sort(v.rbegin(), v.rend());
        }
        else if(sortMenu.compare("3") == 0) {
            sort(v.begin(), v.end());
            sort(v.begin(), v.end(), sortbygender);
        }
        else if(sortMenu.compare("4") == 0) {
            sort(v.begin(), v.end());
            sort(v.begin(), v.end(), sortbyyearofbirth);
        }
        else if(sortMenu.compare("5") == 0) {
            sort(v.begin(), v.end());
            sort(v.begin(), v.end(), sortbyyearofdeath);
        }
        else if(sortMenu.compare("Q") == 0 || sortMenu.compare("q") == 0) {
            return vector<Person>();
        }
        else {
            cout << "Invalid input! " << endl;
            cin >> sortMenu;
        }
    } while(atoi(sortMenu.c_str()) <= 0 || atoi(sortMenu.c_str()) > 5);
    return v;
}

vector<Computer> Domain::sort_and_displayComputer(string sortMenu)
{        // sorterar vektorinn...
    do{
        if(sortMenu.compare("1") == 0) {
            sort(ve.begin(), ve.end());
        }
        else if(sortMenu.compare("2") == 0) {
            sort(ve.rbegin(), ve.rend());
        }
        else if(sortMenu.compare("3") == 0) {
            sort(ve.begin(), ve.end());
            sort(ve.begin(), ve.end(), sortbyyearofbuilt);
        }
        else if(sortMenu.compare("4") == 0) {
            sort(ve.begin(), ve.end());
            sort(ve.begin(), ve.end(), sortbytype);
        }
        else if(sortMenu.compare("Q") == 0 || sortMenu.compare("q") == 0) {
            return vector<Computer>();
        }
        else {
            cout << "Invalid input! " << endl;
            cin >> sortMenu;
        }
    } while(atoi(sortMenu.c_str()) <= 0 || atoi(sortMenu.c_str()) > 5);
    return ve;
}

vector<Person> Domain::searchStringScientist(string num, string search)
{
    vector<Person> vec;

    if(num.compare("1") == 0) {
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getname().find(search) != string::npos)
            {
                vec.push_back(v[i]);
            }
        }
    }
    else if(num.compare("2") == 0) {
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getgender().find(search) != string::npos)
            {
                vec.push_back(v[i]);
            }
        }
    }
    else if(num.compare("3") == 0) {
         for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getbirthyear() == atoi(search.c_str()))
            {
                vec.push_back(v[i]);
            }
        }
    }
    else if(num.compare("4") == 0) {
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getdeathyear()== atoi(search.c_str()))
            {
                vec.push_back(v[i]);
            }
        }
    }
    else if(num.compare("5") == 0) {
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getbio().find(search) != string::npos)
            {
                vec.push_back(v[i]);
            }
        }
    }
    return vec;
}

vector<Computer> Domain::searchStringComputer(string num, string search) {

    vector<Computer> vec;

    if(num.compare("1") == 0) {
        for(unsigned int i = 0; i < ve.size(); i++)
        {
            if (ve[i].getname().find(search) != string::npos)
            {
                vec.push_back(ve[i]);
            }
        }
    }
    else if(num.compare("2") == 0) {
        for(unsigned int i = 0; i < ve.size(); i++)
        {
            if (ve[i].getbuildyear() == atoi(search.c_str()))
            {
                vec.push_back(ve[i]);
            }
        }
    }
    else if(num.compare("3") == 0) {
         for(unsigned int i = 0; i < ve.size(); i++)
        {
            if (ve[i].gettype().find(search) != string::npos)
            {
                vec.push_back(ve[i]);
            }
        }
    }
    else if(num.compare("4") == 0) {  //þarf að útfæra þetta fall nánar
        for(unsigned int i = 0; i < ve.size(); i++)
        {
            if (ve[i].getwasbuilt() == true)
            {
                vec.push_back(ve[i]);
            }
        }
    }

    return vec;
}
