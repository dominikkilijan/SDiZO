#include "HeapImplenetation.h"
#include<math.h>
#include<iostream>
#include "HeapMenu.h"

using namespace std;

int heapSize;
int *length;
int lengthSize;


HeapImplenetation::HeapImplenetation(int heapS)
{
    lengthSize=20;
    length = new int [lengthSize];
    heapSize = heapS;
    cout<<"Wprowadz elementy"<<endl;
    for(int i=0; i<heapSize; i++)
    {
        cin>>length[i];
    }
    buildHeap();

}

HeapImplenetation::~HeapImplenetation()
{
    delete [] length;
}

/**
*
*/
int HeapImplenetation::leftChild(int parentIndex)
{
    return (2*parentIndex+1);
}
int HeapImplenetation::rightChild(int parentIndex)
{
    return (2*parentIndex+2);
}
int HeapImplenetation::parent(int childIndex)
{
    return floor(childIndex/2);
}
void HeapImplenetation::heapSearch(int value)
{

    for (int i=0; i<heapSize; i++)
    {
        if(length[i]==value)
        {
            cout<<"Znaleziono wartosc na indeksie: "<<(i+1)<<endl;
            return;
        }
    }
    cout<<"Nie ma takiej wartosci w kopcu"<<endl;
}

void HeapImplenetation::heapify(int i)
{
    int largest;
    int l = leftChild(i);
    int r = rightChild(i);
    if(l<heapSize && length[l]>length[i] ) largest = l;
    else largest = i;

    if(r<heapSize && length[r]>length[largest]) largest = r;
    if (largest != i)
    {
        /*int bufor=0;
        bufor = length[i];
        length[i] = length[largest];
        length[largest] = bufor;
        heapify(largest);*/
        swap(length[largest], length[i]);
        heapify(largest);
    }
}

void HeapImplenetation::printHeap1()
{
    if (heapSize<=0)   cout<<"Nie ma elementow do wyswietlenia"<<endl;

    int bin=0;
    int elementsInLine=0;
    for(int i=0;i<heapSize;i++)
    {
        cout<<length[i]<<"  ";
        elementsInLine++;


        if (elementsInLine == pow(2,bin))
        {
            cout<<endl;
            bin++;
            elementsInLine=0;
        }

    }
}

void HeapImplenetation::addToHeap(int value)
{
    if(heapSize == lengthSize) cout<<"Kopiec jest pelny!"<<endl;

    else
    {
    cout<<"Dodano element"<<endl;
    heapSize++;
    int i = heapSize-1;
    length[i] = value;

    while(i!=0 && length[parent(i)]<length[i])
    {
        swap(length[parent(i)],length[i]);
        i=parent(i);
    }
    printHeap1();
    }
}

void HeapImplenetation::removeHeapRoot()
{
    if (heapSize <= 0)
        cout<<"Kopiec jest pusty!"<<endl;
    else if (heapSize == 1)
    {
        cout<<"Usunieto korzen z jednoelementowego kopca"<<endl;
        heapSize--;
        length[0] = NULL;
    }
    else
    {
       cout<<"Usunieto korzen z kopca"<<endl;
       heapSize--;
       length[0] = length[heapSize];
       length[heapSize] = NULL;
       heapify(0);
    }
}

void HeapImplenetation::buildHeap()
{
    for (int i=floor(heapSize/2); i>=1; i--)
    {
        heapify(i-1);
    }
}






















