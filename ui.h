#ifndef UI_H
#define UI_H

#include "domain.h"
#include <QtSql>
#include <QtDebug>
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
    void sortMessage();
    void registerMessageScientist();
    void registerMessageComputer();
    void searchMessage();
    void searchData();
    void return_home();
    
    void displayDatabase(vector<Person> v);

};

#endif // UI_H
