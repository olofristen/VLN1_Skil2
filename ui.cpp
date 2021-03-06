#include "ui.h"

// UI, heldur utan um öll samskipti við notendur, cin, cout, main.... -> samskipti við domain(worker) sem útfærir vektor o.s.frv.
// helstu atriði sem eru í boði: add, sort og printlist, search
// Þarf ekki endilega að vera klasi en getur haft samskipti við Person-klasa sem er óháður layerunum

void UI::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system ("clear");
#endif
}

void UI::welcome()      // "Heimaskjárinn"
{

    cout << "                         ===================================" << endl;
    cout << "                         |            WELCOME              |" << endl;
    cout << "                         |               to                |" << endl;
    cout << "                         |     the Computing Database      |" << endl;
    cout << "                         ===================================" << endl;
    cout << endl;
    cout << "In this program you will be able to register and go through the most important " << endl
         << "computer scientists AND computers OF ALL TIME!" << endl;
    cout << endl;
    cout << "Now, the database includes: " << myDom.scientistsSize() << " scientist(s), " << myDom.computersSize() << " computer(s) and " << myDom.linkSize() << " links!!" << endl << endl;
}

void UI::choices()  // Aðalvalmyndin
{
    string menu = "";

    cout << "   =================================================================" << endl;
    cout << "   |  What do you want to do?                                      |" << endl;
    cout << "   |    1.  Register new computer scientist/s                      |" << endl;
    cout << "   |    2.  Register new computer/s                                |" << endl;
    cout << "   |    3.  Register link between scientist/s and computer/s       |" << endl;
    cout << "   |    4.  See all computer scientists registered                 |" << endl;
    cout << "   |    5.  See all computers registered                           |" << endl;
    cout << "   |    6.  Search for a scientist                                 |" << endl;
    cout << "   |    7.  Search for a computer                                  |" << endl;
    cout << "   |    8.  See all registered links                               |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;
    cin >> menu;

    if(menu.compare("1") == 0)
    {
        clearScreen();
        registerMessageScientist();
        readingPerson();
    }
    else if(menu.compare("2") == 0)
    {
        clearScreen();
        registerMessageComputer();
        readingComputer();
    }
    else if(menu.compare("3") == 0)
    {
        clearScreen();
        registerMessageLink();
        linkTogether();
    }
    else if(menu.compare("4") == 0)
    {
        clearScreen();
        sortMessageScientist();
    }
    else if(menu.compare("5") == 0)
    {
        clearScreen();
        sortMessageComputer();
    }
    else if(menu.compare("6") == 0)
    {
        clearScreen();
        searchScientist();
    }
    else if(menu.compare("7") == 0)
    {
        clearScreen();
        searchComputer();
    }
    else if(menu.compare("8") == 0)
    {
        clearScreen();
        allLinksMessage();
        displayDatabaseLinks();
    }
    else
    {
        cout << "Invalid input! " << endl;
    }
}
// Nokkrir hausar
void UI::registerMessageScientist()
{
    cout << "   =================================================================" << endl;
    cout << "   |     REGISTER NEW COMPUTING GENIUS                             |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;
}

void UI::registerMessageComputer()
{
    cout << "   =================================================================" << endl;
    cout << "   |     REGISTER NEW COMPUTER                                     |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;
}

void UI::registerMessageLink()
{
    cout << "   =================================================================" << endl;
    cout << "   |     REGISTER A LINK BETWEEN SCIENTIST/S AND COMPUTER/S        |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;
}

void UI::searchMessage()
{
    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SEARCH                                     |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;

}

void UI::allLinksMessage()
{
    cout << "   =================================================================" << endl;
    cout << "   |     ALL LINKS IN DATABASE                                     |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
}

