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
        newNode = new Node;
        newNode->data = value;
        newNode->nextNode = nullptr;
        newNode->prevNode = nullptr;
        head = newNode;
        tail = newNode;

        listSize++;
    }
    else if (listSize > 0)
    {
        if (index < 0 || index > listSize) cout<<"Nie mozna dodac elementu. Nieprawidlowy numer indeksu"<<endl;

        if (index == 0) //dodawanie elementu na poczatek
        {
            newNode = new Node;
            newNode->data = value;
            newNode->nextNode = head;
            newNode->prevNode = nullptr;
            head->prevNode = newNode;
            head = newNode;

            listSize++;
        }
        if (index == listSize) //dodawanie elementu na koniec
        {
            newNode = new Node;
            newNode->data = value;
            newNode->nextNode = nullptr;
            newNode->prevNode = tail;
            tail->nextNode = newNode;
            tail = newNode;

            listSize++;
        }
        else
        {
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


            listSize++;
            temp->nextNode = nullptr; //usuwanie z pamieci pomocniczego wskaznika
            temp->prevNode = nullptr;
            delete temp;
        }


    }
    else cout<<"Wystapil blad przy dodawaniu elementu"<<endl;
}

void ListImplementation::printList()
{
    if (listSize <= 0) cout<<"Brak elementow do wyswietlenia"<<endl;
    else
    {
    Node* temp = head; //pomocniczy wskaznik

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->nextNode;

    }
    cout<<endl;
    }
}

