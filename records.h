#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for product
struct productData{
    char productName[20];
    float productPrice;
};

//Structure for tracking months
struct database{
    char year[5],day[3];
    char month[20];
    char date[30];
    float totalPrice;
    int maxProduct;
    float balance;
    struct productData pData[50];
};
void lineBreak();

//Adding data
void addData(){
    int count;
    int maxCount;
    int one=1;
    struct database data;
    //Getting date
    lineBreak();
    printf("Enter the year(2022,etc): ");
    scanf("%s",data.year);
    printf("Enter the month(Aug,etc): ");
    scanf("%s",data.month);
    printf("Enter the day(11,etc): ");
    scanf("%s",data.day);
    lineBreak();
    //Date maker
    strupr(data.month);
    strcpy(data.date,data.year);
    strcat(data.date,"/");
    strcat(data.date,data.month);
    strcat(data.date,"/");
    strcat(data.date,data.day);
    //printf("%s",data.date);
    printf("Enter the estimated no. of products(2,etc): ");
    scanf("%d",&data.maxProduct);
    lineBreak();
    data.totalPrice=0;
    for(count=0;count<data.maxProduct;count++)
    {
        printf("Enter the name of product no. %d : ",count+1);
        fflush(stdin);
        scanf("%[^\n]",data.pData[count].productName);
        fflush(stdin);
        printf("Enter the price for %s : ",data.pData[count].productName);
        scanf("%f",&data.pData[count].productPrice);
        fflush(stdin);
        data.totalPrice+=data.pData[count].productPrice;
        lineBreak();
    }
    //printf("Total price: %.2f",data.totalPrice);
    //Saving the records
    FILE *mainFile;
    mainFile= fopen("database.txt","a+");
    fwrite(&data,sizeof(struct database),1,mainFile);
    fclose(mainFile);
}

//Displaying the Records
void displayData(){
    FILE *mainFile;
    mainFile= fopen("database.txt","r");
	struct database data;
    int count=0;
    float total=0;
    data.balance= 400000;
    lineBreak();
    printf("\n\tDISPLAYING TOTAL EXPENSES");
    lineBreak();
    while(fread(&data,sizeof(struct database),1,mainFile))
    {
        lineBreak();
        printf("DATE: \t%s",data.date);
        lineBreak();
        printf("TOTAL: \tRs. %.2f",data.totalPrice);
        lineBreak();
        data.balance-=data.totalPrice;
        total+=data.totalPrice;
    }
    printf("\n\n");
    lineBreak();
    printf("TOTAL EXPENSE: \tRs. %.2f",total);
    lineBreak();
    printf("BALANCE: \tRs. %.2f",data.balance);
    lineBreak();
    fclose(mainFile);
}