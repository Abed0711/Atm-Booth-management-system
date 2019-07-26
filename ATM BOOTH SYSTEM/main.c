#include <stdio.h>              /// standard input output header...
#include <math.h>              /// defines various mathematical functions ...
#include <conio.h>            /// console input and output ...
#include<string.h>           /// string handling & various memory handling functions ...
#include <stdlib.h>         /// standard library header ...
#include <windows.h>       /// for all of the functions in the Windows API ...(Application programming interface)
#include<time.h>         /// for device time ...




FILE*fp,*fp1,*fpa; /// *fp- user.txt , *fp1 - temp.txt , fpa - admin.txt ...


char ui[100],up[100];       /// ui-user input , up - user password (database)...
char in_u[100],in_p[100];  /// in_u - scan user name & in_p - scan password from console for match ...
int ub,amt;               /// ub-user balance , amt - console input deposit/withdraw ...
int choice;              /// choice - for switch ...
char ch ;               /// 'Y' or 'N' ...
int count=0;           /// for 3 times wrong pass both user and admin ...
void tim ();          /// for time ..





void gotoxy(int x,int y);                         /// xy axix ...
void add_user();                                 /// add user for admin mode ...
void tim();                                     /// for time ...
void check_user ();                            /// check user pin , amount , user name (admin mode) ...
void remove_acc ();                           /// Remove ACC (admin mode)...
void admin();                                /// ADMIN MODE ...
void design();                              /// for console design ...
char check_balance(char x[100]);           /// USER id pass , user amount check ...
char deposit (char x[100]);               /// User id pass,Deposit cash ...
char _password(char buffer[]);           /// Password buffer , print "*" ...
void withdraw (char x[100] , int w);    /// user id pass , withdraw amount pass ...









COORD coord = {0,0};          ///global variable ...



void gotoxy(int x,int y)   ///function for gotoxy


{
    coord.X = x;       /// for x axix ...
    coord.Y = y;      /// for y axix ...
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);/// COROD holds the value of x , y & GetStdHandle return (input , output , error) handle ...
}







void tim ()
{
    time_t mytime;
    mytime = time(NULL);
    printf(ctime(&mytime));
}









void add_user()
{

    system("cls");
    design();
    gotoxy(30,10);
    printf("ADD NEW USER : ");
    scanf("%s",ui);
    gotoxy(30,11);
    printf("USER'S PIN : ");
    scanf("%s",up);
    gotoxy(30,12);
    printf("USER'S AMOUNT :");
    scanf("%d",&ub);

    fflush(stdin);
    system("cls");
    design();
    gotoxy(30,10);
    printf("USER:%s PIN:%s AMOUNT:%d",ui,up,ub);
    gotoxy(30,15);
    printf("PRESS Y FOR CONFIRM , PRESS N FOR DENIED:");
    scanf("%c",&ch);
    if(ch=='Y')
    {



        fp=fopen("user.txt","a");            ///data file open to append (add) record

        fprintf(fp,"%s %s %d\n",ui,up,ub);  ///record written in datafile
        system("cls");
        gotoxy(30,10);
        printf("%s %s %d",ui,up,ub);       /// print user id , password , balance on console ...
        fclose(fp);                       /// close database ...
        design();
        gotoxy(30,10);
        printf("USER:%s PIN:%s AMOUNT:%d",ui,up,ub);
        system("cls");

    }
    else if (ch=='N') printf(" NOT ADDED !!");

}









char _password(char buffer[])
{
    char c;
    int pos = 0;
    int a = 0;
    do
    {
        c = getch();

        if( c==' ')
        {
            printf("\a");
        }
        else if( isprint(c) )
        {
            buffer[ pos++ ] = c;
            printf("%c", '*');
        }
        else if( c == 8 && pos )
        {
            buffer[ pos-- ] = '\0';
            printf("%s", "\b \b");
        }
    }
    while( c != 13 );

}







