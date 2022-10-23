#include<stdio.h>
#include<stdlib.h>
struct time {
    int year,day;
    char month[20];
    float totalPrice;
};
struct productData{
    char productName[20];
    float price;
};
void lineBreak();
void addData(){
    //Header part
    lineBreak();
    printf("ADDING RECORDS SECTION");
    lineBreak();

    //User input
    int noOfProduct;
    struct time data;
    printf("Enter the year: ");
    scanf("%d",&data.year);
    printf("Enter the month:");
    scanf("%s",data.month);
    printf("Enter the day:");
    scanf("%d",&data.day);
    printf("Enter the No. of Products (Estimated No.): ");
    scanf("%d",&noOfProduct);
    struct productData data2[noOfProduct];
    int count=0;
    data.totalPrice=0;
    for(count=0;count<noOfProduct;count++)
    {
        printf("Enter the name of No. %d product: ",count+1);
        fflush(stdin);
        scanf("%[^\n]",data2[count].productName);
        fflush(stdin);
        printf("Enter the price for %s : Rs. ",data2[count].productName);
        fflush(stdin);
        scanf("%f",&data2[count].price);
        fflush(stdin);
        data.totalPrice=data2[count].price+ data.totalPrice;
    }
    //Putting in File:
    FILE *mainFile;
    mainFile= fopen("addDataDatabase.txt","a+");
    char sign='=';
    int maxCount=40;
    //Decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }
    //Date
    fprintf(mainFile,"\nDate: %4d,%c%c%c,%2d\n",data.year,data.month[0],data.month[1],data.month[2],data.day);
    char p1[8]="Product",p2[6]="Price";
    //For decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }
    //Contents
    fprintf(mainFile,"\n%-20s\t%s\n",p1,p2);
    //Decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }
    //Product name and price Recording in file
    for(count=0;count<noOfProduct;count++)
    {
        fprintf(mainFile,"\n%-20s\t%.2f\n",data2[count].productName,data2[count].price);
    }
    //Decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }
    //Total Price
    char t[6]="total";
    fprintf(mainFile,"\n%-20s\t%.2f\n",t,data.totalPrice);
      //Decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }
    fprintf(mainFile,"\n\n");

    fclose(mainFile);
}