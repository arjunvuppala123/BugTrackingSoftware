//This displays the menu and asks the user to enter the choice.This choice is returned to the int main

int menu1()
{
    int ch,a;
    printf("\n\nUser Menu");
    printf("\n1.Report a bug");
    printf("\n2.Bug Statistics");
    printf("\n3.Previous Menu");
    printf("\nEnter Your Choice:");
    a=scanf("%d",&ch);
    //Verfication of input
    while (a!=1 || (ch!=1 && ch!=2 && ch!=3) )
        {
            printf("\nOnly integer inputs in the range 1 to 3 allowed \n");
            fflush(stdin);
            a=scanf("%d",&ch);
        }
        return ch;
}
void UserMenu()
{
    int choice;
    /*
    A do-while loop is present to allow the user to use the software till he wishes to go to previous menu.The return value of menu1() is stored in a variable and this
    variable is used for implementing the condition for while loop
     */
    do{
    choice=menu1();
    switch(choice)
    {
    case 1:
        BugEntry();
        break;
    case 2:
        BugStats();
        break;
    case 3:
        break;
    default: printf("Wrong Choice:");
    }
    }while(choice<=2);
}
