#include <iostream>
#include "DynamicArrayImplementation.h"

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
            cout<<newArray[i]<<"    "<<dArray[i]<<endl;
        }
        delete[] dArray;
        cout<<"Zwiekszono miejsce w tablicy"<<endl;
        dArray = newArray;
        printDyArray();
        //delete []newArray;

    }
}
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
            cout<<newArray[i]<<"    "<<dArray[i]<<endl;
        }
        delete[] dArray;
        cout<<"Zmniejszono miejsce w tablicy"<<endl;
        dArray = newArray;
        printDyArray();

    }
}

void DynamicArrayImplementation::addToDyArr(int index, int value)
{
    if (index > arraySize)  cout<<"Nie mozna dodac elementu w to miejsce"<<endl;

    else
    {
    checkIfResize();
    cout<<"Dodawanie nowego elementu"<<endl;
    printDyArray();

    int *newArr;
    newArr = new int[arrayCapacity];

    for(int i=0; i<index; i++)
    {
        newArr[i]=dArray[i];
    }
    cout<<"Przepisano wczesniejsze wartosci"<<endl;
    printDyArray();

    newArr[index]=value;
    arraySize++;

    cout<<"Dodano nowy element"<<endl;
    printDyArray();

    for(int j=index+1; j<arraySize; j++)
    {
        newArr[j]=dArray[j-1];
    }
    cout<<"Skopiowano reszte tablicy"<<endl;
    printDyArray();
    delete[] dArray;
    dArray = newArr;
    cout<<"Wszystko gotowe"<<endl;
    printDyArray();
    }
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
    if (index > arraySize)  cout<<"Nie mozna usunac elementu z tego miejsca"<<endl;
    else
    {

    }
}
