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
        int maxPrintSize;

        long long int frequency;
        long long int start;
        long long int elapsed;


        void addToList(int, int);
        void printList();
        void printListBackwards();
        void removeFromList(int);
        void clearList();
        void searchList(int);
        long long int read_QPC();


    protected:

    private:

};

#endif // LISTIMPLEMENTATION_H
