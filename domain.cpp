#include "domain.h"

bool sortByYearOfBirth (const Person& a, const Person &b)
{
    return a.birthYear < b.birthYear;
}

bool sortByGender (const Person& a, const Person &b)
{
    return a.gender < b.gender;
}

bool sortByYearOfDeath (const Person& a, const Person &b)
{
    return a.deathYear < b.deathYear;

}

bool sortByYearOfBuilt (const Computer& a, const Computer &b)
{
    return a.buildYear < b.buildYear;
}

bool sortByType (const Computer& a, const Computer &b)
{
    return a.type < b.type;
}

bool sortByWasBuilt (const Computer& a, const Computer &b)
{
    return a.wasBuilt < b.wasBuilt;
}

Domain::Domain()
{
    v = DB.readScientistFromDb();
    ve = DB.readComputerFromDb();
    vLink = DB.readLinkFromDb();
}

int Domain::scientistsSize()
{
    return v.size();
}
int Domain::computersSize()
{
    return ve.size();
}

void Domain::addNewPerson(string name, string gender, int birthYear, int deathYear, string bio)
{     // Bætir nýrri persónu inn i vektorinn...
    Person newP = Person(name, gender, birthYear, deathYear, bio);
    newP.setId(DB.addNewScientist(newP));
    v.push_back(newP);
}

void Domain::addNewComputer(string name, int buildYear, string type, bool wasBuilt, string info)
{     // Bætir nýrri tölvu inn i vektorinn...

    Computer newC = Computer(name, type, wasBuilt, buildYear, info);
    newC.setId(DB.addNewComputer(newC));
    ve.push_back(newC);
}

vector<Person> Domain::returnAllScientists()
{
    return v;
}

vector<Computer> Domain::returnAllComputers()
{
    return ve;
}
vector<pair<Person, Computer> > Domain::returnAllLinks()
{
    return vLink;
}

pair<Person, Computer> Domain::addNewLink(int pID, int cID)
{
    pair<Person, Computer> link = make_pair(v[pID-1],ve[cID-1]);
    vLink.push_back(link);
    DB.addNewLink(link);
    return link;
}


vector<Person> Domain::sortAndDisplayScientist(string sortMenu)
{        // sorterar vektorinn...
    /*do{
        if(sortMenu.compare("1") == 0) {
            sort(v.begin(), v.end());
        }
        else if(sortMenu.compare("2") == 0) {
            sort(v.rbegin(), v.rend());
        }
        else if(sortMenu.compare("3") == 0) {
            sort(v.begin(), v.end());
            sort(v.begin(), v.end(), sortByGender);
        }
        else if(sortMenu.compare("4") == 0) {
            sort(v.begin(), v.end());
            sort(v.begin(), v.end(), sortByYearOfBirth);
        }
        else if(sortMenu.compare("5") == 0) {
            sort(v.begin(), v.end());
            sort(v.begin(), v.end(), sortByYearOfDeath);
        }
        else if(sortMenu.compare("Q") == 0 || sortMenu.compare("q") == 0) {
            return vector<Person>();
        }
        else {
            cout << "Invalid input! " << endl;
            cin >> sortMenu;
        }
    } while(atoi(sortMenu.c_str()) <= 0 || atoi(sortMenu.c_str()) > 5); */
    return DB.sortScientistsFromDb(sortMenu);
}

vector<Computer> Domain::sortAndDisplayComputer(string sortMenu)
{        // sorterar vektorinn...
    /*do{
        if(sortMenu.compare("1") == 0) {
            sort(ve.begin(), ve.end());
        }
        else if(sortMenu.compare("2") == 0) {
            sort(ve.rbegin(), ve.rend());
        }
        else if(sortMenu.compare("3") == 0) {
            sort(ve.begin(), ve.end());
            sort(ve.begin(), ve.end(), sortByYearOfBuilt);
        }
        else if(sortMenu.compare("4") == 0) {
            sort(ve.begin(), ve.end());
            sort(ve.begin(), ve.end(), sortByType);
        }
        else if(sortMenu.compare("Q") == 0 || sortMenu.compare("q") == 0) {
            return vector<Computer>();
        }
        else {
            cout << "Invalid input! " << endl;
            cin >> sortMenu;
        }
    } while(atoi(sortMenu.c_str()) <= 0 || atoi(sortMenu.c_str()) > 5);*/
    return DB.sortComputersFromDb(sortMenu);
}

vector<Person> Domain::searchStringScientist(string num, string search)
{
    return DB.searchScientistFromDb(num, search);
}

vector<Computer> Domain::searchStringComputer(string num, string search)
{
    return DB.searchComputerFromDb(num, search);
}
