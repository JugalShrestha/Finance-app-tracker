#include<stdio.h>
void lineBreak();
void displayData(){
    FILE *mainFile;
    char str;
    mainFile= fopen("addDataDatabase.txt","r");
    char stoper[20]="Total";
    float balance= 400000;
    lineBreak();
    printf("TOTAL BALANCE: \t\t%.2f",balance);
    lineBreak();
    printf("DISPLAYING THE EXPENSES ");
    lineBreak();
    do{
        str= fgetc(mainFile);
        printf("%c",str);
    }
    while(str!=EOF);
    fclose(mainFile);
    printf("\n");
}