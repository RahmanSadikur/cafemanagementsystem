#include <stdio.h>
#include <conio.h>
#include <string.h>

void write();
void display(char da[]);


int main()
{   int option;
    char y[20];

    printf("\t*******SHOP MANAGEMENT SYSTEM********\n");
    printf("\npress -1 to enter data\n");
    printf("\npress -2 to read data on specific date\n");
    printf("\npress -0 to exit\n");
    scanf("%d",&option);
    do{
        switch(option)
    {
        case 1:write();
        break;
        case 2:printf("Enter the specific date which's data you want\n");
            scanf("%s",&y[20]);

             display(y);
            break;
            case 0:exit(0);
        default:printf("you had entered wrong keyword");

    }

    }
    while(option==0);
    return 0;
}
void write()
{

    FILE *x;
    x=fopen("data.rec","a");
    char dat[20];
    char cnam[49];
    char pnam[49];
    char cpnum[15];
    double cost;
    printf("\nenter the date ::");
    scanf("%s",dat);

    printf("\nEnter the customer name ::");
    scanf("%s",&cnam);

    printf("\nenter customer phone number ::");
    scanf("%s",&cpnum);

    printf("\nenter  product you want to buy ::");
    scanf("%s",&pnam);
    printf("\nenter  product cost ::");
    scanf("%d",&cost);


    fprintf(x,"\n%s%s%s%s%d\n",dat,cnam,cpnum,pnam,cost);
    printf("\n>>> Record saved successfully ....");

    fclose(x);

}
void display(char da[])
{
    char dat[20];
    char cnam[49];
    char pnam[49];
    char cpnum[15];
    double cost;
    FILE *x;
    int r;
    x=fopen("data.rec","r");
    while(fscanf(x,"%s%s%s%s%d",&dat,&cnam,&cpnum,&pnam,&cost)!=EOF)
    {
        r=strcmp(dat,da);
        if(r==0)
        {
            printf("\n customer name:%s",cnam);
            printf("\n customer phone number:%s",cpnum);
            printf("\n product name:%s",pnam);
            printf("\n product cost:%d",cost);
        }
    }
   fclose(x);

}


