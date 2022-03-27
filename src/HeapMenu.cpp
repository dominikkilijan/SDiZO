#include<iostream>
#include "HeapMenu.h"
#include "Menu.h"
#include "HeapImplenetation.h"
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

int heapWork = 1;
fstream heapFile;




HeapMenu::HeapMenu(int option)
{
        heapWork = 0;
        initOption = option;


        if (initOption != 3) // okreslenie liczby poczatkowych elementow
        {
        cout<<"Maksymalna pojemnosc kopca?"<<endl;
        cin>>heapCap;

        cout<<"Ile elementow w kopcu?"<<endl;
        cin>>numberOfHeapElements;
        }
        else // liczba poczatkowych elementow jest juz zapisana w pliku tekstowym
        {
            getFileInfo();
            numberOfHeapElements = fileSize;
            heapCap = fileSize+5;
        }


        HeapImplenetation heap(heapCap);

        if (numberOfHeapElements > 0 && initOption == 1) // reczne wpisanie wartosci
        {
            cout<<"Wpisz wartosci"<<endl;
            for(int i=0; i<numberOfHeapElements; i++)
            {
                int val;
                cin>>val;
                heap.addToHeap(val, 0);
            }
        }

        if (numberOfHeapElements > 0 && initOption == 2) // uzycie liczb pseudolosowych do wypelnienia listy
        {
            cout<<"Liczby losowe"<<endl;
            srand(time(NULL));

            for (int i = 0; i < numberOfHeapElements; i++)
            {
            heap.addToHeap(rand()%100, 0);
            }
        }
        if (numberOfHeapElements > 0 && initOption == 3) // wpisanie do listy elementow z pliku
        {
            cout<<"Wczytywanie z pliku"<<endl;
            cout<<"NoE = "<<numberOfHeapElements<<endl;
            for (int i = 0; i< numberOfHeapElements; i++)
            {
                heap.addToHeap(fileArray[i], 0);
            }
            delete [] fileArray;
        }

        while(heapWork==0)
        {
        int heapChoice=0;
        cout << endl<<"MENU GLOWNE KOPCA:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. Dodaj element "<<endl;
        cout << "2. Usun korzen "<<endl;
        cout << "3. Wyszukaj element "<<endl;
        cout << "4. Wypisz elementy struktury "<<endl;
        cout << "5. Powrot do menu glownego "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "Wybor: ";
        cin >> heapChoice;
        system("cls"); // clear console

        switch (heapChoice)
        {
        case 1:
            {
            int val;
            cout<<"Podaj wartosc dodawanego elementu: "<<endl;
            cin>>val;

            heap.addToHeap(val, 1); // dodawanie na koniec kopca


            heap.printHeap1();
            }
            break;

        case 2:
            {
            heap.removeHeapRoot(); // usuwanie korzenia
            heap.printHeap1();
            }

            break;

        case 3:
            {
            int val;
            cout<<"Podaj wartosc szukanego elementu: "<<endl;
            cin>>val;
            heap.heapSearch(val); // szukanie wartosci w strukturze
            heap.printHeap1();
            }

            break;

        case 4:
            heap.printHeap1(); // wyswietlanie max 15 elementow

            break;

        case 5:
            {
            heapWork =1;
            Menu menu; // powrot do menu glownego
            delete this;
            }
            break;
        default:
            cout<<"Nieprawidlowy numer polecenia. Sprobuj jeszcze raz"<<endl;
        }
        }
}

HeapMenu::~HeapMenu()
{
    delete [] fileArray;
}

void HeapMenu::getFileInfo() // odczytywanie wartosci z pliku do nowej tablicy
{
    heapFile.open("Values.txt", ios::in);
    int val;

    if(heapFile.is_open())
    {
    heapFile >> fileSize;
    if(heapFile.fail())  cout << "File error - READ SIZE" << endl; // jesli plik jest pusty
    else
    {
    fileArray = new int [fileSize];


    for(int i = 0; i < fileSize; i++)
    {
        heapFile >> val;

        if(heapFile.fail())
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
    heapFile.close();
    }
    else    cout << "File error - OPEN" << endl; // jesli nie znaleziono pliku o podanej nazwie
}



