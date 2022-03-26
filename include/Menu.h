#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<fstream>

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        int choice;
        int work;
        int *fileArray;
        int fileSize;
        fstream file;

        void getFileInfo();


};

#endif // MENU_H
