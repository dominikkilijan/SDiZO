#ifndef LISTMENU_H
#define LISTMENU_H

#include <fstream>

class ListMenu
{
    public:
        ListMenu(int);
        virtual ~ListMenu();

        int listChoice;
        int listWork;
        int initChoice;
        int initOption;
        int numberOfElements;

        int *fileListArray;
        int fileSize;


        void getFileInfo();
};

#endif // LISTMENU_H
