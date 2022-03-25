#include<iostream>
#include "HeapMenu.h"
#include "Menu.h"
#include "HeapImplenetation.h"

using namespace std;

int heapWork = 1;


HeapMenu::HeapMenu()
{
        heapWork = 0;
        cout<<"Ile elementow w kopcu?"<<endl;
        cin>>numberOfElements;

        HeapImplenetation heap(numberOfElements);

        while(heapWork ==0)
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
            }
            break;

        case 2:
            {
            heap.removeHeapRoot();
            }

            break;

        case 3:
            {
            int val;
            cout<<"Podaj wartosc szukanego elementu: "<<endl;
            cin>>val;
            heap.heapSearch(val);
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
    //system("cls"); // clear console
}


