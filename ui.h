#ifndef UI_H
#define UI_H

#include "domain.h"
#include <QtSql>
#include <sstream>
#include <iomanip>
#include <string>

// Klasi sem heldur utan um notendaviðmótið.  Notandinn getur t.d. bætt inn nýjum einstakling, tölvu og link, lesið allt út
// á skjáinn með ákveðinni röðun og leitað af einverju sem tengist einstaklingnum eða tölvunni.

class UI
{
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
    void allLinksMessage();

    void searchMessage();
    void searchScientist();
    void searchComputer();
    void clearScreen();
    void linkTogether();

    // Alls konar skemmtilegt display-föll sem skrifa dót úr á skjáinn...
    void displayDatabaseScientist(vector<Person> v);
    void displayDatabaseScientistShort(vector<Person> v);
    void displayDatabaseComputer(vector<Computer> ve);
    void displayDatabaseComputerShort(vector<Computer> ve);
    void displayLink(pair<Person, Computer> link);
    void displayDatabaseLinks();
    void displayShort(Person P);
    void displayShortCom(Computer C);

};

#endif // UI_H
