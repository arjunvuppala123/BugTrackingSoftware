#include<stdio.h>
#include<string.h>
#include<ctype.h>

//a structure for storing time user logged in
struct time
{
    int hours;
    int minutes;
    char period[2];
};

//structure for storing data for bug
struct bug
{
    int id;                                      // unique id
    char Description[500];            // description of bug
    char Filled_by_name[50];       // the one who filled the bug
    char Priority[10];                   // stores either HIGH,MEDIUM,LOW
    char Type[10];                      // stores either MAJOR , MINOR AND COSMETIC
    char Status[50];                    // Stores the status of bug
    char Assigned_to[50];           // assigns the bug to a person
    struct time Loggedin;            // stores time at which time the user logged in
};

typedef struct bug bug;

//changes name of the structure

//a function for displaying data
void display(bug b)
{
    if (strcmp(b.Status,"NOT-ASSIGNED")==0)
        {
            printf("\nID:%d\nName of user who filled the bug:%s\nStatus:%s\nType:%s\nPriority:%s\nDescription:%s\nTime: %d:%d %s\n",b.id,b.Filled_by_name,b.Status,b.Type,b.Priority,b.Description,b.Loggedin.hours,b.Loggedin.minutes,b.Loggedin.period);
        }
        else
            {
                printf("\nID:%d\nfiler name:%s\nStatus:%s\nType:%s\nPriority:%s\nDescription:%s\nAssigned to:%s\nTime: %d : %d %s\n",b.id,b.Filled_by_name,b.Status,b.Type,b.Priority,b.Description,b.Assigned_to,b.Loggedin.hours,b.Loggedin.minutes,b.Loggedin.period);
            }
}

//converts lowercase string to upper case used in many functions in the software
void convertUpperCase(char str[])
{
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
    }
}

