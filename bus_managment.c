#include<stdio.h>
#include<string.h>
int busnumber[5]={201,202,203,204,205};
char sources[5][50]={"kolkata","jaipur","ajmer","dehli","jodhpur"};
char destination[5][50]={"byawar","sikar","ahemdabaad","puna","agra"};
int totalseat[5]={5,10,15,20,25};
int availableseat[5]={5,10,15,20,25};
int fare[5]={500,200,250,450,650};

int totalbus=5;
char fixusername[]="ikra";
char fixpassword[]="ikra12345";

char name[50];
char password[50];
int bus,seat_book,seat_cancle,bus_num;
int mainoption,useroption;

int login();
int book_ticket();
int cancle_ticket();
int check_status();

int main()
{
    printf("**************BUS RESERVATION SYATEM******************\n");
    printf("1.login\n");
    printf("2.Exit\n");
    printf("please enter your option:");
    scanf("%d",&mainoption);
    switch(mainoption)
    {
        case 1:
        if(1==login())
        {
            do
            {
                printf("\n==user menu==\n");
                printf("1.book a ticket\n");
                printf("2.cancle a ticket\n");
                printf("3.check status\n");
                printf("4.logout\n");
                printf("enter your option");
                scanf("%d",&useroption);
                switch(useroption)
                {
                    case 1:
                        book_ticket();
                        break;
                    case 2:
                        cancle_ticket();
                        break;
                    case 3:
                        check_status();
                        break;
                    case 4:
                        printf("logout successfully\n");
                        break;
                    default:
                        printf("invalid option tryagain\n");
                }
            } while(useroption!=4);
        }
            else
            {
                printf("login failled ! incorrect name password\n");
            }
            break;
            case 2:
            {
                printf("thank you for using the syatem\n");
                break;
                default:
                printf("invalid mainoption !\n");
            return 0;
        }
    
        
    }
    return 0;
}
int login()
{
    printf("\n please enter name:");
    scanf("%s",name);
    printf("\n please enter password:");
    scanf("%s",password);
    if(strcmp(name,fixusername)==0 && strcmp(password,fixpassword)==0)
    {
        printf("LOGIN SUCCESSFULL WELCOME,%s!\n",name);
        return 1;
    }
    return 0;
}
int book_ticket()
{
    int count=0;
    printf("\n enter bus number:");
    scanf("%d",&bus_num);
    printf("enter number of seat:");
    scanf("%d",&seat_book);
    for(int i=0;i<totalbus;i++)
    {
        if(busnumber[i]==bus_num)
        {
            count=1;
            if(availableseat[i]>=seat_book)
            {
                availableseat[i]=availableseat[i]-seat_book;
                printf("\n booking successful!%d seat on bus %d\n",seat_book,bus_num);
            }
            else
            {
                printf("\n sorry only %d seat are available\n available seat[i]");
            }
            break;
        }
    }
        if(count==0)
        {
            printf("bus not found ! \n");
        }
      return 0;  
}
int cancle_ticket()
{
    int count=0;
    printf("\n enter bus_num:");
    scanf("%d",&bus_num);
    printf("enter number of seat to cancle:");
    scanf("%d",&seat_cancle);
    for(int i=0;i<totalbus;i++)
    {
        if(busnumber[i]==bus_num)
        {
            count=1;
            if(availableseat[i]+seat_cancle<=totalseat[i])
            {
                availableseat[i]=availableseat[i]+seat_cancle;
                printf("\n cancellation successful !%d seat to cancled on busnumber%d\n",seat_cancle,busnumber);
            }
            else{
                printf("\n invalid cancalled amount\n");
            }
            break;
        }
    }
    if(count=0)
    {
        printf("bus unavailable\n");
    }
    return 0;
}
int check_status()
{
    int found=0;
    printf("\n please enter busnumber:");
    scanf("%d",&bus_num);
    for(int i=0;i<totalbus;i++)
    {
        if(busnumber[i]==bus_num)
        {
            found=1;
            printf("\nbusnumbere:       %d\n",busnumber[i]);
            printf("source city:        %s\n",sources[i]);
            printf("destination city:   %s\n",destination[i]);
            printf("totalseat:          %d\n",totalseat[i]);
            printf("availableseat:      %d\n",availableseat[i]);
            printf("fare                %d\n",fare[i]);
            break;
        }
    }
        if(found==0)
        {
            printf("bus unavailable\n");
        }
      return 0;  
}




