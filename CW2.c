#include<stdio.h>
#include<conio.h>
char dt;//driving type
int t=1,tr,ta;
float allt=0,fulltc=0;

void Display()
{
    printf("\t\t\t\t\t\t !*******Bus Management System*******!\n");
}
void input()

{
    printf("Driving Types\n");
    printf("Driving Types a= Normal root\n");
    printf("Driving Types b= Trips\n");
    printf("\nIf you want stop any place press (0)\n\n\n");


    printf("Enter What is your Driving Type(\"a\"or \"b\") : ");
    scanf(" %c",&dt);

    while(dt!='a'& dt!='b')
    {
        printf("Your type is invalid !\n");
        printf("Enter your type Again : ");
        scanf(" %c",&dt);
    }

}
void typeseen()
{
  switch(dt)
    {
        case 'a':
            printf("\n\n\t\t<<<*** NORMAL ROOT SERVICE ***>>>");
            printf("\n\n*** For 3 terms or more than 3 , LKR:500 Will add to conductor and Driver ***");break;

        case 'b':
            printf("\n\n\t\t<<*** SPECIAL TRIP SERVICE ***>>");
            printf("\n\n***For One day trip add 20%% from rest income For Driver and Conductor***");
            printf("\n***For more than 2 days trip add 30%% from rest income For Driver and Conductor***");
            printf("\n***For more than 4 days trip add 40%% from rest income For Driver and Conductor***");break;
    }
}


void dailyincome()
{   int ti,tc,t=1;// t=driving type   ti= incomes of terms    tc=time table controller costs   tr= cost of repair the bus ta=additional Cost
    float gt,ft;
    //int total=0;

    while(ti!=0)
    {


    if(dt=='a')
    {
          printf("\n\nEnter your term %d Income(LKR) : ",t);
          scanf("%d",&ti);
    while(ti<0)
    {
          printf("\nInvalid Data! Enter Again");
          printf("\n\nEnter your term %d Income(LKR) : ",t);
          scanf("%d",&ti);

    }
          printf("Enter Time Keeper's cost(LKR) : ");
          scanf("%d",&tc);
     while(tc<0)
    {
          printf("\nInvalid Data! Enter Again");
          printf("\n\nEnter Time Keeper's cost(LKR) : ",t);
          scanf("%d",&tc);
    }

          allt=allt+ti;
          fulltc=fulltc+tc;
          t++;

    }

    if(ti==0)
    {
        printf("\n\n\tYes! now finished the terms!!!");
        printf("\n\n---------------------------------------------");
    }

    }


    gt=0; t=1;
        printf("\n\nEnter Bus Repair cost(LKR) : ");
        scanf("%d",&tr);
    while(tr<0)
    {
        printf("Invalid Cost amount! Try Again!");
        printf("\nEnter Bus Repair cost(LKR) : ");
        scanf("%d",&tr);

    }
        printf("\nEnter Additional cost for Driver & Conductor(LKR) : ");
        scanf("%d",&ta);
    while(ta<0)
    {
        printf("Invalid Cost amount! Try Again!");
        printf("\nEnter Additional cost for Driver & Conductor(LKR) : ");
        scanf("%d",&ta);

    }


        printf("\n\n------***---***---***---***---***---***------");
        printf("\n\nTotal income of the all Terms   (LKR) is %.2f",allt);
        printf("\n\nTotal paid cost for time keepers(LKR) is %.2f",fulltc);

    if(t<4)
    {
        gt=ta+((allt-(tr+fulltc))*20/100);
        printf("\n\nThe final outcome for Driver & Conductor is LKR %.2f",gt);
    }
    else
    {
        gt=ta+((allt-(tr+fulltc))*20/100)+500;
        printf("\n\nThe final outcome for Driver & Conductor is LKR %.2f",gt);
    }

        ft=allt-gt;
        printf("\n\nFinal Profit is LKR %.2f\n\n",ft);
     if(gt<=0)
    {
        printf("\n\n\t***.....SORRY.....***");
        printf("\n!!!These result of final outcome & final profit answers are false !!!!");
        printf("\n!!!Today you haven't any profit from this root!!!!");
    }
        printf("\n\n\n\t!*****<<< BETTER TOMMORROW THAN TODAY! >>>*****!\n");

}

void tripincome()
{   int tripcost,nday,rbus;
    float m1,m2;
    m1=0;
    m2=0;

    //m1=cost for driver conductor
    if(dt=='b')
    {
        printf("\n\nEnter your Total Cost for Trip(LKR) : ");
        scanf("%d",&tripcost);
        while(tripcost<0)
        {
            printf("Invalid Trip Cost ! Enter Again!");
            printf("\n\nEnter your Total Cost for Trip(LKR) : ");
            scanf("%d",&tripcost);
        }
        printf("\n\nEnter the No of Days for the Trip : ");
        scanf("%d",&nday);
          while(nday<0)
        {
            printf("Invalid No of Days ! Enter Again!");
            printf("\n\nEnter the No of Days for the Trip : ");
            scanf("%d",&nday);
        }




        printf("\n\nThe Cost for Repair the Bus(LKR) : ");
        scanf("%d",&rbus);
          while(rbus<0)
        {
            printf("Invalid Repair cost ! Enter Again!");
            printf("\n\nEnter the cost of Repair the bus(LKR) : ");
            scanf("%d",&rbus);
        }
         printf("\nEnter Additional cost for Driver & Conductor(LKR) : ");
         scanf("%d",&ta);
      while(ta<0)
    {
        printf("Invalid Cost amount! Try Again!");
        printf("\nEnter Additional cost for Driver & Conductor(LKR) : ");
        scanf("%d",&ta);

    }

     if(nday>=4)
    {
        m1=ta+(tripcost-rbus)*40/100;
    }
    else if(nday>=2)
    {
        m1=ta+(tripcost-rbus)*30/100;
    }else
    {
        m1=ta+(tripcost-rbus)*20/100;
    }
    printf("\n\n------***---***---***---***---***---***------");

    printf("\n\nTotal Profit for Driver & Conductor is LKR %.2f",m1);

    m2=tripcost-m1;
    printf("\n\nTotal Profit for Bus Owner is LKR %.2f ",m2);
     if(m1<0)
    {
        printf("\n\n\t***.....SORRY.....***");
        printf("\n!!!These result of Total Profit for Driver , Conductor & Bus Owner answers are false !!!!");
        printf("\n!!! You haven't any profit from this trip!!!!");
    }
        printf("\n\n\n\t!*****<<< BETTER TOMMORROW THAN TODAY! >>>*****!\n");
    }


}

int main()
{
    Display();
    input();
    typeseen();
    tripincome();
    dailyincome();
    getch();
    return 0;
}
