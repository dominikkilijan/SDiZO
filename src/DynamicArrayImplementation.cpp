#include <iostream>
#include "DynamicArrayImplementation.h"
#include <iomanip>
#include <windows.h>

using namespace std;

int arrayCapacity;
int basicArray;
int arraySize;

DynamicArrayImplementation::DynamicArrayImplementation(int cap, int initSize)
{

    if(cap<0) cout<<"Nieprawidlowy rozmiar tablicy!"<<endl;
    arrayCapacity = cap;
    arraySize = initSize;
    dArray = new int[arrayCapacity];
    cout<<"Wpisz wartosci"<<endl;
    for(int i=0; i<arraySize; i++)
    {
        cin>>dArray[i];
    }

}

DynamicArrayImplementation::~DynamicArrayImplementation()
{
    cout<<"elo dynamiczna tablica!"<<endl;
    delete[] dArray;
}

long long int DynamicArrayImplementation::read_QPC()
{
    LARGE_INTEGER count;

    QueryPerformanceCounter(&count);
    return ((long long int)count.QuadPart);
}

// jesli koncza sie miejsca w tablicy to rozmiar jest zwiekszany dwukrotnie
void DynamicArrayImplementation::checkIfResize()
{
    if (arraySize+1>=arrayCapacity)
    {
        if (arrayCapacity == 0) arrayCapacity = 4;
        else arrayCapacity *= 2;


        int *newArray;
        newArray = new int[arrayCapacity];

        for(int i=0; i<(arrayCapacity/2);i++)
        {
            newArray[i]=dArray[i];
        }
        delete[] dArray;
        cout<<"Zwiekszono miejsce w tablicy"<<endl;
        dArray = newArray;

    }
}

// jesli w tablicy jest duzo wolnych miejsc to rozmiar jest zmniejszany dwukrotnie
void DynamicArrayImplementation::checkIfDownsize()
{
    if (arraySize<=arrayCapacity/4)
    {
        if (arrayCapacity == 0) cout<<"Tablica jest pusta"<<endl;
        else arrayCapacity /= 2;


        int *newArray;
        newArray = new int[arrayCapacity];

        for(int i=0; i<(arrayCapacity/2);i++)
        {
            newArray[i]=dArray[i];
        }
        delete[] dArray;
        cout<<"Zmniejszono miejsce w tablicy"<<endl;
        dArray = newArray;

    }
}

void DynamicArrayImplementation::addToDyArr(int index, int value)
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();  // poczatek pomiaru czasu

    if (index > arraySize)  cout<<"Nie mozna dodac elementu w to miejsce"<<endl;

    else
    {
    checkIfResize(); // sprawdzenie czy nie trzeba zrobic wiecej miejsca w tablicy

    int *newArr;
    newArr = new int[arrayCapacity];

    for(int i=0; i<index; i++) // przepisanie elementow przed docelowym indeksem
    {
        newArr[i]=dArray[i];
    }

    newArr[index]=value; // dodanie nowego elementu
    arraySize++;

    for(int j=index+1; j<arraySize; j++) // przepisanie pozostalych wartosci w tablicy
    {
        newArr[j]=dArray[j-1];
    }

    delete[] dArray;
    dArray = newArr;

    }
    elapsed = read_QPC() - start; // koniec pomiaru czasu

    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
}

void DynamicArrayImplementation::printDyArray()
{
    for(int i=0; i<arraySize; i++)
    {
        cout<<(int)dArray[i]<<"  ";
    }
    cout<<endl;
}



void DynamicArrayImplementation::removeFromDyArray(int index)
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();  // poczatek pomiaru czasu

    if (index > arraySize)  cout<<"Nie mozna usunac elementu z tego miejsca"<<endl;
    else
    {

    int *newArr;
    newArr = new int[arrayCapacity];

    for(int i=0; i<index; i++) // przepisanie elementow przed docelowym indeksem
    {
        newArr[i]=dArray[i];
    }

    arraySize--;

    for(int j=index; j<arraySize; j++) // pominiecie wartosci z wybranego indeksu i skopiowanie reszty
    {
        newArr[j]=dArray[j+1];
    }

    delete[] dArray;
    dArray = newArr;

    checkIfDownsize(); // sprawdzenie czy nie zmniejszyc tablicy

    }
    elapsed = read_QPC() - start; // koniec pomiaru czasu

    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
}

// szukanie indeksu na podstawie podanej wartosci
void DynamicArrayImplementation::arraySearch(int value)
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();  // poczatek pomiaru czasu

    for (int i=0; i<arraySize; i++)
    {
        if(dArray[i]==value)
        {
            cout<<"Znaleziono wartosc na indeksie: "<<(i)<<endl;
            elapsed = read_QPC() - start; // koniec pomiaru czasu po znalezieniu wartosci

            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
            cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
            cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
            return;
        }
    }
    cout<<"Nie ma takiej wartosci w tablicy"<<endl;

    elapsed = read_QPC() - start; // koniec pomiaru czasu jesli nie znaleziono wartosci

    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
}
