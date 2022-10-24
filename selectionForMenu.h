#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void choiceForMenu(char opt[2])
{
    //options from the menu section
    char opt1[2]= "1",opt2[2]="2",opt3[2]="3",opt4[2]="4",opt5[2]="5",opt0[2]="0";
    void addData();
    void displayData();
    if(strcmp(opt,opt1)==0)
    {
        system("cls");
        displayData();
        printf("\n");
        system("pause");
    }
    else if(strcmp(opt,opt2)==0)
    {
        system("cls");
        addData();
        printf("\n");
        system("pause");
    }
    else if(strcmp(opt,opt3)==0)
    {
        printf("\nupdate data section");
        //updateData();
    }
    else if(strcmp(opt,opt4)==0)
    {
        printf("\nsearch data section");
        //searchData();
    }
    else if(strcmp(opt,opt5)==0)
    {
        printf("\ndelete data section");
        //deleteData();
    }
    else if(strcmp(opt,opt0)==0)
    {
        exit(0);
    }
    else{
        printf("\nWrong Input (0-5)\n");
        system("pause");
    }
}