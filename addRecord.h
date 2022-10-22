#include<stdio.h>
#include<stdlib.h>
struct database {
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
    int year,month,day,noOfProduct;
    printf("Enter the year: ");
    scanf("%d",&year);
    printf("Enter the month:");
    scanf("%d",&month);
    printf("Enter the day:");
    scanf("%d",&day);
    printf("Enter the amount of Products (Estimated NO.): ");
    scanf("%d",&noOfProduct);
    struct database data[noOfProduct];
    int count;
    float totalPrice;
    for(count=0;count<noOfProduct;count++)
    {
        printf("Enter the name of No. %d product: ",count+1);
        fflush(stdin);
        scanf("%s",data[count].productName);
        fflush(stdin);
        printf("Enter the price for %s : Rs. ",data[count].productName);
        fflush(stdin);
        scanf("%f",&data[count].price);
        fflush(stdin);
        totalPrice= data[count].price+ totalPrice;
    }

    //Putting in File:
    FILE *mainFile;
    mainFile= fopen("addDataDatabase.txt","w");
    char sign='=';
    int maxCount=40;
    //Decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }
    //Date
    fprintf(mainFile,"\nDate: %4d,%2d,%2d\n",year,month,day);
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
        fprintf(mainFile,"\n%-20s\t%.2f\n",data[count].productName,data[count].price);
    }
    //Decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }
    //Total Price
    char t[6]="total";
    fprintf(mainFile,"\n%-20s\t%.2f\n",t,totalPrice);
      //Decoration
    for(count=0;count<=maxCount;count++)
    {
        fprintf(mainFile,"%c",sign);
    }

    fclose(mainFile);
}