#include <iostream>
#include "DynamicArrayMenu.h"
#include "Menu.h"
#include "DynamicArrayImplementation.h"

using namespace std;

DynamicArrayMenu::DynamicArrayMenu()
{
        cout<<"Poczatkowy limit elementow w dynamicznej tablicy?"<<endl;
        int initialCap;
        cin>>initialCap;

        cout<<"Ile elementow w dynamicznej tablicy?"<<endl;
        int numberOfElements;
        cin>>numberOfElements;

        DynamicArrayImplementation dynamicArray(initialCap, numberOfElements);

        while(arrayWork == 0)
        {
        int arrayChoice=0;
        cout << endl<<"MENU GLOWNE DYNAMICZNEJ TABLICY:"<<endl;
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
        cin >> arrayChoice;
        system("cls"); // clear console

        switch (arrayChoice)
        {
        case 1:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                dynamicArray.addToDyArr(0, val);
            }

            break;

        case 2:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                dynamicArray.addToDyArr(dynamicArray.arraySize, val);
            }

            break;

        case 3:
            {
                int id;
                cout<<"Podaj indeks: ";
                cin>>id;
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;

                dynamicArray.addToDyArr(id, val);
            }

            break;

        case 4:
            dynamicArray.checkIfDownsize();

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:
            dynamicArray.printDyArray();

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

DynamicArrayMenu::~DynamicArrayMenu()
{
    //cout<<"elo array menu"<<endl;
    //system("cls"); // clear console
}
