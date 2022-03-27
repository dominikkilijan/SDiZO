#ifndef DYNAMICARRAYIMPLEMENTATION_H
#define DYNAMICARRAYIMPLEMENTATION_H


class DynamicArrayImplementation
{
    public:
        DynamicArrayImplementation(int);
        virtual ~DynamicArrayImplementation();

        int *dArray;
        int arraySize;
        int arrayCapacity;
        int maxPrintSize;
        int notInitialization;

        long long int frequency;
        long long int start;
        long long int elapsed;

        void checkIfResize();
        void addToDyArr(int, int, int);
        void printDyArray();
        void checkIfDownsize();
        void removeFromDyArray(int);
        void arraySearch(int);
        long long int read_QPC();


    protected:

    private:
};

#endif // DYNAMICARRAYIMPLEMENTATION_H
