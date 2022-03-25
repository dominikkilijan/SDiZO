#ifndef LISTIMPLEMENTATION_H
#define LISTIMPLEMENTATION_H

using namespace std;


class ListImplementation
{
    public:
        ListImplementation();
        virtual ~ListImplementation();

        struct Node
        {
            int data;
            Node* prevNode;
            Node* nextNode;
        };


        Node* head;
        Node* tail;
        Node* newNode;

        int listSize;


        void addToList(int, int);
        void printList();
        void printListBackwards();
        void removeFromList(int);
        void clearList();


    protected:

    private:

};

#endif // LISTIMPLEMENTATION_H