void UI::sortMessageScientist()     // Sorting-valmyndin fyrir vísindamenn
{
    string sortMenu = "";

    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SORT                                       |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;

    cout << "   =================================================================" << endl;
    cout << "   |  How do you want the computing geniuses to appear?            |" << endl;
    cout << "   |    1.  A-Z                                                    |" << endl;
    cout << "   |    2.  Z-A                                                    |" << endl;
    cout << "   |    3.  By gender                                              |" << endl;
    cout << "   |    4.  By year of birth                                       |" << endl;
    cout << "   |    5.  By year of death                                       |" << endl;
    cout << "   |    6.  Just those who are alive ! (A-Z..)                     |" << endl;
    cout << "   |    7.  A-Z shortlist of all registerd scientists              |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;

    cin >> sortMenu;
    if(sortMenu == "Q" || sortMenu == "q")
    {
        return;
    }
    if(sortMenu == "1" || sortMenu == "2" || sortMenu == "3" || sortMenu == "4" || sortMenu == "5" || sortMenu == "6" || sortMenu == "7")
    {
        if(sortMenu == "7")
        {
            vector<Person> ve = myDom.sortAndDisplayScientist(sortMenu);
            if(!ve.empty())
            {
                displayDatabaseScientistShort(ve);
            }
        }
        else
        {
            vector<Person> vec = myDom.sortAndDisplayScientist(sortMenu);
            if(!vec.empty())
            {
                displayDatabaseScientist(vec);
            }
        }
    }
    else if(sortMenu == "Q" || sortMenu == "q")      // Hættum að sjálfsögðu með Q (eða q)!
    {
        return;
    }
    else
    {
        cout << "Invalid input!";
    }
}

void UI::sortMessageComputer()     // Sorting-valmynd fyrir tölvur
{
    string sortMenu = "";

    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SORT                                       |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;

    cout << "   =================================================================" << endl;
    cout << "   |  How do you want the computers to appear?                     |" << endl;
    cout << "   |    1.  A-Z                                                    |" << endl;
    cout << "   |    2.  Z-A                                                    |" << endl;
    cout << "   |    3.  By year it was built                                   |" << endl;
    cout << "   |    4.  By type                                                |" << endl;
    cout << "   |    5.  A-Z shortlist of all registered computers              |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;

    cin >> sortMenu;
    if(sortMenu == "1" || sortMenu == "2" || sortMenu == "3" || sortMenu == "4" || sortMenu == "5")
    {
        if(sortMenu == "5")
        {
            vector<Computer> ve = myDom.sortAndDisplayComputer(sortMenu);
            if(!ve.empty())
            {
                displayDatabaseComputerShort(ve);
            }
        }
        else
        {
            vector<Computer> vec = myDom.sortAndDisplayComputer(sortMenu);
            if(!vec.empty())
            {
                displayDatabaseComputer(vec);
            }
        }
    }
    else if(sortMenu == "Q" || sortMenu == "q")     // Hættum að sjálfsögðu með Q (eða q)!
    {
        return;
    }
    else
    {
        cout << "Invalid input!";
    }
}

