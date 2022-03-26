#include "HeapImplenetation.h"
#include<math.h>
#include<iostream>
#include "HeapMenu.h"
#include<windows.h>

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

// zwracanie indeksow od 0
int HeapImplenetation::leftChild(int parentIndex) // indeks lewego dziecka
{
    return (2*parentIndex+1);
}
int HeapImplenetation::rightChild(int parentIndex) // indeks prawego dziecka
{
    return (2*parentIndex+2);
}
int HeapImplenetation::parent(int childIndex) // indeks rodzica
{
    return floor(childIndex/2);
}

//szukanie elementu na podstawie wartosci. Wyswietla indeks
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


// porzadkuje elementy wedlug zalozen kopca max
void HeapImplenetation::heapify(int i)
{
    int largest;
    int l = leftChild(i);
    int r = rightChild(i);
    if(l<heapSize && length[l]>length[i] ) largest = l; // wyznaczanie najwiekszej wartosci wsrod rodzica i jego dzieci
    else largest = i;

    if(r<heapSize && length[r]>length[largest]) largest = r;
    if (largest != i)
    {
        swap(length[largest], length[i]); // zamiana elementow w kopcu
        heapify(largest);
    }
}

// wyswietlanie elementow kopca po tyle elementow ile byloby rysowane na kartce. Nie sa zachowane odleglosci i nie ma linii miedzy rodzicem i dziecmi
void HeapImplenetation::printHeap1()
{
    if (heapSize<=0)   cout<<"Nie ma elementow do wyswietlenia"<<endl;

    int bin=0;
    int elementsInLine=0;
    for(int i=0;i<heapSize;i++)
    {
        cout<<length[i]<<"  ";
        elementsInLine++;


        if (elementsInLine == pow(2,bin)) // liczba elementow na kolejnych poziomach kopca to potegi 2 czyli 1,2,4,8 itd
        {
            cout<<endl;
            bin++;
            elementsInLine=0; // po kazdej potedze 2 licznik jest zerowany
        }

    }
}

// dodawanie elementu na ostatnia pozycje w kopcu i ewentualna zamiana miejscami
void HeapImplenetation::addToHeap(int value)
{
    if(heapSize == lengthSize) cout<<"Kopiec jest pelny!"<<endl;

    else
    {
    cout<<"Dodano element"<<endl;
    heapSize++;
    int i = heapSize-1; // indeks ostatniego (nowego) elementu
    length[i] = value;

    while(i!=0 && length[parent(i)]<length[i]) // jesli nowo dodany element jest wiekszy od rodzica to zamien je miejscami. Sprawdzaj az do korzenia
    {
        swap(length[parent(i)],length[i]);
        i=parent(i);
    }
    printHeap1();
    }
}

// usuwanie korzenia kopca = najwszyzszej wartosci.
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
       length[0] = length[heapSize]; // na miejscu starego korzenia pojawia sie ostatni element w kopcu i nastepuje przywracanie wlasciwosci kopaca max
       length[heapSize] = NULL;
       heapify(0);
    }
}

// ukladanie elementow zgodnie z zalozeniami kopca max. Metoda uzywana w konstruktorze
void HeapImplenetation::buildHeap()
{
    for (int i=floor(heapSize/2); i>=1; i--) // floor(heapsize/2) zwraca rodzica (nie-lisc) z najwiekszym indeksem
    {
        heapify(i-1);
    }
}
