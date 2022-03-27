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


        if (initOption != 3) // okreslenie liczby poczatkowych elementow
        {
        cout<<"Ile elementow w liscie?"<<endl;
        cin>>numberOfElements;
        }
        else // liczba poczatkowych elementow jest juz zapisana w pliku tekstowym
        {
            getFileInfo();
            numberOfElements = fileSize;
        }

        ListImplementation linkedList;

        if (numberOfElements > 0 && initOption == 1) // reczne wpisanie wartosci
        {
            cout<<"Wpisz wartosci"<<endl;
            for(int i=0; i<numberOfElements; i++)
            {
                int val;
                cin>>val;

                linkedList.addToList(i, val);
            }
        }

        if (numberOfElements > 0 && initOption == 2) // uzycie liczb pseudolosowych do wypelnienia listy
        {
            cout<<"Liczby losowe"<<endl;
            srand(time(NULL));

            for (int i = 0; i < numberOfElements; i++)
            {

            linkedList.addToList(i, rand()%100);
            }
        }
        if (numberOfElements > 0 && initOption == 3) // wpisanie do listy elementow z pliku
        {
            cout<<"Wczytywanie z pliku"<<endl;
            cout<<"NoE = "<<numberOfElements<<endl;
            for (int i = 0; i< numberOfElements; i++)
            {
                linkedList.addToList(i, fileArray[i]);
            }
            delete [] fileArray;
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
        cout << "8. Wypisz elementy listy od przodu i od tylu "<<endl;
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
                linkedList.addToList(0, val); // dodawanie na index = 0
                linkedList.printList();
            }

            break;

        case 2:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                linkedList.addToList(linkedList.listSize, val); // dodawanie na ostatni index = listSize
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
                linkedList.addToList(id, val); // dodawanie na wybrany indeks. Wczesniejsza wartosc jest przenoszona do nastepnego wezla
                linkedList.printList();
            }

            break;

        case 4:
            {
            linkedList.removeFromList(0); // usuwanie pierwszego elementu (z indeksu = 0)
            linkedList.printList();
            }

            break;

        case 5:
            {
            linkedList.removeFromList(linkedList.listSize-1); // usuwanie wezla z konca listy
            linkedList.printList();
            }

            break;

        case 6:
            {
                int id;
                cout<<"Podaj indeks: ";
                cin>>id;
                linkedList.removeFromList(id); // usuwanie z wybranego miejsca
                linkedList.printList();
            }

            break;

        case 7:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                linkedList.searchList(val); // szukanie wartosci w strukturze
                linkedList.printList();
            }
            break;

        case 8:
            {
                linkedList.printList(); // wyswietlanie max 15 elementow od przodu i od tylu
                linkedList.printListBackwards();
            }

            break;

        case 9:
            {
            Menu menu; // powrot do menu glownego
            delete this;
            }
            break;
        default:
            cout<<"Nieprawidlowy numer polecenia. Sprobuj jeszcze raz"<<endl;
        }
        }
}

ListMenu::~ListMenu()
{
    delete [] fileArray;
}

void ListMenu::getFileInfo() // odczytywanie wartosci z pliku do nowej tablicy
{
    listFile.open("Values.txt", ios::in);
    int val;

    if(listFile.is_open())
    {
    listFile >> fileSize;
    if(listFile.fail())  cout << "File error - READ SIZE" << endl; // jesli plik jest pusty
    else
    {
    fileArray = new int [fileSize];


    for(int i = 0; i < fileSize; i++)
    {
        listFile >> val;

        if(listFile.fail())
        {
            cout << "File error - READ DATA" << endl; // jesli w pliku jest tylko rozmiar>0
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
    else    cout << "File error - OPEN" << endl; // jesli nie znaleziono pliku o podanej nazwie
}
