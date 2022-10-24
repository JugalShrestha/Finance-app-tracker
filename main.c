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
        sectionBreak();
        printf("\t\t\t\tMENU");
        sectionBreak();
        printf("\n\t1. Display Total Expenses");
        printf("\n\t2. Add a Record");
        printf("\n\t3. Update a Record");
        printf("\n\t4. Search a Record");
        printf("\n\t5. Delete a Record");
        printf("\n\t0. Exit");
        sectionBreak();
        printf("\n\tEnter your choice (0-5):\t");
        scanf("%s",option);
        sectionBreak();
        choiceForMenu(option);
        system("cls");
    }
    while(strcmp(option,exitInput)!=0);
    return 0;
}