//checks if string value of priority of bug is HIGH , MEDIUM , LOW
int CheckPriority(char str[])
{
    if(strcmp(str,"HIGH")==0)
    {
        return 0;
    }
    else if (strcmp(str,"LOW")==0)
    {
        return 0;
    }
    else if(strcmp(str,"MEDIUM")==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//checks if string value of type of bug is Major , Minor , cosmetic
int CheckType(char str[])
{
    if(strcmp(str,"MAJOR")==0)
    {
        return 0;
    }
    else if (strcmp(str,"MINOR")==0)
    {
        return 0;
    }
    else if(strcmp(str,"COSMETIC")==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//checks if string value of period is AM OR PM
int CheckPeriod(char str[])
{
    if(strcmp(str,"AM")==0)
    {
        return 0;
    }
    else if (strcmp(str,"PM")==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Verification of input for hours
int CheckHours(int hours)
{
    if (hours>12)
    {
        return 1;
    }
    else if (hours<0)
    {
        return  1;
    }
    else
    {
        return 0;
    }
}

//Verification of input for minutes
int CheckMinutes(int minutes)
{
    if (minutes>=60)
    {
        return 1;
    }
    else if (minutes<=0)
    {
        return  1;
    }
    else
    {
        return 0;
    }
}

//generates a unique id for record
int id()
{
    FILE *ipt;
	int Max=0;
	bug FileRec;
	 ipt = fopen ("sample.dat", "rb");
	 rewind(ipt);
	 while(fread(&FileRec, sizeof(FileRec), 1, ipt)==1)
            {
                if(FileRec.id>Max)
                {
                    Max=FileRec.id;
                }
            }
	 Max=Max+1;
	 return Max;
}

//checks if input of type string has no numbers or special characters
int checkstring(char str[])
{
    int i,ctr=0;
    for (i=0; str[i]!= '\0'; i++)
    {
        if (isdigit(str[i]))
            {
                ctr=ctr+1;
            }
    }
    if (ctr>0)
    {
        return 1;
    }
    else{
        return 0;
    }

}

//Checks if bug is present in the file by bug id
int BugFound(bug x,int item)
{
    FILE *ipt;
    int flag=0;
    ipt=fopen("sample.dat", "rb");
    rewind(ipt);
    while(fread(&x, sizeof(x), 1, ipt)==1)
        {
            if (x.id==item)
            {
                flag=1;
            }
        }
    fclose(ipt);
    return flag;
}

//Allows the user to enter a new bug in the file
void BugEntry()
{
    int a,e,d,f,g,h,i,j,k,l,m;  //used for verification of input
    bug b;
    FILE *fpt;
    char ch;

            fpt=fopen("sample.dat","ab");

            b.id=id();
            printf("ID:#%d\n",b.id);

            printf("Enter name of user who filed the bug:");
            scanf(" %[^\n]%*c",b.Filled_by_name);
            //verification of input
            f=checkstring(b.Filled_by_name);
            while(f==1)
            {
                printf("Enter string only!!::");
                fflush(stdin);
                scanf(" %[^\n]%*c",b.Filled_by_name);
                f=checkstring(b.Filled_by_name);
            }
            convertUpperCase(b.Filled_by_name);

            printf("Enter Description:");
            scanf(" %[^\n]%*c",b.Description);

           strcpy(b.Status,"NOT-ASSIGNED");
           printf("Default Status is:%s\n", b.Status);

            printf("Enter priority of Bug(High, Medium, Low):");
            scanf("%s",b.Priority);
             //verification of input
            convertUpperCase(b.Priority);
            d=CheckPriority(b.Priority);
            while(d==1)
            {
                printf("Enter High, Medium, Low only!!:");
                fflush(stdin);
                scanf(" %s",b.Priority);
                convertUpperCase(b.Priority);
                d=CheckPriority(b.Priority);
            }

            printf("Enter type of bug(Major, Minor, Cosmetic):");
            scanf("%s",b.Type);
            convertUpperCase(b.Type);
             //verification of input
            a=CheckType(b.Type);
            while(a==1)
            {
                printf("Enter Major, Minor, Cosmetic only!!");
                fflush(stdin);
                scanf(" %s",b.Type);
                convertUpperCase(b.Type);
                a=CheckType(b.Type);
            }

            printf("Enter Time user logged in:\n");

            printf("Hours:");
            g=scanf("%d",&b.Loggedin.hours);
             //verification of input
            while (g!=1)
                {
                    printf("\nonly integer type allowed\n");
                    fflush(stdin);
                    g=scanf("%d",&b.Loggedin.hours);
                }
            k=CheckHours(b.Loggedin.hours);
            while (k==1)
            {
                    printf("\nonly input from 1-12 allowed:\n");
                    fflush(stdin);
                    l=scanf("%d",&b.Loggedin.hours);
                    while (l!=1)
                    {
                        printf("\nonly integer type allowed\n");
                        fflush(stdin);
                        l=scanf("%d",&b.Loggedin.hours);
                    }
                    k=CheckHours(b.Loggedin.hours);
            }

            printf("Minutes:");
             //verification of input
            h=scanf("%d",&b.Loggedin.minutes);
            while (h!=1)
                {
                    printf("\nonly integer type allowed\n");
                    fflush(stdin);
                     h=scanf("%d",&b.Loggedin.minutes);
                }
            j=CheckMinutes(b.Loggedin.minutes);
            while (j==1)
            {
                    printf("\nonly input from 0-59 allowed:\n");
                    fflush(stdin);
                    m=scanf("%d",&b.Loggedin.minutes);
                    while (m!=1)
                    {
                        printf("\nonly integer type allowed\n");
                        fflush(stdin);
                        m=scanf("%d",&b.Loggedin.minutes);
                    }
                   j=CheckMinutes(b.Loggedin.minutes);
            }

            printf("AM OR PM:");
            scanf(" %s", b.Loggedin.period);
             //verification of input
            convertUpperCase(b.Loggedin.period);
            i=CheckPeriod(b.Loggedin.period);
            while (i==1)
            {
                printf("Enter AM OR PM only!!::");
                fflush(stdin);
                scanf(" %s", b.Loggedin.period);
                convertUpperCase(b.Loggedin.period);
                i=CheckType(b.Loggedin.period);
            }


            fwrite(&b,sizeof(b),1,fpt);

             if(fwrite != 0)
                printf("Contents to file written successfully !\n");

            else
                {printf("Error writing file !\n");}
            fclose(fpt);
            scanf(" %c",&ch);

}

//displays list of bugs in terms of filer name
void dispbugstatsbyname()
{
    FILE *ipt;
    bug b;
    char item[50];
    int  flag=0,a;
    printf("Enter the name of the user:");
    scanf(" %s",item);
    checkstring(item);
    convertUpperCase(item);
    ipt = fopen ("sample.dat", "rb");
    rewind(ipt);
    while(fread(&b, sizeof(b), 1, ipt)==1)
        {
            if(strcmp(item,b.Filled_by_name)==0)
                {
                    flag=1;
                    display(b);
                }
        }
    if (flag==0)
        printf("Name not found!!");
   fclose(ipt);
}
void dispbugstatsbytype()
{
    FILE *ipt;
    bug b;
    char item[50],item1[50];
    char ch;
    int  flag=0,a,j=0;
    printf("Enter type of bug (Major , Minor, Cosmetic):");
    scanf(" %s",item);
    convertUpperCase(item);
    a=CheckType(item);
    while(a==1)
            {
                printf("Enter Major, Minor, Cosmetic only!!::");
                fflush(stdin);
                scanf(" %s",item);
                convertUpperCase(item);
                a=CheckType(item);
            }
    ipt = fopen ("sample.dat", "rb");
    rewind(ipt);
    while(fread(&b, sizeof(b), 1, ipt)==1)
        {
            if(strcmp(item,b.Type)==0)
                {
                    flag=1;
                    display(b);
                }
        }
    if (flag==0)
        printf("Bug not found!!");
    fclose(ipt);
}

//displays list of bugs in terms of status
void dispbugstatsbystatus()
{
     FILE *ipt;
    bug b;
    char item[50];
    int  flag=0,a;
    printf("Enter the status(Not-Assigned, Assigned, In-process, Fixed, Delivered):");
    scanf("%s",item);
    checkstring(item);
    convertUpperCase(item);
    ipt = fopen ("sample.dat", "rb");
    rewind(ipt);
    while(fread(&b, sizeof(b), 1, ipt)==1)
        {
            if(strcmp(item,b.Status)==0)
                {
                    flag=1;
                    display(b);
                }
        }
    if (flag==0)
        printf("Bugs with this status not found!!");
   fclose(ipt);
}

//if user chooses bug statistics in either of menu, the menu for bug statistics will appear. This allows the user to choose which option he wants to display list of bugs
void BugStats()
{
    int ch,a;
    //printf("\nBug Statistics");
    printf("\n1. Bug Statistics:View Bugs by Filer");
    printf("\n2. Bug Statistics:View Bugs by Type");
    printf("\n3. Bug Statistics:View Bugs by Status");
    printf("\nEnter Choice:");
    a=scanf("%d",&ch);
    while (a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
                a=scanf("%d",&ch);
        }
    switch(ch)
    {
        case 1:
            dispbugstatsbyname();
             break;

        case 2:
            dispbugstatsbytype();
            break;

        case 3:
            dispbugstatsbystatus();
            break;

        default:
            printf("Wrong choice!! Enter again");
            break;
        }
}

//Allows the manager to assign a bug to a person(developer)
void AssignBug()
{
    bug b;
    FILE *fpt,*fpo;
    int s, BugId, ch,flag1=0,a;
    printf("Enter bug id:");
    a=scanf("%d", &BugId);
    while (a!=1)
        {
            printf("\nOnly integer type allowed\n");
            fflush(stdin);
            a=scanf("%d",&BugId);
        }
    ch=BugFound(b,BugId);
    if (ch==0)
    {

        printf("\nBug id not found!\n");
    }
    else
    {
        fpo = fopen("sample.dat", "rb");
        fpt = fopen("TempFile.dat", "wb");
        rewind(fpo);
        while (fread(&b, sizeof(b), 1, fpo)==1)
            {
                if (b.id != BugId)
                    {
                        fwrite(&b, sizeof(b), 1, fpt);
                    }
                else
                    {
                        if (strcmp(b.Status,"NOT-ASSIGNED")!=0)
                        {
                            printf("Bug is already assigned");
                            fwrite(&b, sizeof(b), 1, fpt);
                        }
                        else
                        {
                        printf("Assign Bug to:");
                        scanf(" %s", b.Assigned_to);
                        strcpy(b.Status,"ASSIGNED");
                        printf("%s",b.Status);
                        fwrite(&b, sizeof(b), 1, fpt);
                        }
                    }
            }
                fclose(fpo);
                fclose(fpt);
                fpo = fopen("sample.dat", "wb");
                fpt = fopen("TempFile.dat", "rb");
                while (fread(&b, sizeof(b), 1, fpt))
                    {
                        fwrite(&b, sizeof(b), 1, fpo);
                    }
                fclose(fpo);
                fclose(fpt);
        }
}

//Changes the status of bug (done by developer)
void ModifyStatus()
{
    bug b;
    FILE *fpt,*fpo;
    int s, BugId, ch,flag1=0,a;
    printf("Enter bug id:");
    a=scanf("%d", &BugId);
    while (a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
            a=scanf("%d",&BugId);
        }
    ch=BugFound(b,BugId);
    if (ch==0)
    {
        printf("\nBug id not found!\n");
    }
    else
    {
        fpo = fopen("sample.dat", "rb");
        fpt = fopen("TempFile.dat", "wb");
        rewind(fpo);
        while (fread(&b, sizeof(b), 1, fpo)==1)
            {
                s = b.id;
                if (s != BugId)
                    {
                        fwrite(&b, sizeof(b), 1, fpt);
                    }
                else
                    {
                        if (strcmp(b.Status,"NOT-ASSIGNED")==0)
                            {
                                printf("Bug has not got assigned!!please assign!!");
                                fwrite(&b, sizeof(b), 1, fpt);
                            }

                                else if(strcmp(b.Status,"ASSIGNED")==0)
                                    {
                                        printf("Bug status has changed from Assigned to In-process!!");
                                        strcpy(b.Status,"IN PROCESS");
                                        fwrite(&b, sizeof(b), 1, fpt);
                                    }

                                    else if(strcmp(b.Status,"IN-PROCESS")==0)
                                        {
                                            printf("Bug status has changed from In process to Fixed!!");
                                                strcpy(b.Status,"FIXED");
                                                fwrite(&b, sizeof(b), 1, fpt);
                                            }


                                        else if(strcmp(b.Status,"FIXED")==0)
                                            {
                                                    printf("Bug status has changed from Fixed to Delivered!!");
                                                    strcpy(b.Status,"DELIVERED");
                                                    fwrite(&b, sizeof(b), 1, fpt);
                                            }
                                                else
                                                {
                                                    printf("Status change not applicable. Bug has already been fixed and delivered!!");
                                                    fwrite(&b, sizeof(b), 1, fpt);
                                                }
                                }
            }
            fclose(fpo);
            fclose(fpt);
            fpo = fopen("sample.dat", "wb");
            fpt = fopen("TempFile.dat", "rb");
            while (fread(&b, sizeof(b), 1, fpt))
                {
                    fwrite(&b, sizeof(b), 1, fpo);
                }
            fclose(fpo);
            fclose(fpt);
            }
}
