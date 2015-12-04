#include "ui.h"

// UI, heldur utan um öll samskipti við notendur, cin, cout, main.... -> samskipti við domain(worker) sem útfærir vektor o.s.frv.
// helstu atriði sem eru í boði: add, sort og printlist, search
// Þarf ekki endilega að vera klasi en getur haft samskipti við Person-klasa sem er óháður layerunum


void UI::welcome()
{

    cout << "                         ===================================" << endl;
    cout << "                         |             WELCOME             |" << endl;
    cout << "                         |               to                |" << endl;
    cout << "                         |     the Computer Scientist      |" << endl;
    cout << "                         |             Database            |" << endl;
    cout << "                         ===================================" << endl;
    cout << endl;
    cout << "In this program you will be able to register and go through the most known "
         << "computer scientists of all time!" << endl;
    cout << endl;
    cout << "Now, the database includes " << my_dom.size() << " scientist(s)!" << endl << endl;
}

void UI::choices()
{
    string menu = "";

    cout << "   =================================================================" << endl;
    cout << "   |  What do you want to do?                                      |" << endl;
    cout << "   |    1.  Register new computer scientist/s                      |" << endl;
    cout << "   |    2.  Register new computer                                  |" << endl;
    cout << "   |    3.  See all computer scientists registered                 |" << endl;
    cout << "   |    4.  Search the database                                    |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;
    cin >> menu;

    if(menu.compare("1") == 0){
        system("CLS");
        registerMessageScientist();
        reading_person();
    }
    else if(menu.compare("2") == 0){
        system("CLS");
        registerMessageComputer();
    }
    else if(menu.compare("3") == 0){
        system("CLS");
        searchData();
    }
    else {
        cout << "Invalid input! " << endl;
    }
}

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


void UI::searchMessage()
{
    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SEARCH                                     |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;

}

void UI::sortMessage()     // sleppa því að taka inn vektorinn, á ekki að vera hér...
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
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;

    cin >> sortMenu;

    vector<Person> vec = my_dom.sort_and_display(sortMenu);
    if(!vec.empty()) {
        displayDatabase(vec);
}


void UI::searchData()
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

        if(searchMenu.compare("1") == 0) {
            cout << "What name would you like to find?: ";
        }
        else if(searchMenu.compare("2") == 0) {
            cout << "A lady or a man? Or maybe a dog?: ";
        }
        else if(searchMenu.compare("3") == 0) {
            cout << "When was the person born?: ";
        }
        else if(searchMenu.compare("4") == 0) {
            cout << "When did the person die?: ";
        }
        else if(searchMenu.compare("5") == 0) {
            cout << "Enter some word and we will see..: ";
        }
        else if(searchMenu.compare("Q") == 0 || searchMenu.compare("q") == 0) {
            return ;
        }
        else {
            cout << "Invalid input! " << endl;
        }
    }  while(atoi(searchMenu.c_str()) <= 0 || atoi(searchMenu.c_str()) > 5);

    cin >> search;
    vector<Person> vec = my_dom.searchstring(searchMenu, search);

    displayDatabase(vec);

    if(vec.size() == 0)
    {
        cout << "Sorry, no match." << endl;
    }
}


void UI::reading_person() {

    string number = "";
    int num = 0;

    do{
        cout << "How many computing geniuses do you want to register? ";
        cin >> number;

        if(number == "Q" || number == "q") {
            return;
        }
        num = atoi(number.c_str());
        if(num <= 0) {
            cout << "Invalid input! " << endl;
        }
    } while(num <= 0);

    cout << endl << "Type in person: " << endl << endl;

    string name = "", gender = "", bio = "", year = "", dead = "";
    int birthyear = 0, deathyear = 0;
    string a = "";

    for(int i = 0; i < num; i++)
    {
        cout << "Name: ";
        cin >> name;

        do{
            cout << "Gender (F/M): ";
            cin >> a;

            if(a.compare("f") == 0 || a.compare("F") == 0){
                gender = "Female";
            }
            else if(a.compare("m") == 0 || a.compare("M") == 0){
                gender = "Male";
            }
            else{
                cout << "Invalid input" << endl;
            }
        }while(gender == "");

        do{
            cout << "Year of birth (1700 - 2010): ";
            cin >> year;

            if(year < "1700" || year > "2010") {
                cout << "Invalid input" << endl;
            }
        }while(year < "1700" || year > "2010");

        birthyear = atoi(year.c_str());


        cout << "Is the scientist dead (Y/N)?: " << endl;
        cin >> dead;
        do{
            if(dead.compare("y") == 0 || dead.compare("Y") == 0) {
                cout << "Year of death: ";  // Dauður
                cin >> year;
                deathyear = atoi(year.c_str());

                if(deathyear < birthyear || deathyear > 2015) {
                    cout << "Invalid input! " << endl;
                }
            }
            else if(dead.compare("n") == 0 || dead.compare("N") == 0) {
                deathyear = -1;     // Ekki dauður
            }

            else{          // Ekki vitað, spyr aftur
                cout << "Invalid input! " << endl;
            }

        }while(deathyear != -1 && deathyear < birthyear || deathyear > 2015);

        cout << "Bio: ";
        cin.ignore();
        getline(cin, bio);
        cout << endl;

        my_dom.add_new_person(name, gender, birthyear, deathyear, bio);
    }
}

void UI::displayDatabase(vector<Person> v)      // Prentar út vektorinn...
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << endl << v[i];
    }
    cout << endl << v.size() << " scientists!" << endl;
}

        //connectToDatabase();

        string DOB;
        string DOD;

       ostringstream convert;
       convert << birthyear;
       DOB = convert.str();

        if (deathyear == (-1))
            DOD = "NULL";
        else
        {
            convert << deathyear;
            DOD = convert.str();
        }

        string temp = "INSERT INTO scientists(name, gender, DOB, DOD, Bio) VALUES ('" + name +
        "', " + "'" + gender + "', " + DOB + ", " + DOD + ", " + "'" + bio + "');";

        /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        QString dbSoC = "database.sqlite";
        db.setDatabaseName(dbSoC);

        db.open();

        QSqlQuery query(db);

        if (!db.open())
        {
            cout << "Unable to open database." << endl;
        }
        else
            query.exec(temp);*/ //virkar ekki for some reason.... arg

        my_dom.add_new_person(name, gender, birthyear, deathyear, bio);
    }
}
