#include <iostream>
#include "ListMenu.h"
#include "Menu.h"
#include "ListImplementation.h"
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

fstream listFile;

ListMenu::ListMenu(int option)
{
        listWork = 0;
        initOption = option;


        if (initOption != 3)
        {
        cout<<"Ile elementow w liscie?"<<endl;
        cin>>numberOfElements;
        }
        else
        {
            getFileInfo();
            numberOfElements = fileSize;
        }

        ListImplementation linkedList;

        if (numberOfElements > 0 && initOption == 1)
        {
            cout<<"Wpisz wartosci"<<endl;
            for(int i=0; i<numberOfElements; i++)
            {
                int val;
                cin>>val;

                linkedList.addToList(i, val);
            }
        }

        if (numberOfElements > 0 && initOption == 2)
        {
            cout<<"Liczby losowe"<<endl;
            srand(time(NULL));

            for (int i = 0; i < numberOfElements; i++)
            {

            linkedList.addToList(i, rand()%100);
            }
        }
        if (numberOfElements > 0 && initOption == 3)
        {
            cout<<"Wczytywanie z pliku"<<endl;
            cout<<"NoE = "<<numberOfElements<<endl;
            for (int i = 0; i< numberOfElements; i++)
            {
                linkedList.addToList(i, fileArray[i]);
            }
        }


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
        system("cls"); // czyszczenie konsoli

        switch (listChoice)
        {
        case 1:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                linkedList.addToList(0, val); //index = 0
                linkedList.printList();
            }

            break;

        case 2:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                linkedList.addToList(linkedList.listSize, val); // index = listSize
                linkedList.printList();
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
                linkedList.printList();
            }

            break;

        case 4:
            {
            linkedList.removeFromList(0);
            linkedList.printList();
            }

            break;

        case 5:
            {
            linkedList.removeFromList(linkedList.listSize-1);
            linkedList.printList();
            }

            break;

        case 6:
            {
                int id;
                cout<<"Podaj indeks: ";
                cin>>id;
                linkedList.removeFromList(id);
                linkedList.printList();
            }

            break;

        case 7:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                linkedList.searchList(val);
                linkedList.printList();
            }
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
}

void ListMenu::getFileInfo()
{
    listFile.open("Values.txt", ios::in);
    int val;

    if(listFile.is_open())
    {
    listFile >> fileSize;
    if(listFile.fail())  cout << "File error - READ SIZE" << endl;
    else
    {
    fileArray = new int [fileSize];


    for(int i = 0; i < fileSize; i++)
    {
        listFile >> val;

        if(listFile.fail())
        {
            cout << "File error - READ DATA" << endl;
            break;
        }
        else
        {
            fileArray[i] = val;
        }
    }
    }
    listFile.close();
    }
    else    cout << "File error - OPEN" << endl;
}
