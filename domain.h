#ifndef DOMAIN_H
#define DOMAIN_H

#include "data.h"
#include <algorithm>
//#include <cstdlib>

class Domain {

// Domain-klasinn geymir vektor með Person-klösum og sér um að umraða, leita í og bæta í hann.  Geymir Database-klasa og
// kemur gögnunum þannig á milli notendaviðmótsins og gagnagrunnsins.

private:

    vector<Person> v;
    vector<Computer> ve;
    Database DB;

public:
    Domain();
    void add_new_person(string name, string gender, int birthyear, int deathyear, string bio);
    void add_new_computer(string name, int buildyear, string type, bool wasBuilt, string info);
    vector<Person> sort_and_displayScientist(string sortMenu);
    vector<Computer> sort_and_displayComputer(string sortMenu);
    vector<Person>  searchStringScientist(string num, string search);
    vector<Computer>  searchStringComputer(string num, string search);
    int size();
    int scientistsSize();
    int computersSize();


};


#endif // DOMAIN_H
