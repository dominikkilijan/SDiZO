#include <iostream>
#include "ListMenu.h"
#include "Menu.h"
#include "ListImplementation.h"

using namespace std;

ListMenu::ListMenu()
{


        ListImplementation linkedList;

        listWork = 0;
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
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                linkedList.addToList(0, val);
            }

            break;

        case 2:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                linkedList.addToList(linkedList.listSize, val);
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
                linkedList.addToList(id, val);
            }

            break;

        case 4:
            linkedList.removeFromList(0);

            break;

        case 5:
            linkedList.removeFromList(linkedList.listSize);

            break;

        case 6:
            {
                int id;
                cout<<"Podaj indeks: ";
                cin>>id;
                linkedList.removeFromList(id);
            }

            break;

        case 7:
            linkedList.clearList();

            break;

        case 8:
            {
            linkedList.printList();
            linkedList.printListBackwards();
            }

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
    cout<<"elo list menu"<<endl;
    //system("cls"); // clear console
}
