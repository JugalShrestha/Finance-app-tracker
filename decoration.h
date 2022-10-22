#include<stdio.h>
void lineBreak(){
    printf("\n");
    char sign='=';
    int count;
    int maxBreak=40;
    for(count=0;count<maxBreak;count++)
    {
        printf("%c",sign);
    }
    printf("\n");
}