void UI::searchScientist()      // Leitunarvalmyndin fyrir vísindamennina...
{
    string searchMenu = "", search = "";
    searchMessage();

    cout << "   =================================================================" << endl;
    cout << "   |  in which category would you prefer to search?                |" << endl;
    cout << "   |    1.  By name                                                |" << endl;
    cout << "   |    2.  By gender                                              |" << endl;
    cout << "   |    3.  By year of birth                                       |" << endl;
    cout << "   |    4.  By year of death                                       |" << endl;
    cout << "   |    5.  By bio                                                 |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;

    do{
        cin >> searchMenu;

        if(searchMenu.compare("1") == 0)
        {
            cout << "What name would you like to find?: ";
        }
        else if(searchMenu.compare("2") == 0)
        {
            cout << "Male or female?: ";
        }
        else if(searchMenu.compare("3") == 0)
        {
            cout << "When was the person born?: ";
        }
        else if(searchMenu.compare("4") == 0)
        {
            cout << "When did the person die?: ";
        }
        else if(searchMenu.compare("5") == 0)
        {
            cout << "Enter some word and we will see..: ";
        }
        else if(searchMenu.compare("Q") == 0 || searchMenu.compare("q") == 0)
        {
            return ;
        }
        else {
            cout << "Invalid input! " << endl;
        }
    }
    while(atoi(searchMenu.c_str()) <= 0 || atoi(searchMenu.c_str()) > 5);

    cin.ignore();
    getline(cin, search);
    vector<Person> vec = myDom.searchStringScientist(searchMenu, search);

    displayDatabaseScientist(vec);

    if(vec.size() == 0)
    {
        cout << "Sorry, no match." << endl;
    }
}
void UI::searchComputer()       // Leitunarvalmynd fyrir tölvurnar...
{
    string searchMenu = "", search = "";
    searchMessage();

    cout << "   =================================================================" << endl;
    cout << "   |  In which category would you prefer to search?                |" << endl;
    cout << "   |    1.  By name                                                |" << endl;
    cout << "   |    2.  By type                                                |" << endl;
    cout << "   |    3.  By the year it was built                               |" << endl;
    cout << "   |    4.  By whether it was built or not                         |" << endl;
    cout << "   |    5.  By info                                                |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;

    do{
        cin >> searchMenu;

        if(searchMenu.compare("1") == 0)
        {
            cout << "What name would you like to find?: ";
        }
        else if(searchMenu.compare("2") == 0)
        {
            cout << "Which type was the computer?: ";
        }
        else if(searchMenu.compare("3") == 0)
        {
            cout << "When was the computer built?: ";
        }
        else if(searchMenu.compare("4") == 0)
        {
            cout << "So was the computer built or not? " << endl;
            cout << "Please pick 1 for yes and 0 for no. Pick now: ";
        }
        else if(searchMenu.compare("5") == 0)
        {
            cout << "Enter some word and we will see..: ";
        }
        else if(searchMenu.compare("Q") == 0 || searchMenu.compare("q") == 0)
        {
            return ;
        }
        else
        {
            cout << "Invalid input! " << endl;
        }
    }
    while(atoi(searchMenu.c_str()) <= 0 || atoi(searchMenu.c_str()) > 5);

    cin.ignore();
    getline(cin, search);
    vector<Computer> vec = myDom.searchStringComputer(searchMenu, search);

    displayDatabaseComputer(vec);

    if(vec.size() == 0)
    {
        cout << "Sorry, no match :(" << endl;
    }
}

