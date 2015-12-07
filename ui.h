#ifndef UI_H
#define UI_H

#include "domain.h"
#include <QtSql>
#include <sstream>

// Klasi sem heldur utan um notendaviðmótið.  Notandinn getur t.d. bætt inn nýjum einstakling, lesið alla einstaklingana út
// á skjáinn með ákveðinni röðun og leitað af einverju sem tengist einstaklingnum.

class UI {
private:
    Domain my_dom;

public:
    void welcome();
    void choices();
    void reading_person();
    void reading_computer();
    void sortMessageScientist();
    void sortMessageComputer();
    void registerMessageScientist();
    void registerMessageComputer();
    void registerMessageLink();
    void searchMessage();
    void searchScientist();
    void searchComputer();
    void return_home();
    void clear_screen();
    
    void displayDatabaseScientist(vector<Person> v);
    void displayDatabaseComputer(vector<Computer> ve);
    void displayDatabaseLink(vector<pair<Person, Computer> > vlink);

};

#endif // UI_H
