#include "HeapImplenetation.h"
#include<math.h>
#include<iostream>
#include "HeapMenu.h"
#include <iomanip>
#include <windows.h>

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

long long int HeapImplenetation::read_QPC()
{
    LARGE_INTEGER count;

    QueryPerformanceCounter(&count);
    return ((long long int)count.QuadPart);
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
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();  // poczatek pomiaru czasu

    for (int i=0; i<heapSize; i++)
    {
        if(length[i]==value)
        {
            cout<<"Znaleziono wartosc na indeksie: "<<(i+1)<<endl;
            elapsed = read_QPC() - start; // koniec pomiaru czasu jesli znaleziono element

            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
            cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
            cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
            return;
        }
    }
    cout<<"Nie ma takiej wartosci w kopcu"<<endl;

    elapsed = read_QPC() - start; // koniec pomiaru czasu jesli nie znaleziono szukanej wartosci

    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
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
// wyswietlanie wszystkich lub max 15 kolejnych wartosci
void HeapImplenetation::printHeap1()
{
    if (heapSize<=0)   cout<<"Nie ma elementow do wyswietlenia"<<endl;
    else
    {
        maxPrintSize = 15; // ile elementow mozna maksymalnie wyswietlic
        if (heapSize <= 15) // jesli liczba elementow jest mniejsza niz 15 to wyswietl wszyskie wartosci
        {                   // w przeciwnym wypadku wyswietl pierwsze 15 wartosci
            maxPrintSize = heapSize;
        }

    int bin=0;
    int elementsInLine=0;
    string spaces[8] = {"       ", "", "   ", "    ", " ", "  ", "", " "};
    string *beginSpaces= &spaces[0];
    string *endSpaces= &spaces[1];
    for(int i=0;i<maxPrintSize;i++)
    {
        cout<<*beginSpaces<<length[i]<<*endSpaces;
        elementsInLine++;


        if (elementsInLine == pow(2,bin)) // liczba elementow na kolejnych poziomach kopca to potegi 2 czyli 1,2,4,8 itd
        {
            cout<<endl;
            bin++;
            elementsInLine=0; // po kazdej potedze 2 licznik jest zerowany
            beginSpaces +=2;
            endSpaces +=2;

        }

    }
    }
}

// dodawanie elementu na ostatnia pozycje w kopcu i ewentualna zamiana miejscami
void HeapImplenetation::addToHeap(int value)
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();  // poczatek pomiaru czasu

    if(heapSize == lengthSize) cout<<"Kopiec jest pelny!"<<endl;

    else
    {
    cout<<"Dodano element"<<endl;
    heapSize++;
    int i = heapSize-1; // indeks ostatniego (nowego) elementu
    length[i] = value;

    buildHeap();
    }
    elapsed = read_QPC() - start; // koniec pomiaru czasu

    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
}

// usuwanie korzenia kopca = najwszyzszej wartosci.
void HeapImplenetation::removeHeapRoot()
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC(); // poczatek pomiaru czasu

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
    elapsed = read_QPC() - start; // koniec pomiaru czasu

    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;
}

// ukladanie elementow zgodnie z zalozeniami kopca max. Sprawdza wszystkie elementy kopca
void HeapImplenetation::buildHeap()
{
    for (int i=floor(heapSize/2); i>=1; i--) // floor(heapsize/2) zwraca rodzica (nie-lisc) z najwiekszym indeksem
    {
        heapify(i-1);
    }
}
