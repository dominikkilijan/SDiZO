#include<iostream>
#include "Menu.h"
#include "HeapMenu.h"
#include "DynamicArrayMenu.h"
#include "ListMenu.h"
//#include <fstream>

using namespace std;

int work =0;

Menu::Menu()
{
        int initChoice = 0;



       /* switch (initChoice)
        {
        case 1:


            {
                cout<<"No to se wpisuj"<<endl;
            }
            break;
        case 2:
            {
                cout<<"Wygenerowano liczby"<<endl;
            }
            break;
        case 3:
            {
                cout<<"Wczytano wartosci"<<endl;
            }
            break;
        }*/



        while(work == 0)
        {
        int choice=0;
        cout << endl<<"MENU GLOWNE:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. Dynamiczna tablica "<<endl;
        cout << "2. Lista dwukierunkowa "<<endl;
        cout << "3. Kopiec "<<endl;
        cout << "4. Koniec programu "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "Wybor: ";
        cin >> choice;

        cout<<"Co chcesz zrobic?"<<endl;
        cout<<"1. Recznie wpisywac wartosci"<<endl;
        cout<<"2. Wygenerowac losowe liczby"<<endl;
        cout<<"3. Wczytac wartosci z pliku"<<endl;
        cin>>initChoice;


        system("cls"); // czyszczenie konsoli

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
        }
    }
}

Menu::~Menu()
{
    cout<<"elo menu"<<endl;
}