void check_user ()
{
    system("cls");
    design();
    gotoxy(55,5);
    tim();
    gotoxy(30,10);
    printf("ENTER ACOUNT NO :");
    scanf("%s",&in_u);

    fp=fopen("user.txt","r");  ///data file open to append (add) record ...

    while(fscanf(fp,"%s %s %d\n",&ui,&up,&ub)!=EOF)
    {


        if(strcmp(in_u,ui)==0)
        {
            system("cls");
            design();
            gotoxy(55,5);
            tim();
            gotoxy(30,10);
            printf("USER ID:%s  PIN:%s  AMOUNT:%d\n",ui,up,ub);
            break;
        }
        else
        {
            system("cls");
            design();
            gotoxy(55,5);
            tim();
            gotoxy(30,11);
            printf("NO MATCH FOUND !");
        }
    }

    fclose(fp);

}







void remove_acc ()
{

    char x[100];

    system("cls");
    fflush(stdin);
    design();
    gotoxy(35,10);
    printf("ENTER AC NO DELET :");
    gotoxy(35,11);
    scanf("%s",x);
    system("cls");


    fp=fopen("user.txt","r");   ///data file open to append (add) record ...
    fp1=fopen("temp.txt","a");


    while(fscanf(fp,"%s %s %d\n",&ui,&up,&ub)!=EOF)
    {

        if(strcmp(x,ui)==0)
        {

        }
        else
        {
            fprintf(fp1,"%s %s %d\n",ui,up,ub); /// print on a new file name temp.txt ...

        }

    }

    fclose(fp);
    fclose(fp1);

    system("del user.txt");    /// data store (user.txt) delete ...
    system("ren temp.txt user.txt"); /// rename temp.txt to user.txt ...



}







void admin()
{
    char ia [100],j[100];    /// console input for admin ...
    char id[100], pin[100]; /// for match ...

a:

    system("cls");
    system("color 2F");
    fpa=fopen("admin.txt","r");
    design();
    gotoxy(55,5);
    tim();
    gotoxy(35,10);
    printf("ENTER YOUR USER NAME :");
    fflush(stdin);
    scanf("%s",ia);
    gotoxy(35,15);
    printf("ENTER YOUR PASSWORD :");
    _password(j);

    if(count==3)
    {
        system("cls");
        design();
        gotoxy(30,10);
        printf("Is there any problem!? contac us !phone:01xxxxxx");
        fclose(fp);
        exit(0);
    }
    while(fscanf(fpa,"%s %s\n",&id,&pin)!=EOF)   /// scan from file(admin.txt)
    {
        {
            if(strcmp(ia,id)==0)

            {
                if(strcmp(j,pin)==0)

                {

B:
                    system("cls");

                    design();
                    gotoxy(55,5);
                    tim();
                    gotoxy(15,10);
                    printf("1.CHECK\t\t2.ADD USER\t\t3.DELETE\t\t4.LOGOUT");
                    gotoxy(30,11);
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1 :
                        system("cls");
                        check_user ();
                        gotoxy(35,11);
                        printf("Enter the Choice: \n\n\t\t\t[1] Main Menu\t\t\t[0] Exit\n");
                        gotoxy(25,15);
                        scanf("%d",&choice);

                        switch (choice)

                        {

                        case 1:

                            goto B;

                        case 0:
                            fflush(stdin);
                            fclose(fp);
                            exit(0);



                        default:

                            printf("Invalid choice");

                            break;
                        }

                        break;
                    case 2 :
                        add_user();
                        system("cls");
                        design();
                        goto B;
                        break;
                    case 3 :
                        remove_acc ();
                        system("cls");
                        design();
                        goto B;
                        break;
                    case 4:

                        exit(0);


                    }
                }

            }

            else
            {
                count++;


                system("color 4");
                goto a;

            }
        }
    }
    fclose(fpa);
}













void design()
{
    int ch, kh, rows=25, columns=100;
    for(ch=1; ch<=rows; ch++)
    {
        for(kh=1; kh<=columns; kh++)
        {
            if(ch==1 || ch==rows || kh==1 || kh==columns)
            {
                printf("*");
            }
            else
            {

                printf(" ");
            }
        }
        printf("\n");
    }
}












