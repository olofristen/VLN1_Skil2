#ifndef UI_H
#define UI_H

#include "domain.h"
#include <QtSql>
#include <sstream>

// Klasi sem heldur utan um notendaviðmótið.  Notandinn getur t.d. bætt inn nýjum einstakling, lesið alla einstaklingana út
// á skjáinn með ákveðinni röðun og leitað af einverju sem tengist einstaklingnum.

class UI {
private:
    Domain myDom;

public:
    void welcome();
    void choices();
    void readingPerson();
    void readingComputer();
    void sortMessageScientist();
    void sortMessageComputer();
    void registerMessageScientist();
    void registerMessageComputer();
    void registerMessageLink();
    void searchMessage();
    void searchScientist();
    void searchComputer();
    void returnHome();
    void clearScreen();
    void linkTogether();
    
    void displayDatabaseScientist(vector<Person> v);
    void displayDatabaseComputer(vector<Computer> ve);
    void displayLink(pair<Person, Computer> link);
    void displayDatabaseLinks();
    //void displayDatabaseLink(vector<pair<Person, Computer> > vlink);

};

#endif // UI_H
