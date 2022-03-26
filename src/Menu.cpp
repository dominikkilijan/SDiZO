#include<iostream>
#include "Menu.h"
#include "HeapMenu.h"
#include "DynamicArrayMenu.h"
#include "ListMenu.h"

using namespace std;

int work =0;

Menu::Menu()
{
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
        system("cls"); // czyszczenie konsoli

        switch (choice)
        {
        case 1:
            {
            DynamicArrayMenu dynamicArrayMenu;
            delete this;
            }
            break;

        case 2:
            {
            ListMenu listMenu;
            delete this;
            }
            break;

        case 3:
            {
            HeapMenu heapMenu;
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




