#include<iostream>
#include "Menu.h"
#include "HeapMenu.h"
#include "DynamicArrayMenu.h"
#include "ListMenu.h"
#include <fstream>

using namespace std;

int work =0;

Menu::Menu()
{
        int initChoice = 0;



        switch (initChoice)
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
        }



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
                switch (initChoice)
                {
                case 1:
                    {
                    cout<<"No to se wpisuj"<<endl;

                    DynamicArrayMenu dynamicArrayMenu;
                    }
                    break;
                case 2:
                    {
                    cout<<"Wygenerowanie liczb"<<endl;
                    }
                    break;
                case 3:
                    {
                    cout<<"Wczytanie wartosci"<<endl;
                    getFileInfo();

                    }
                    break;
                }

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

void Menu::getFileInfo()
{
    file.open("Values.txt", ios::in);
    int val;

    if(file.is_open())
    {
    file >> fileSize;
    if(file.fail())  cout << "File error - READ SIZE" << endl;
    else
    {
    fileArray = new int [fileSize];
    int fileArray[fileSize];
    cout<<"File size: "<<fileSize<<endl;

    for(int i = 0; i < fileSize; i++)
    {
        file >> val;
        cout<<"Val: "<<val<<endl;

        if(file.fail())
        {
            cout << "File error - READ DATA" << endl;
            break;
        }
        else
        {
            fileArray[i] = val;
            cout<<"W tablicy: "<<fileArray[i]<<endl;
            //file.
        }
    }
    }
    file.close();
    }
    else    cout << "File error - OPEN" << endl;
}




