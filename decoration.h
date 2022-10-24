#include<stdio.h>
void lineBreak(){
    printf("\n");
    char sign='-';
    int count;
    int maxBreak=50;
    printf("\t");
    for(count=0;count<maxBreak;count++)
    {
        printf("%c",sign);
    }
    printf("\n");
}
void sectionBreak(){
    printf("\n");
    char sign='=';
    int count;
    int maxBreak=50;
    printf("\t");
    for(count=0;count<maxBreak;count++)
    {
        printf("%c",sign);
    }
    printf("\n");
}
