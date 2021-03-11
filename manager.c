//This displays the menu and asks the manager to enter the choice.This choice is returned to the int main
int menu2()
{
    int ch,a;
     printf("\n\nManager Menu");
     printf("\n1.Assign Bug:");
     printf("\n2.Modify status of bug");
     printf("\n3.Bug Statistics");
     printf("\n4.Previous Menu");
     printf("\nEnter Your Choice:");
     a=scanf("%d",&ch);
     //Verfication of input
     while (a!=1 || (ch!=1 && ch!=2 && ch!=3 && ch!=4) )
        {
            printf("\nOnly integer inputs in the range 1 to 4 allowed \n");
            fflush(stdin);
            a=scanf("%d",&ch);
        }
        return ch;
        }
void ManagerMenu()
{
     int choice;
     do
     {
         choice=menu2();
         /*
    A do-while loop is present to allow the user to use the software till he wishes to go to previous menu.The return value of menu1() is stored in a variable and this
    variable is used for implementing the condition for while loop
     */
     switch(choice)
    {
    case 1:
        AssignBug();
        break;
    case 2:
        ModifyStatus();
        break;
    case 3:
        BugStats();
        break;
    case 4:
        break;
    default: printf("Wrong Choice");
    }
     }while(choice<=3);
}