void UI::readingPerson()        // Lesum inn nýjan vísindamann inn í gagnagrunninn
{
    string number = "";
    int num = 0;

    do
    {
        cout << "How many computing geniuses do you want to register? ";
        cin >> number;

        if(number == "Q" || number == "q")
        {
            return;
        }
        num = atoi(number.c_str());
        if(num <= 0)
        {
            cout << "Invalid input! " << endl;
        }
    }
    while(num <= 0);

    cout << endl << "Type in person: " << endl << endl;

    string name = "", gender = "", bio = "", year = "", dead = "";
    int birthYear = 0, deathYear = 0;
    string a = "";

    for(int i = 0; i < num; i++)
    {
        cout << "Name: ";
        if (i == 0)
        {
            cin.ignore();
        }
        getline(cin, name);

        do
        {
            cout << "Gender (F/M): ";
            cin >> a;

            if(a.compare("f") == 0 || a.compare("F") == 0)
            {
                gender = "Female";
            }
            else if(a.compare("m") == 0 || a.compare("M") == 0)
            {
                gender = "Male";
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }
        while(gender == "");

        do
        {
            cout << "Year of birth (1600 - 2010): ";
            cin >> year;

            if(year < "1600" || year > "2010")
            {
                cout << "Invalid input" << endl;
            }
        }
        while(year < "1600" || year > "2010");

        birthYear = atoi(year.c_str());

        cout << "Is the scientist dead (Y/N)?: ";
        cin >> dead;

        do
        {
            if(dead.compare("y") == 0 || dead.compare("Y") == 0)
            {
                cout << "Year of death: ";  // Dauður
                cin >> year;
                deathYear = atoi(year.c_str());

                if(deathYear < birthYear || deathYear > 2015)
                {
                    cout << "Invalid input! " << endl;
                    cin >> dead;
                }
            }
            else if(dead.compare("n") == 0 || dead.compare("N") == 0)
            {
                deathYear = -1;     // Ekki dauður, skilum -1 fyrir deathYear
            }

            else
            {          // Ekki vitað, spyr aftur
                cout << "Invalid input! " << endl;
                cin >> dead;
            }

        }
        while((deathYear != -1) && ((deathYear < birthYear) || (deathYear > 2015)));

        cout << "Bio: ";
        cin.ignore();
        getline(cin, bio);
        cout << endl;

        myDom.addNewPerson(name, gender, birthYear, deathYear, bio);
    }
}

void UI::readingComputer()      // Ný tölva í gagnagrunninn...
{
    string number = "";
    int num = 0;

    do
    {
        cout << "How many computers do you want to register? ";
        cin >> number;

        if(number == "Q" || number == "q")
        {
            return;
        }
        num = atoi(number.c_str());
        if(num <= 0)
        {
            cout << "Invalid input! " << endl;
        }
    }
    while(num <= 0);

    cout << endl << "Type in computer: " << endl << endl;

    string name = "", buildYear = "", type = "", info = "", wb = "", a = "";
    bool wasBuilt;
    int tempBy = 0;

    for(int i = 0; i < num; i++)
    {
        cout << "Name: ";
        if(i == 0)
        {
            cin.ignore();
        }
        getline(cin, name);


            cout << "Was the computer:" << endl;
            cout << "1. Mechanic" << endl;
            cout << "2. Electronic" << endl;
            cout << "3. Transistor computer" << endl;
            cout << "4. Other" << endl;
        do
        {
            cin >> a;

            if(a.compare("1") == 0)
            {
                type = "Mechanic";
            }
            else if(a.compare("2") == 0)
            {
                type = "Electronic";
            }
            else if(a.compare("3") == 0)
            {
                type = "Transistor computer";
            }
            else if(a.compare("4") == 0)
            {
                type = "Other";
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }
        while(type == "");

        do
        {
            cout << "Was the computer ever made (Y/N)? " ;
            cin >> wb;

            if(wb == "Y" || wb == "y")
            {
                wasBuilt = true;
            }
            else if(wb == "N" || wb == "n")
            {
                wasBuilt = false;
            }
            else
            {
                cout << "Invalid input" << endl;
                wb = "";
            }
        }
        while(wb == "");

        if(wasBuilt == true)
        {
            do
            {
                cout << "Year of production (1600 - 2010): ";
                cin >> buildYear;

                if(buildYear < "1600" || buildYear > "2010")
                {
                    cout << "Invalid input" << endl;
                }
            }
            while(buildYear < "1600" || buildYear > "2010");
        }
        else
        {
            cout << "When was the computer documented? ";
            do
            {
                cin >> buildYear;

                if(buildYear < "1600" || buildYear > "2015")
                {
                    cout << "Invalid input" << endl;
                }
            }
            while(buildYear < "1600" || buildYear > "2015");
        }

        tempBy = atoi(buildYear.c_str());

        cout << "Info: ";
        cin.ignore();
        getline(cin, info);
        cout << endl;

        myDom.addNewComputer(name, tempBy, type, wasBuilt, info);
    }
}

void UI::linkTogether()     // Skrifum einstaklingana og tölvurnar út á skjáinn og notandinn velur númer til að tengja saman!
{
    int sid = -1, cid = -1;
    string tempScientistId = "", tempComputerId = "";
    cout << "Choose one scientist (ID) and one computer (ID)!" << endl << endl;
    cout << "Scientists from the database: " << endl;
    displayDatabaseScientistShort(myDom.returnAllScientists());
    cout << endl << "Scientist ID: ";
    do
    {
        cin >> tempScientistId; // Tekur inn vector gildi en ekki ID úr gagnagrunni!
        if(tempScientistId == "q" || tempScientistId == "Q")
        {
            return;
        }
        else if(atoi(tempScientistId.c_str()) > 0 && atoi(tempScientistId.c_str()) <= myDom.scientistsSize())

        {
            sid = atoi(tempScientistId.c_str());
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    while(sid <= 0 || sid > myDom.scientistsSize());

    cout << endl << "Computers in the database: " << endl;
    displayDatabaseComputerShort(myDom.returnAllComputers());
    cout << endl << "Computer ID: ";

    do
    {
        cin >> tempComputerId; // Tekur inn vector gildi en ekki ID úr gagnagrunni!
        if(tempComputerId == "q" || tempComputerId == "Q")
        {
            return;
        }
        else if(atoi(tempComputerId.c_str()) > 0 && atoi(tempComputerId.c_str()) <= myDom.computersSize())
        {
            cid = atoi(tempComputerId.c_str());
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    while(cid <= 0 || cid > myDom.computersSize());

    pair<Person, Computer> link = myDom.addNewLink(sid - 1, cid - 1);
    cout << endl << "----------------------------------------" << endl;
    cout << "New link: " << endl << endl;
    displayLink(link);
}

void UI::displayDatabaseScientist(vector<Person> v)      // Prentar út person-vektor...
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << endl << v[i];
        cout << endl << "Computers: ";
        vector<Computer> comp = myDom.getCompFromLinks(v[i].getId());

        for(unsigned int i = 0; i < comp.size(); i++) {
            cout << comp[i].getName();
            if(i != comp.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl
        << "------------------------------------------------------------------" << endl;
    }
    cout << endl << v.size() << " scientists!" << endl;
}

void UI::displayDatabaseScientistShort(vector<Person> v)
{
    cout << endl << " #     NAME                          BIRTH YEAR   DEATH YEAR" << endl;
    cout << "----------------------------------------------------------" << endl;

    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << " " << setw(5) << left << i + 1;
        displayShort(v[i]);
    }
    cout << endl << v.size() << " scientists!" << endl;
}

void UI::displayDatabaseComputer(vector<Computer> ve)      // Prentar út Computer-vektor...
{
    for(unsigned int i = 0; i < ve.size(); i++)
    {
        cout << endl << ve[i];
        cout << endl << "Scientists: ";
        vector<Person> sci = myDom.getSciFromLinks(ve[i].getId());

        for(unsigned int i = 0; i < sci.size(); i++)
        {
            cout << sci[i].getName();
            if(i != sci.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl
             << "------------------------------------------------------------------" << endl;
    }
    cout << endl << ve.size() << " computers!" << endl;
}

void UI::displayDatabaseComputerShort(vector<Computer> ve)
{
    cout << endl << " #     NAME                          YEAR    TYPE" << endl;
    cout << "---------------------------------------------------------" << endl;


    for(unsigned int i = 0; i < ve.size(); i++)
    {
        cout << " " << setw(5) << left << i + 1;
        displayShortCom(ve[i]);
    }
    cout << endl << ve.size() << " computers!" << endl;
}


void UI::displayLink(pair<Person, Computer> link)      // Prentar út par af Person og Computer...
{
    //cout << "Link: " << endl;
    cout << endl << link.first;     // Person
    cout << endl << "---------------------------------------------- " << endl;
    cout << endl << link.second;    // Computer
    //cout << endl << vlink.size() << " links!" << endl;
    cout << endl << "---------------------------------------------- " << endl;
}


bool sortPairVector(pair<Person, Computer>& la, pair<Person, Computer>& lb)     // Notað í fallinu hér að neðan fyrir sort á pair
{
    return la.first < lb.first;
}

void UI::displayDatabaseLinks()     // Prentum út allar tengingarnar, þ.e. nöfn á einstaklingum og tölvum
{
    vector<pair<Person, Computer> > vLink = myDom.returnAllLinks();

    sort(vLink.begin(), vLink.end(), sortPairVector);
    cout << endl << " #   SCIENTISTS               COMPUTERS" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for(unsigned int i = 0; i < vLink.size(); i++)
    {
        cout << " " << setw(4) << left << i + 1 << setw(25) << left << vLink[i].first.getName();
        cout << setw(25) << left << vLink[i].second.getName() << endl;
    }
    cout << endl << vLink.size() << " links!" << endl;
}

void UI::displayShort(Person P)
{   
    cout << " " << setw(30) << left << P.getName();
    cout << setw(8) << left << P.getBirthYear();
    if(P.getDeathYear() == -1)
    {
        cout << setw(9) << right << "" << endl;
    }
    else
    {
        cout << setw(9) << right << P.getDeathYear() << endl;
    }
}

void UI::displayShortCom(Computer C)
{
    cout << " " << setw(30) << left << C.getName() << setw(8) << left << C.getBuildYear();
    cout << setw(15) << left << C.getType() << endl;
}
