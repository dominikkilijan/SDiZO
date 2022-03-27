#include <iostream>
#include "DynamicArrayMenu.h"
#include "Menu.h"
#include "DynamicArrayImplementation.h"
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

int arrayWork = 0;
fstream file;
int numberOfElements;

DynamicArrayMenu::DynamicArrayMenu(int option)
{

        initOption = option;

        cout<<"Poczatkowy limit elementow w dynamicznej tablicy?"<<endl;
        int initialCap;
        cin>>initialCap;

        if (initOption != 3) // okreslenie liczby poczatkowych elementow
        {
        cout<<"Ile elementow w dynamicznej tablicy?"<<endl;
        cin>>numberOfElements;
        }
        else // liczba poczatkowych elementow jest juz zapisana w pliku tekstowym
        {
            getFileInfo();
            numberOfElements = fileSize;
        }

        DynamicArrayImplementation dynamicArray(initialCap);

        if (numberOfElements > 0 && initOption == 1) // reczne wpisanie wartosci
        {
            cout<<"Wpisz wartosci"<<endl;
            for(int i=0; i<numberOfElements; i++)
            {
                int val;
                cin>>val;
                dynamicArray.addToDyArr(i, val);
            }
        }

        if (numberOfElements > 0 && initOption == 2) // uzycie liczb pseudolosowych do wypelnienia tablicy
        {
            cout<<"Liczby losowe"<<endl;
            srand(time(NULL));

            for (int i = 0; i < numberOfElements; i++)
            {
            dynamicArray.addToDyArr(i, rand()%100);
            }
        }
        if (numberOfElements > 0 && initOption == 3) // wpisanie do tablicy elementow z pliku
        {
            cout<<"Wczytywanie z pliku"<<endl;
            cout<<"NoE = "<<numberOfElements<<endl;
            for (int i = 0; i< numberOfElements; i++)
            {
                dynamicArray.addToDyArr(i, fileArray[i]);
            }
            delete [] fileArray;
        }




        arrayWork = 0;
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
        cout << "8. Wyswietl elementy tablicy "<<endl;
        cout << "9. Powrot do menu glownego "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "Wybor: ";
        cin >> arrayChoice;
        system("cls"); // czyszczenie konsoli

        switch (arrayChoice)
        {
        case 1:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                dynamicArray.addToDyArr(0, val); // dodawanie na index = 0
                dynamicArray.printDyArray();
            }

            break;

        case 2:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                dynamicArray.addToDyArr(dynamicArray.arraySize, val); // dodawanie na ostatni index = arraySize
                dynamicArray.printDyArray();
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

                dynamicArray.addToDyArr(id, val); // dodawanie na wybrany indeks. Wczesniejsza wartosc jest przenoszona na nastepny indeks
                dynamicArray.printDyArray();
            }

            break;

        case 4:
            {
            dynamicArray.removeFromDyArray(0); // usuwanie pierwszego elementu ( indeks = 0)
            dynamicArray.printDyArray();
            }

            break;

        case 5:
            {
            dynamicArray.removeFromDyArray(dynamicArray.arraySize); // usuwanie wartosci z konca
            dynamicArray.printDyArray();
            }

            break;

        case 6:
            {
                int id;
                cout<<"Podaj indeks: ";
                cin>>id;

                dynamicArray.removeFromDyArray(id); // usuwanie z wybranego miejsca
                dynamicArray.printDyArray();
            }

            break;

        case 7:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                dynamicArray.arraySearch(val); // szukanie wartosci w strukturze
                dynamicArray.printDyArray();
            }


            break;

        case 8:
            dynamicArray.printDyArray(); // wyswietlanie max 15 elementow

            break;

        case 9:
            {
            arrayWork=1;
            Menu menu; // powrot do menu glownego
            delete this;
            }
            break;
        }
        }
}

DynamicArrayMenu::~DynamicArrayMenu()
{
    delete [] fileArray;
}

void DynamicArrayMenu::getFileInfo() // odczytywanie wartosci z pliku do nowej tablicy
{
    file.open("Values.txt", ios::in);
    int val;

    if(file.is_open())
    {
    file >> fileSize;
    if(file.fail())  cout << "File error - READ SIZE" << endl; // jesli plik jest pusty
    else
    {
    fileArray = new int [fileSize];


    for(int i = 0; i < fileSize; i++)
    {
        file >> val;

        if(file.fail())
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
    file.close();
    }
    else    cout << "File error - OPEN" << endl; // jesli nie znaleziono pliku o podanej nazwie
}
