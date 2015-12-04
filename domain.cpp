#include "domain.h"


bool sortbyyearofbirth (const Person& a, const Person &b) {
    return a.birthYear < b.birthYear;
}

bool sortbygender (const Person& a, const Person &b) {
    return a.gender < b.gender;
}
bool sortbyyearofdeath (const Person& a, const Person &b) {
    return a.deathYear < b.deathYear;
}

Domain::Domain() {

    v = DB.read_from_DB();
}

int Domain::size() {
    return v.size();
}

void Domain::add_new_person(string name, string gender, int birthyear, int deathyear, string bio) {     // Bætir nýrri persónu inn i vektorinn...

    Person newP = Person(name, gender, birthyear, deathyear, bio);
    v.push_back(newP);
    DB.add_new_scientist(newP);
    //DB.write_to_DB(v);
}

vector<Person> Domain::sort_and_display(string sortMenu) {        // sorterar vektorinn...

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


vector<Person> Domain::searchstring(string num, string search) {

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

