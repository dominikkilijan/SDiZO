#ifndef HEAPIMPLENETATION_H
#define HEAPIMPLENETATION_H


class HeapImplenetation
{
    public:
        HeapImplenetation(int);
        virtual ~HeapImplenetation();

        int *length;
        int lengthSize;
        int heapSize;
        int maxPrintSize;

        long long int frequency;
        long long int start;
        long long int elapsed;


        int leftChild(int);
        int rightChild(int);
        int parent(int);
        void heapify(int);
        void heapSearch(int);
        void printHeap1();
        void addToHeap(int);
        void removeHeapRoot();
        void buildHeap();

        long long int read_QPC();

    protected:

    private:
};

#endif // HEAPIMPLENETATION_H
