/* 
   Program : To make a record management system 
   Author : Vardaan Khadka Chhetri 
            Class of 2023 
            Section: B
            Roll no.: 948
   Date : 3rd May , 2020
*/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
	int i,j;
	int main_exit;
	
	
	
	void menu();
	void exit_app();
	void search();
	void delete();
	void edit_record();
	void view_record();
	void new_record();
	void fordelay(int);


struct date{
    int month,day,year;

};
struct {

    char name[60];
    int record_no,age;
    char address[60];
    char status[255];
    double phone;
    struct date dob;

}add,upd,check,rem;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
        k=i;
}

void new_record()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    record_number:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\nEnter the record number:");
    scanf("%d",&check.record_no);
    while(fscanf(ptr,"%d  %s %d/%d/%d %d %s %s %lf \n",&add.record_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.status,&add.phone)!=EOF)
    {
        if (check.record_no==add.record_no)
        {printf("Record no. already in use!");
            fordelay(1000000000);
            goto record_number;

        }
    }
    add.record_no=check.record_no;
    printf("\nEnter the name:");
    scanf(" %s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the status of patient:");
    scanf("%s",add.status);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);

    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf \n",add.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.status,add.phone);


    fclose(ptr);
    printf("\nRecord created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        exit_app();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}
void view_record()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nRECORD NO\tNAME\t\tDOB\t\tAGE\t\tADDRESS\t\tSTATUS\t\tPHONE");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf",&add.record_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.status,&add.phone)!=EOF)
    {
        fflush(stdin);
        printf("\n%d\t\t%s\t\t%d/%d/%d\t%d\t\t%s\t\t%s\t\t%.0lf",add.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.status,add.phone);
        test++;
    }

    fclose(view);
    if (test==0)
    {   system("cls");
        printf("\nNO RECORDS!!\n");}

    view_record_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        exit_app();
    else
    {
        printf("\nInvalid!\a");
        goto view_record_invalid;
    }
}
void edit_record(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the record no. of the patient whose info you want to change:");
    scanf("%d",&upd.record_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf ",&add.record_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.status,&add.phone)!=EOF)
    {
        if (add.record_no==upd.record_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Status\n2.Record Number\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {printf("Enter the new stauts:");
                scanf("%s",upd.status);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf \n",add.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,upd.status,add.phone);
                system("cls");
                printf("Changes saved!");
            }
            else if(choice==2)
            {
                printf("Enter the new record number:");
                scanf("%lf",&upd.record_no);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf \n",upd.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.status,add.phone);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf \n",add.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.status,add.phone);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
    {   system("cls");
        printf("\nRecord not found!!\a\a\a");
        edit_record_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)

            menu();
        else if (main_exit==2)
            exit_app();
        else if(main_exit==0)
            edit_record();
        else
        {printf("\nInvalid!\a");
            goto edit_record_invalid;}
    }
    else
    {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit_app();
    }
}

void delete(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.record_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf ",&add.record_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.status,&add.phone)!=EOF)
    {
        if(add.record_no!=rem.record_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf \n",add.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.status,add.phone);

        else
        {test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
        delete_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if (main_exit==2)
            exit_app();
        else if(main_exit==0)
            delete();
        else
        {printf("\nInvalid!\a");
            goto delete_invalid;}
    }
    else
    {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit_app();
    }

}

void search(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.record_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf",&add.record_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.status,&add.phone)!=EOF)
        {
            if(add.record_no==check.record_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nstatus:%s \nPhone number:%.0lf \n\n",add.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.status,add.phone);
            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf ",&add.record_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.status,&add.phone)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nStatus:%s \nPhone number:%.0lf\n\n",add.record_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.status,add.phone);


            }
        }
    }


    fclose(ptr);
    if(test!=1)
    {   system("cls");
        printf("\nRecord not found!!\a\a\a");
        search_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            exit_app();
        else if(main_exit==0)
            search();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto search_invalid;}
    }
    else
    {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
    if (main_exit==1)
    {
        system("cls");
        menu();
    }

    else
    {

        system("cls");
        exit_app();
    }

}


void exit_app(void)
{
    printf("\n\n\n\nThank you for using the software.");
}


void menu(void)
{   int choice;
    system("cls");
    printf("\n\n\t\t\tPATIENT RECORDING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new record\n\t\t2.Update information of existing record\n\t\t3.Check the details of existing record\n\t\t4.Remove existing record\n\t\t5.View all record\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_record();
            break;
        case 2:edit_record();
            break;
        case 3:search();
            break;
        case 4:delete();
            break;
        case 5:view_record();
            break;
        case 6:exit_app();
            break;

    }



}
int main()
{
    menu();
    return 0;
}

