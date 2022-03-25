#include <iostream>
#include "ListMenu.h"
#include "Menu.h"

using namespace std;

ListMenu::ListMenu()
{
        while(listWork == 0)
        {
        int listChoice=0;
        cout << endl<<"MENU GLOWNE LISTY DWUKIERUNKOWEJ:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. Dodaj na poczatek "<<endl;
        cout << "2. Dodaj na koniec "<<endl;
        cout << "3. Dodaj na wybrane miejsce "<<endl;
        cout << "4. Usun z poczatku "<<endl;
        cout << "5. Usun z konca "<<endl;
        cout << "6. Usun z wybranego miejsca "<<endl;
        cout << "7. Wyszukaj element "<<endl;
        cout << "8. Sprawdz poprawnosc struktury "<<endl;
        cout << "9. Powrot do menu glownego "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "Wybor: ";
        cin >> listChoice;
        system("cls"); // clear console

        switch (listChoice)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;

        case 9:
            {
            Menu menu;
            delete this;
            }
            break;
        }
        }
}

ListMenu::~ListMenu()
{
    //cout<<"elo list menu"<<endl;
    //system("cls"); // clear console
}
