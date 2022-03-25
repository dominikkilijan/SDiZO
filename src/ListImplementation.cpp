#include <iostream>
#include "ListImplementation.h"

using namespace std;


ListImplementation::ListImplementation()
{
    listSize = 0;
}

ListImplementation::~ListImplementation()
{
    //dtor
}

void ListImplementation::addToList(int index, int value)
{


    if(listSize == 0) //dodawanie pierwszego elementu
    {
        cout<<"Dodawanie pierwszego elementu"<<endl;
        newNode = new Node;
        newNode->data = value;
        newNode->nextNode = nullptr;
        newNode->prevNode = nullptr;
        head = newNode;
        tail = newNode;

    }
    else if (listSize > 0)
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

            Node* temp = head; //pomocniczy wskaznik

            for(int i=0; i<index; i++)
            {
                temp = temp->nextNode;
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
}

void ListImplementation::printList()
{
    if (listSize <= 0) cout<<"Brak elementow do wyswietlenia"<<endl;
    else
    {
    Node* temp = head; //pomocniczy wskaznik
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
