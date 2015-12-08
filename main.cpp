#include <QCoreApplication>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "ui.h"


using namespace std;

int main()
{
    UI ui;

    char check = 'y';

    do{
        ui.welcome();
        ui.choices();

        cout << endl;
        cout << "Do you wish to continue? (Y/N) " << endl;
        cin >> check;
        ui.clearScreen();

    } while(check == 'y' || check == 'Y');
}
