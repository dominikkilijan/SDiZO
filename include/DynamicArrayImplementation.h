#ifndef DYNAMICARRAYIMPLEMENTATION_H
#define DYNAMICARRAYIMPLEMENTATION_H


class DynamicArrayImplementation
{
    public:
        DynamicArrayImplementation(int, int);
        virtual ~DynamicArrayImplementation();

        int basicArray[8];
        int *dArray;
        int arraySize;
        int arrayCapacity;

        void checkIfResize();
        void addToDyArr(int, int);
        void printDyArray();
        void checkIfDownsize();
        void removeFromDyArray(int);


    protected:

    private:
};

#endif // DYNAMICARRAYIMPLEMENTATION_H
