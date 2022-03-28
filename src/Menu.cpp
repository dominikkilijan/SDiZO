#include<iostream>
#include "Menu.h"
#include "HeapMenu.h"
#include "DynamicArrayMenu.h"
#include "ListMenu.h"

using namespace std;

int work;

Menu::Menu()
{
        int initChoice = 0; // wybor inicjalizacji

        work = 0;

        while(work == 0) // ciagle wyswietlaj menu
        {
        int choice=0; // wybor struktury
        cout << endl<<"MENU GLOWNE:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. Dynamiczna tablica "<<endl;
        cout << "2. Lista dwukierunkowa "<<endl;
        cout << "3. Kopiec "<<endl;
        cout << "4. Koniec programu "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "Wybor: ";
        cin >> choice;

        if (choice < 4 && choice > 0) // nie ma potrzeby wyswietlac opcji inicjalizacji przy wylaczaniu programu
        {
        cout<<"Sposob wpisania poczatkowych danych"<<endl;
        cout<<"1. Reczne wpisywanie wartosci"<<endl;
        cout<<"2. Wygenerowanie liczb losowych"<<endl;
        cout<<"3. Wczytanie wartosci z pliku"<<endl;
        cin>>initChoice;
        if (initChoice > 3 || initChoice < 0)
        {
            cout<<"Nieprawidlowy numer. Liczby beda wpiywane recznie"<<endl;
            initChoice = 1;
        }
        else system("cls"); // czyszczenie konsoli
        }




        switch (choice)
        {
        case 1:
            {
            DynamicArrayMenu dynamicArrayMenu(initChoice);
            delete this;
            }
            break;

        case 2:
            {
            ListMenu listMenu(initChoice);
            delete this;
            }
            break;

        case 3:
            {
            HeapMenu heapMenu(initChoice);
            delete this;
            }
            break;

        case 4:
            work=1;
            exit(0);

            break;
        default:
            cout<<"Nieprawidlowy numer polecenia. Sprobuj jeszcze raz"<<endl;
        }

    }
}

Menu::~Menu()
{

}




