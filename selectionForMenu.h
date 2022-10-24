#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void choiceForMenu(char opt[2])
{
    //options from the menu section
    char opt1[2]= "1",opt2[2]="2",opt3[2]="3",opt4[2]="4",opt5[2]="5",opt0[2]="0";
    void addData();
    void displayData();
    void updateData();
    void searchData();
    //DISPLAY DATA
    if(strcmp(opt,opt1)==0)
    {
        system("cls");
        displayData();
        printf("\n\t");
        system("pause");
    }
    //ADD DATA
    else if(strcmp(opt,opt2)==0)
    {
        system("cls");
        addData();
        printf("\n\t");
        system("pause");
    }
    //UPDATE DATA
    else if(strcmp(opt,opt3)==0)
    {
        system("cls");
        updateData();
        printf("\n\t");
        system("pause");
    }
    //SEARCH DATA
    else if(strcmp(opt,opt4)==0)
    {
        system("cls");
        searchData();
        printf("\n\t");
        system("pause");
    }
    //DELETE DATA
    else if(strcmp(opt,opt5)==0)
    {
        printf("\ndelete data section");
        //deleteData();
    }
    //EXIT
    else if(strcmp(opt,opt0)==0)
    {
        exit(0);
    }
    //WRONG INPUT
    else{
        printf("\tWrong Input (0-5)\n\t");
        system("pause");
    }
}