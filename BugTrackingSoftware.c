/*
****************************************************************************************************************************************
        This is a Bug-Detection Software. It has two options :
        1. user
        2.Two for the manager .

        After the option is opted , it will open the menu for both the user and manager depending upon choice.

        The user menu has 3 options:
        1.Reporting a new bug present in software.
        2.Displaying Bug Statistics.
        3.Going back to the menu

        The manager menu has 4 options:
        1.Assigning bug to the person
        2.Changing status of bug
        3.Displaying Bug Statistics.
        4.Going back to the menu
****************************************************************************************************************************************
*/

#include "functions.h"
#include "user.c"
#include "manager.c"

 //This displays the menu and asks the user to enter the choice.This choice is returned to the int main

int menu3()
{
    int ch,a;
    printf("Log in as:");
    printf("\n1.User   ");
    printf("\t2.Manager");
    printf("\t3.Exit");
    printf("\nEnter your  choice:");
    a=scanf("%d", &ch);
    //Verfication of input
    while (a!=1 || (ch!=1 && ch!=2 && ch!=3) )
        {
            printf("\nOnly integer inputs in the range 1 to 3 allowed: \n");
            fflush(stdin);
            a=scanf("%d",&ch);
        }
        return ch;
}

int main()
{
    int choice;
    /*
    A do-while loop is present to allow the user to use the software till he wishes to exit from the program.The return value of menu3() is stored in a variable and this
    variable is used for implementing the condition for while loop
     */
    do{
    choice=menu3();
    switch(choice)
    {
        case 1:
            UserMenu();
            break;

        case 2:
            ManagerMenu();
            break;

        case 3:
            break;

        default:
            printf("\nWrong Choice!!Try again\n");
            break;
    }
    }while(choice<=2);
    return 0;
}
