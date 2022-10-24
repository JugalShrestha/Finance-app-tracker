#include<stdio.h>
#include<string.h>
#include"decoration.h"
#include"selectionForMenu.h"
#include"records.h"
int main()
{
    //Menu System:
    char exitInput[2]="0";
    char option[2];
    do{
        system("cls");
        lineBreak();
        printf("\t\tMENU");
        lineBreak();
        printf("\n1. Display Total Expenses");
        printf("\n2. Add Records");
        printf("\n3. Update a Record");
        printf("\n4. Search a Record");
        printf("\n5. Delete a Record");
        printf("\n0. Exit");
        lineBreak();
        printf("\nEnter your choice (0-5):\t");
        scanf("%s",option);
        choiceForMenu(option);
        system("cls");
    }
    while(strcmp(option,exitInput)!=0);
    return 0;
}


