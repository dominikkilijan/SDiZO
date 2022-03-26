#include <iostream>
#include "DynamicArrayMenu.h"
#include "Menu.h"
#include "DynamicArrayImplementation.h"
#include <fstream>

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

        if (initOption != 3)
        {
        cout<<"Ile elementow w dynamicznej tablicy?"<<endl;
        cin>>numberOfElements;
        }
        else
        {
            numberOfElements = fileSize;
        }
        cout<<"Number of elements = "<<numberOfElements<<endl;

        DynamicArrayImplementation dynamicArray(initialCap);
        cout<<"Po konstruktorze"<<endl;
        cout<<"Init option = "<<initOption<<endl;
        cout<<"Number of elements = "<<numberOfElements<<endl;

        if (numberOfElements > 0 && initOption == 1)
        {
            cout<<"Wpisz wartosci"<<endl;
            for(int i=0; i<numberOfElements; i++)
            {
                cout<<"Kurwa"<<endl;
                int val;
                cin>>val;
                dynamicArray.addToDyArr(i, val);
            }
        }
        cout<<"Number of elements"<<endl;

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
        cout << "8. Sprawdz poprawnosc struktury "<<endl;
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
                dynamicArray.addToDyArr(0, val);
                dynamicArray.printDyArray();
            }

            break;

        case 2:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                dynamicArray.addToDyArr(dynamicArray.arraySize, val);
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

                dynamicArray.addToDyArr(id, val);
                dynamicArray.printDyArray();
            }

            break;

        case 4:
            {
            dynamicArray.removeFromDyArray(0);
            dynamicArray.printDyArray();
            }

            break;

        case 5:
            {
            dynamicArray.removeFromDyArray(dynamicArray.arraySize);
            dynamicArray.printDyArray();
            }

            break;

        case 6:
            {
                int id;
                cout<<"Podaj indeks: ";
                cin>>id;

                dynamicArray.removeFromDyArray(id);
                dynamicArray.printDyArray();
            }

            break;

        case 7:
            {
                int val;
                cout<<"Podaj wartosc: ";
                cin>>val;
                dynamicArray.arraySearch(val);
                dynamicArray.printDyArray();
            }


            break;

        case 8:
            dynamicArray.printDyArray();

            break;

        case 9:
            {
            arrayWork=1;
            Menu menu;
            delete this;
            }
            break;
        }
        }
}

DynamicArrayMenu::~DynamicArrayMenu()
{
    cout<<"elo array menu"<<endl;
}

void DynamicArrayMenu::getFileInfo()
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

    for(int i = 0; i < fileSize; i++)
    {
        file >> val;

        if(file.fail())
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
    file.close();
    }
    else    cout << "File error - OPEN" << endl;
}
