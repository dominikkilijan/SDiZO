#ifndef DYNAMICARRAYMENU_H
#define DYNAMICARRAYMENU_H

#include <fstream>


class DynamicArrayMenu
{
    public:
        DynamicArrayMenu(int);
        virtual ~DynamicArrayMenu();

        int arraychoice;
        int arrayWork;
        int initialCap;
        int numberOfElements;
        int initOption;

        int *fileArray;
        int fileSize;


        void getFileInfo();

    protected:

    private:
};

#endif // DYNAMICARRAYMENU_H
