#include <iostream>
#include "ListImplementation.h"

using namespace std;


ListImplementation::ListImplementation()
{
    listSize = 0;
}

ListImplementation::~ListImplementation()
{
    cout<<"elo linked list"<<endl;
    clearList();
    delete newNode;
}

void ListImplementation::removeFromList(int index)
{
    if (index < 0 || index > listSize-1 || listSize == 0) cout<<"Nie mozna usunac elementu. Nieprawidlowy numer indeksu"<<endl;

    else if (listSize == 1) // usuwanie ostatniego elementu
    {
        delete head;
        listSize--;
        cout<<"Usunieto ostatni element. Lista jest pusta"<<endl;
    }

    else if (index == 0) //usuwanie elementu z poczatku
    {

        newNode = head->nextNode;
        newNode->prevNode = nullptr;
        delete head;
        head = newNode;

        listSize--;
        cout<<"Usunieto element"<<endl;
    }
    else if (index == listSize) //usuwanie elementu z konca
    {
        newNode = tail->prevNode;
        newNode->nextNode = nullptr;

        delete tail;
        tail = newNode;

        listSize--;
        cout<<"Usunieto element"<<endl;
    }
    else if (index > 0 && index < listSize) // usuwanie ze srodka
    {
       /* Node* temp = head;

            for(int i=0; i<index; i++)
            {
                temp = temp->nextNode;
            }*/
            Node* temp;

            if (index <= listSize/2) // dla pierwszej polowy wezlow pomocniczy wskaznik porusza sie od glowy
            {

            temp = head;
            cout<<"Ruszam sie od glowy"<<endl;
            for(int i=0; i<index; i++)
            {
                temp = temp->nextNode;
            }
            }
            if (index > listSize/2) // dla drugiej polowy wezlow pomocniczy wskaznik porusza sie od ogona
            {

            temp = tail;
            cout<<"Ruszam sie od ogona"<<endl;
            for(int i=(listSize-1); i>index; i--)
            {
                temp = temp->prevNode;
            }
            }

            newNode = temp->nextNode;
            newNode->prevNode = temp->prevNode;
            newNode = temp->prevNode;
            newNode->nextNode= temp->nextNode;
            temp->nextNode = nullptr;
            temp->prevNode = nullptr;

            delete temp;

            listSize--;
            cout<<"Usunieto element"<<endl;
    }


   printList();
   cout<<"listSize: "<<listSize<<endl;
}

void ListImplementation::addToList(int index, int value)
{


    if(listSize == 0) // dodawanie pierwszego elementu
    {
        cout<<"Dodawanie pierwszego elementu"<<endl;
        newNode = new Node;
        newNode->data = value;
        newNode->nextNode = nullptr;
        newNode->prevNode = nullptr;
        head = newNode;
        tail = newNode;

    }
    else if (listSize > 0) //dodawanie kolejnych elementow
    {
        if (index < 0 || index > listSize) cout<<"Nie mozna dodac elementu. Nieprawidlowy numer indeksu"<<endl;

        if (index == 0) //dodawanie elementu na poczatek
        {
            cout<<"Dodawanie na poczatek"<<endl;
            newNode = new Node;
            newNode->data = value;
            newNode->nextNode = head;
            newNode->prevNode = nullptr;
            head->prevNode = newNode;
            head = newNode;

        }

        if (index == listSize) //dodawanie elementu na koniec
        {
            cout<<"Dodawanie na koniec"<<endl;
            newNode = new Node;
            newNode->data = value;
            newNode->nextNode = nullptr;
            newNode->prevNode = tail;
            tail->nextNode = newNode;
            tail = newNode;

        }

        if (index > 0 && index < listSize)
        {
            cout<<"Dodawanie do srodka"<<endl;
            newNode = new Node; //dodawanie elementu do srodka listy
            newNode->data = value;
            Node* temp;

            if (index <= listSize/2) // dla pierwszej polowy wezlow pomocniczy wskaznik porusza sie od glowy
            {

            temp = head;
            cout<<"Ruszam sie od glowy"<<endl;
            for(int i=0; i<index; i++)
            {
                temp = temp->nextNode;
            }
            }
            if (index > listSize/2) // dla drugiej polowy wezlow pomocniczy wskaznik porusza sie od ogona
            {

            temp = tail;
            cout<<"Ruszam sie od ogona"<<endl;
            for(int i=(listSize-1); i>index; i--)
            {
                temp = temp->prevNode;
            }
            }

            newNode->nextNode = temp; //gimnastyka wskaznikow
            newNode->prevNode = temp->prevNode;
            temp->prevNode = newNode;

            temp = newNode->prevNode;
            temp->nextNode = newNode;

            temp = nullptr;
            delete temp;

            printList();

        }


    }
    else cout<<"Wystapil blad przy dodawaniu elementu"<<endl;

    listSize++;
    cout<<"listSize: "<<listSize<<endl;
}


void ListImplementation::printList()
{
    if (listSize <= 0) cout<<"Brak elementow do wyswietlenia"<<endl;
    else
    {
    Node* temp = head;
    cout<<"Elementy w liscie:"<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->nextNode;

    }
    cout<<endl;
    }
}

void ListImplementation::printListBackwards()
{
    if (listSize <= 0) cout<<"Brak elementow do wyswietlenia"<<endl;
    else
    {
    Node* temp = tail; //pomocniczy wskaznik
    cout<<"Elementy w liscie od tylu:"<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->prevNode;

    }
    cout<<endl;
    }
}

void ListImplementation::clearList()
{
    while (listSize != 0)
    {
        removeFromList(0);
    }
}

//szukanie elementu na podstawie wartosci. Wyswietla indeks
void ListImplementation::searchList(int value)
{
    newNode = head;
    for (int i=0; i<listSize; i++)
    {
        if(newNode->data==value)
        {
            cout<<"Znaleziono wartosc na indeksie: "<<(i)<<endl;
            return;
        }
        newNode = newNode->nextNode;
    }
    cout<<"Nie ma takiej wartosci w tablicy"<<endl;
}