char check_balance(char x[100])
{

    system("cls");

    fp=fopen("user.txt","r");   ///data file open to append (add) record

    while(fscanf(fp,"%s %s %d\n",&ui,&up,&ub)!=EOF)
    {




        if(strcmp(x,ui)==0)
        {
            system("cls");
            design();
            gotoxy(35,10);
            printf("YOUR BALANCE : %d/=",ub);
            break;
        }
    }

    fclose(fp);

}






char deposit (char x[100])
{
    system("cls");
    fflush(stdin);
    design();
    gotoxy(30,10);
    printf("DEPOSIT AMOUNT :");
    scanf("%d",&amt);



    fp=fopen("user.txt","r");
    fp1=fopen("temp.txt","a");


    while(fscanf(fp,"%s %s %d\n",&ui,&up,&ub)!=EOF)
    {

        if(strcmp(x,ui)==0)
        {


            fprintf(fp1,"%s %s %d\n",ui,up,ub+=amt);

        }
        else
        {
            fprintf(fp1,"%s %s %d\n",ui,up,ub);

        }
        system("cls");
        design();
        gotoxy(30,10);
        printf("DEPOSIT SUCCESFUL : %d\n",amt);




    }
    fclose(fp);
    fclose(fp1);

    system("del user.txt");
    system("ren temp.txt user.txt");
}






void withdraw (char x[100] , int w)
{

    system("cls");


    fp=fopen("user.txt","r");
    fp1=fopen("temp.txt","a");




    while(fscanf(fp,"%s %s %d\n",&ui,&up,&ub)!=EOF)
    {
        if(strcmp(x,ui)==0)
        {


            fprintf(fp1,"%s %s %d\n",ui,up,ub-=w);
        }

        else
        {
            fprintf(fp1,"%s %s %d\n",ui,up,ub);

        }
    }





    system("cls");
    design();
    gotoxy(30,10);
    printf("COLLECT YOUR CASH : %d\n",w);
    gotoxy(30,11);
    printf("your balance is %d",ub);
    fclose(fp);
    fclose(fp1);


    system("del user.txt");
    system("ren temp.txt user.txt");

}










