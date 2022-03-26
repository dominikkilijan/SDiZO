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


        if (initOption != 3)
        {
        cout<<"Ile elementow w kopcu?"<<endl;
        cin>>numberOfElements;
        }
        else
        {
            getFileInfo();
            numberOfElements = fileSize;
        }


        HeapImplenetation heap(numberOfElements);

        if (numberOfElements > 0 && initOption == 1)
        {
            cout<<"Wpisz wartosci"<<endl;
            for(int i=0; i<numberOfElements; i++)
            {
                int val;
                cin>>val;
                heap.addToHeap(val);
            }
        }

        if (numberOfElements > 0 && initOption == 2)
        {
            cout<<"Liczby losowe"<<endl;
            srand(time(NULL));

            for (int i = 0; i < numberOfElements; i++)
            {
            heap.addToHeap(rand()%100);
            }
        }
        if (numberOfElements > 0 && initOption == 3)
        {
            cout<<"Wczytywanie z pliku"<<endl;
            cout<<"NoE = "<<numberOfElements<<endl;
            for (int i = 0; i< numberOfElements; i++)
            {
                heap.addToHeap(fileArray[i]);
            }
        }

        while(heapWork==0)
        {
        int heapChoice=0;
        cout << endl<<"MENU GLOWNE KOPCA:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. Dodaj element "<<endl;
        cout << "2. Usun korzen "<<endl;
        cout << "3. Wyszukaj element "<<endl;
        cout << "4. Sprawdz poprawnosc struktury "<<endl;
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
            heap.addToHeap(val);
            heap.printHeap1();
            }
            break;

        case 2:
            {
            heap.removeHeapRoot();
            heap.printHeap1();
            }

            break;

        case 3:
            {
            int val;
            cout<<"Podaj wartosc szukanego elementu: "<<endl;
            cin>>val;
            heap.heapSearch(val);
            heap.printHeap1();
            }

            break;

        case 4:
            heap.printHeap1();

            break;

        case 5:
            {
            heapWork =1;
            Menu menu;
            delete this;
            }
            break;
        }
        }
}

HeapMenu::~HeapMenu()
{

}

void HeapMenu::getFileInfo()
{
    heapFile.open("Values.txt", ios::in);
    int val;

    if(heapFile.is_open())
    {
    heapFile >> fileSize;
    if(heapFile.fail())  cout << "File error - READ SIZE" << endl;
    else
    {
    fileArray = new int [fileSize];


    for(int i = 0; i < fileSize; i++)
    {
        heapFile >> val;

        if(heapFile.fail())
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
    heapFile.close();
    }
    else    cout << "File error - OPEN" << endl;
}


