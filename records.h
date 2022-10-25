#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define balance 400000
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
    int maxProduct2;
    struct productData pData[50];
};
void lineBreak();
void sectionBreak();

//Adding data
void addData(){
    int count;
    int maxCount;
    struct database data;
    //Showing Today's date
    sectionBreak();
    printf("\tTodays date: \t%s",__DATE__);
    //Getting date
    sectionBreak();
    printf("\tEnter the year(2022,etc): ");
    scanf("%s",data.year);
    printf("\tEnter the month(August,etc): ");
    scanf("%s",data.month);
    printf("\tEnter the day(11,etc): ");
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
    printf("\tEnter the estimated no. of products(2,etc): ");
    scanf("%d",&data.maxProduct);
    lineBreak();
    data.totalPrice=0;
    for(count=0;count<data.maxProduct;count++)
    {
        printf("\tEnter the name of product no. %d : ",count+1);
        fflush(stdin);
        scanf("%[^\n]",data.pData[count].productName);
        fflush(stdin);
        printf("\tEnter the price for %s : Rs. ",data.pData[count].productName);
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
    sectionBreak();
    printf("\t\tDISPLAYING TOTAL EXPENSES");
    sectionBreak();
    while(fread(&data,sizeof(struct database),1,mainFile))
    {
        lineBreak();
        char d[6]="DATE:";
        printf("\t%s \t%s",d,data.date);
        lineBreak();
        char t[7]="TOTAL:";
        printf("\t%-25s \tRs. %.2f",t,data.totalPrice);
        lineBreak();
        total+=data.totalPrice;
    }
    printf("\n\n");
    sectionBreak();
    printf("\tTotal Expense (%s): \tRs. %.2f",__DATE__,total);
    lineBreak();
    char b[9]="BALANCE:";
    printf("\t%-25s\tRs. %.2f",b,balance-total);
    sectionBreak();
    fclose(mainFile);
}

//Updating A Record:
void updateData(){
    char toBeUpdate[20];
    char yearToUpdate[5],monthToUpdate[20],dayToUpdate[3];
    sectionBreak();
    printf("\t\t\tUPDATING FOR A DATE");
    sectionBreak();
    printf("\tTODAY'S DATE: %s",__DATE__);
    sectionBreak();
    lineBreak();
    printf("\tYear to be searched (2022,etc): ");
    scanf("%s",yearToUpdate);
    printf("\tMonth to be searched (August,etc): ");
    scanf("%s",monthToUpdate);
    printf("\tDay to be searched (11,etc): ");
    scanf("%s",dayToUpdate);
    //Date maker
    strupr(monthToUpdate);
    strcpy(toBeUpdate,yearToUpdate);
    strcat(toBeUpdate,"/");
    strcat(toBeUpdate,monthToUpdate);
    strcat(toBeUpdate,"/");
    strcat(toBeUpdate,dayToUpdate);
    //printf("\t%s",toBeUpdate);

    
    FILE *mainFile,*updateFile;
    int dataCounter=0;
    int counter=0;
    mainFile= fopen("database.txt","r");
    updateFile= fopen("updatedDatabase.txt","w");
    struct database data;
    while(fread(&data,sizeof(struct database),1,mainFile))
    {
        //After date is found menu
        if(strcmp(data.date,toBeUpdate)==0)
        {
            dataCounter=1;
            system("CLS");
            sectionBreak();
            printf("\tUPDATING FOR (%s)",toBeUpdate);
            sectionBreak();
            printf("\tPrevious Expense: \tRs. %.2f",data.totalPrice);
            sectionBreak();
            printf("\tAdd the Estimated No. of new products (2,etc): ");
            scanf("%d",&data.maxProduct2);
            lineBreak();
            for(counter=(data.maxProduct);counter<(data.maxProduct+data.maxProduct2);counter++)
            {        
                printf("\tEnter the name of product no. %d : ",counter+1);
                fflush(stdin);
                scanf("%[^\n]",data.pData[counter].productName);
                fflush(stdin);
                printf("\tEnter the price for %s : Rs.",data.pData[counter].productName);
                scanf("%f",&data.pData[counter].productPrice);
                fflush(stdin);
                data.totalPrice+=data.pData[counter].productPrice;
                lineBreak();
            }
            data.maxProduct=data.maxProduct2+data.maxProduct;
            printf("\n\tNew Expense: %.2f",data.totalPrice);
            lineBreak();
        }
        fwrite(&data,sizeof(struct database),1,updateFile);
    }
    fclose(mainFile);
    fclose(updateFile);

    if(dataCounter==1)
    {
        //For Updating the data
        mainFile=fopen("database.txt","w");
        updateFile=fopen("updatedDatabase.txt","r");
        while(fread(&data,sizeof(struct database),1,updateFile))
        {
            fwrite(&data,sizeof(struct database),1,mainFile);
        }
        fclose(mainFile);
        fclose(updateFile);
    }
    else{
        lineBreak();
        printf("\tRecord NOT Found!");
        lineBreak();
    }
}

//Searching a record
void searchData(){
    char toBeSearched[20];
    char yearToSearch[5],monthToSearch[20],dayToSearch[3];
    sectionBreak();
    printf("\t\t\tSEARCHING A DATE");
    sectionBreak();
    printf("\tTODAY'S DATE: %s",__DATE__);
    sectionBreak();
    lineBreak();
    printf("\tYear to be searched (2022,etc): ");
    scanf("%s",yearToSearch);
    printf("\tMonth to be searched (August,etc): ");
    scanf("%s",monthToSearch);
    printf("\tDay to be searched (11,etc): ");
    scanf("%s",dayToSearch);
    //Date maker
    strupr(monthToSearch);
    strcpy(toBeSearched,yearToSearch);
    strcat(toBeSearched,"/");
    strcat(toBeSearched,monthToSearch);
    strcat(toBeSearched,"/");
    strcat(toBeSearched,dayToSearch);
    //printf("\t%s",toBeSearched);

    FILE *mainFile;
    int dataCounter=0;
    int counter=0;
    mainFile= fopen("database.txt","r");
    struct database data;
    while(fread(&data,sizeof(struct database),1,mainFile))
    {
        //After date is found
        if(strcmp(data.date,toBeSearched)==0)
        {
            system("cls");
            dataCounter=1;
            sectionBreak();
            printf("\tDATE: \t%s",data.date);
            sectionBreak();
            for(counter=0;counter<data.maxProduct;counter++)
            {
                printf("\t%-25s \tRs. %.2f\n",data.pData[counter].productName,data.pData[counter].productPrice);
            }
            char t[7]="TOTAL:";
            lineBreak();
            printf("\t%-24s \tRs.%.2f",t,data.totalPrice);
            lineBreak();
        }
    }
    if(dataCounter!=1)
    {
        lineBreak();
        printf("\tRecord NOT Found!");
        lineBreak();
    }
    fclose(mainFile);
}

//Deleting the data
void deleteData(){
    char toBeDeleted[20];
    char yearToDelete[5],monthToDelete[20],dayToDelete[3];
    sectionBreak();
    printf("\t\t\tDELETING A RECORD");
    sectionBreak();
    printf("\tTODAY'S DATE: %s",__DATE__);
    sectionBreak();
    lineBreak();
    printf("\tYear to be deleted (2022,etc): ");
    scanf("%s",yearToDelete);
    printf("\tMonth to be deleted (August,etc): ");
    scanf("%s",monthToDelete);
    printf("\tDay to be deleted (11,etc): ");
    scanf("%s",dayToDelete);
    //Date maker
    strupr(monthToDelete);
    strcpy(toBeDeleted,yearToDelete);
    strcat(toBeDeleted,"/");
    strcat(toBeDeleted,monthToDelete);
    strcat(toBeDeleted,"/");
    strcat(toBeDeleted,dayToDelete);
    //printf("\t%s",toBeDeleted);

    //READING IN FILE
    FILE *mainFile,*deleteFile;
    int dataCounter=0;
    int counter=0;
    mainFile= fopen("database.txt","r");
    deleteFile= fopen("updatedDatabase.txt","w");
    struct database data;
    while(fread(&data,sizeof(struct database),1,mainFile))
    {
        //After date is found
        if(strcmp(data.date,toBeDeleted)==0)
        {
            dataCounter=1;
        }
        else
        fwrite(&data,sizeof(struct database),1,deleteFile);
    }
    fclose(mainFile);
    fclose(deleteFile);
    if(dataCounter==1)
    {
        mainFile= fopen("database.txt","w");
        deleteFile= fopen("updatedDatabase.txt","r");
        while(fread(&data,sizeof(struct database),1,deleteFile))
        {
            fwrite(&data,sizeof(struct database),1,mainFile);
        }
        fclose(mainFile);
        fclose(deleteFile);
        sectionBreak();
        printf("\tRecord Deleted!");
        sectionBreak();

    }
    else{
        lineBreak();
        printf("\tRecord NOT Found!");
        lineBreak();
    }
    
}