int main ()
{

a:
    system("cls");
    fflush(stdin);
    system("color 2F");
    design();


    gotoxy(35,10);
    printf("#########################");
    gotoxy(35,11);
    printf("# WELLCOME TO ATM BOOTH #");
    gotoxy(35,12);
    printf("#########################");
    gotoxy(35,14);
    scanf("%c",&ch);
    if(ch=='A')
    {
        admin();

    }
    else if (!kbhit())
    {



        system("cls");
        fflush(stdin);
        system("color 2F");
        design();



        gotoxy(35,10);
        printf("ENTER YOUR USER NAME :");
        scanf("%s",in_u);
        gotoxy(35,15);
        printf("ENTER YOUR PASSWORD :");
        scanf("%s",in_p);
        printf("\t\t\t\t\n\n\n\n\n\n\n\n");
        fp=fopen("user.txt","r");
        if(count==3)
        {
            system("cls");
            design();
            gotoxy(30,10);
            printf("Is there any problem!? contac us !phone:01xxxxxx");
            fclose(fp);
            exit(0);
        }
        while(fscanf(fp,"%s %s %d\n",&ui,&up,&ub)!=EOF)
        {

            if(strcmp(in_u,ui)==0)

            {
                if(strcmp(in_p,up)==0)

                {
                    system("cls");
                    system("color 2F");
                    fclose(fp);
                    {

                        int choice ;
                        fflush(stdin);
                        system("cls");
main:
                        system("cls");
                        design();
                        gotoxy(35,5);
                        printf(" # WELLCOME TO ATM SYSTEM #");
                        fflush(stdin);
                        gotoxy(20,10);
                        printf("1.CHECK BALANCE.");
                        gotoxy(20,11);
                        printf("2.WITHDRAW CASH.");
                        gotoxy(20,12);
                        printf("3.DEPOSITE CASH.");
                        gotoxy(20,13);
                        printf("4.helpLINE.");
                        gotoxy(20,14);
                        printf("5.QUIT");
                        gotoxy(20,15);

                        system("color 2F");
                        printf("ENTER YOUR CHOICE : ");

                        scanf("%d",&choice);

                        fflush(stdin);
                        system("cls");
                        design();
                        switch(choice)
                        {

                        case 1 :
                            check_balance(in_u);
                            gotoxy(35,11);
                            printf("Enter the Choice: \n\n\t\t\t[1] Main Menu\t\t\t[0] Exit\n");
                            gotoxy(25,15);
                            scanf("%d",&choice);

                            switch (choice)

                            {

                            case 1:

                                goto main;

                            case 0:
                                fflush(stdin);
                                fclose(fp);
                                exit(0);



                            default:

                                printf("Invalid choice");

                                break;
                            }


                            break;
                        case 2 :
                            system("cls");
                            fflush(stdin);
                            design();
                            gotoxy(35,10);
                            printf("WITHDRAW AMOUNT :");
                            scanf("%d",&amt);
                            if(amt>=ub)
                            {
                                system("cls");
                                fflush(stdin);
                                design();
                                gotoxy(35,10);
                                printf("INSUFFICIENT BALANCE!");
                            }
                            else if (amt%100==0)
                            {

                                withdraw(in_u,amt);
                            }
                            else
                            {
                                system("cls");
                                design();
                                gotoxy(30,10);
                                printf("YOU HAVE TO WITHDRAW CASH IN MULTIPLE OF 100/=");
                            }
                            gotoxy(35,11);
                            printf("Enter the Choice: \n\n\t\t\t[1] Main Menu\t\t\t[0] Exit\n");
                            gotoxy(25,15);
                            scanf("%d",&choice);

                            switch (choice)

                            {

                            case 1:

                                goto main;

                            case 0:
                                fflush(stdin);
                                fclose(fp);
                                exit(0);



                            default:

                                printf("Invalid choice");

                                break;
                            }

                            break;

                        case 3 :

                            deposit(in_u);
                            gotoxy(35,11);
                            printf("Enter the Choice: \n\n\t\t\t[1] Main Menu\t\t\t[0] Exit\n");
                            gotoxy(25,15);
                            scanf("%d",&choice);

                            switch (choice)

                            {

                            case 1:

                                goto main;

                            case 0:
                                fflush(stdin);
                                fclose(fp);
                                exit(0);



                            default:

                                printf("Invalid choice");

                                break;
                            }

                            break;

                        case 4 :
                            system("cls");
                            design();
                            gotoxy(30,10);
                            printf("CONTAC US ! CONTAC INFO : XXXXXXXX");
                            gotoxy(35,11);
                            printf("Enter the Choice: \n\n\t\t\t[1] Main Menu\t\t\t[0] Exit\n");
                            gotoxy(25,15);
                            scanf("%d",&choice);

                            switch (choice)

                            {

                            case 1:

                                goto main;

                            case 0:
                                fflush(stdin);
                                fclose(fp);
                                exit(0);



                            default:

                                printf("Invalid choice");

                                break;
                            }

                            break;
                        case 5:
                            system("cls");
                            fflush(stdin);
                            system("color 2F");
                            design();


                            gotoxy(35,10);
                            printf("#########################################");
                            gotoxy(35,11);
                            printf("# THANK YOU ! FOR USING OUT ATM BOOTH ! #");
                            gotoxy(35,12);
                            printf("#########################################\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            exit(0);

                        }
                    }
                }
                else
                {
                    count++;



                    system("color 4F");

                    goto a;
                }



            }


            else
            {
                system("cls");
                design();
                gotoxy(30,10);
                printf("UNAUTHORIZED CREDIT CARD!");
            }
        }


    }
}
