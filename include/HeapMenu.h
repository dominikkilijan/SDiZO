#ifndef HEAPMENU_H
#define HEAPMENU_H

#include <HeapMenu.h>
#include <fstream>


class HeapMenu
{
    public:
        HeapMenu(int);
        virtual ~HeapMenu();

        int heapChoice;
        int heapWork=1;
        int numberOfElements;
        int initOption;

        int *fileArray;
        int fileSize;


        void getFileInfo();


    protected:

    private:
};

#endif // HEAPMENU_H
