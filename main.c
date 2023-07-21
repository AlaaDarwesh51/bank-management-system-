#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void create();
void display();
void delete_pos();
void customer_edit();
void TRANSACT ();
void CUSTOMER_LIST ();
void acount_list();
struct data
{
    char account_name[50] ,gender ;
    int id,AccNo,PhNo,birthday ;
};
struct node
{
        struct data info;
        struct node *next;
      //  struct Trans *trans;
};
struct node *start=NULL;
struct Date
{
    int d,m,y;
};
struct trans
{   int AN;
    char m;
    int n;
    struct Date date ;
    struct trans *link;
};
struct trans *head=NULL;
//trans=NULL;
int main()
{            /*welcome screen to perform different
            banking activities mentioned below. */
            printf("Welcome To Your Bank ^_^ \n");
            printf("We Are Happy For Helping You _ \n");
        int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.plz Enter 1 for NEW_ACCOUNT    \n");
                printf("\n 2.Display    \n");
                printf("\n 3.plz Enter 3 for Deleting ACCOUNT     \n");
                printf("\n 4.plz Enter 4 Display CUSTOMER_LIST  \n");
                printf("\n 5.plz Enter 5 for CUSTOMER_EDIT        \n");
                printf("\n 6.plz Enter 6 for ACCOUNT_LIST      \n");
                printf("\n 7.plz Enter 7 for Transaction    \n");
                printf("\n 8.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        delete_pos();
                                        break;
                        case 4:
                                        CUSTOMER_LIST();
                                        break;
                        case 5:
                                        customer_edit();
                                        break;
                        case 6:
                                       acount_list();
                                        break;

                        case 7:
                                       TRANSACT ();
                                        break;

                        case 8:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }
         printf("enter your name\n ");
            fflush(stdin);
           gets(&temp->info.account_name);
           //fflush(stdin);
            printf("enter your gender\n ");
            fflush(stdin);
            scanf ("%c",&temp->info.gender);
            printf("enter id\n ");
            fflush(stdin);
            scanf ("%d",&temp->info.id);
           printf("enter Account No\n ");
            fflush(stdin);
            scanf ("%d",&temp->info.AccNo);
            printf("enter Phone No\n ");
            fflush(stdin);
            scanf ("%d",&temp->info.PhNo);
            printf("enter Your Year Of Birth\n ");
            fflush(stdin);
            scanf ("%d",&temp->info.birthday);

            printf("You Have Successfully Added This New Account\n");

        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe CUSTOMER_LIST are:\n");
                while(ptr!=NULL)
                {   printf ("\n{Account Name:%s  Gender:%c   id:%d   Account No:%d    Phone No:%d    Birthday Year:%d}\n",
                    ptr->info.account_name,
                    ptr->info.gender,
                    ptr->info.id,ptr->info.AccNo,
                    ptr->info.PhNo,ptr->info.birthday);
                        ptr=ptr->next ;
                }
        }
}
void delete_pos()
{
         int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the Position of the Account to be deleted:\t");
                scanf("%d",&pos);

                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info.account_name  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted Account is:%d\t",ptr->info.account_name);
                        free(ptr);
                }
}}

void customer_edit()
{
	// Initialize current
	int x,ch;
	struct node* current = start;
	printf("\nEnter the Account No of the Account to be edited :\t");
                scanf("%d",&x);

	while (current != NULL)
	{
		if (current->info.AccNo == x)
        {   printf("\n 1.plz Enter 1 for Editing Your Name    \n");
                printf("\n 2.plz Enter 2 for Editing Your Gender    \n");
                printf("\n 3.plz Enter 3 for Editing Your id    \n");
                printf("\n 4.plz Enter 4 for Editing Your Account No \n");
                printf("\n 5.plz Enter 5 for Editing Your Phone No       \n");
                printf("\n 6.plz Enter 6 for Editing Your Year Of Birth     \n");

            printf("Enter your choice:\t");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:{
                            printf("enter your new name\n ");
                            fflush(stdin);
                            gets(&current->info.account_name);
                                        break;}
                        case 2:{
                            printf("enter your new gender\n ");
                            fflush(stdin);
                            scanf ("%c",&current->info.gender);
                                        break;}
                        case 3:{
                            printf("enter new id\n ");
                            fflush(stdin);
                            scanf ("%d",&current->info.id);

                                        break;}
                        case 4:{
                            printf("enter new Account No\n ");
                            fflush(stdin);
                            scanf ("%d",&current->info.AccNo);
                                        break;}
                        case 5:{
                             printf("enter new Phone No\n ");
                             fflush(stdin);
                             scanf ("%d",&current->info.PhNo);

                                        break;}
                        case 6:{
                            printf("enter Your new Year Of Birth\n ");
                            fflush(stdin);
                            scanf ("%d",&current->info.birthday);

                                        break;}
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }

        }

		current = current->next;
	}
        printf("You Have Successfully Edited This New Account\n");
}
void CUSTOMER_LIST(){


     struct node *ptr;
    char t[25];
    char g ;
    int d,a,p,b;
    struct node*temp=start;
    struct node*temp1=temp->next;

    while(temp1!=NULL){
        if(strcmp(temp->info.account_name,temp1->info.account_name)>0){
            strcpy(t,temp1->info.account_name);
            strcpy(temp1->info.account_name,temp->info.account_name);
            strcpy(temp->info.account_name,t);
            g=temp1->info.gender;
            temp1->info.gender=temp->info.gender;
            temp->info.gender=g;

            d=temp1->info.id;
            temp1->info.id=temp->info.id;
            temp->info.id=d;

            a=temp1->info.AccNo;
            temp1->info.AccNo=temp->info.AccNo;
            temp->info.AccNo=a;

            p=temp1->info.PhNo;
            temp1->info.PhNo=temp->info.PhNo;
            temp->info.PhNo =p;

            b=temp1->info.birthday;
            temp1->info.birthday=temp->info.birthday;
            temp->info.birthday=b;
        }
        temp=temp->next;
        temp1=temp->next;
    }
////////////////
    temp=start;
    temp1=temp->next;

    while(temp1!=NULL){
        if(strcmp(temp->info.account_name,temp1->info.account_name)>0){
            strcpy(t,temp1->info.account_name);
            strcpy(temp1->info.account_name,temp->info.account_name);
            strcpy(temp->info.account_name,t);
            g=temp1->info.gender;
            temp1->info.gender=temp->info.gender;
            temp->info.gender=g;

            d=temp1->info.id;
            temp1->info.id=temp->info.id;
            temp->info.id=d;

            a=temp1->info.AccNo;
            temp1->info.AccNo=temp->info.AccNo;
            temp->info.AccNo=a;

            p=temp1->info.PhNo;
            temp1->info.PhNo=temp->info.PhNo;
            temp->info.PhNo =p;

            b=temp1->info.birthday;
            temp1->info.birthday=temp->info.birthday;
            temp->info.birthday=b;
        }
        temp=temp->next;
        temp1=temp->next;
    }

    //display

        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe CUSTOMER_LIST are:\n");
                while(ptr!=NULL)
                {   printf ("\n{Account Name:%s  Gender:%c   id:%d   Account No:%d    Phone No:%d    Birthday Year:%d}\n",ptr->info.account_name,
                    ptr->info.gender,
                    ptr->info.id,ptr->info.AccNo,
                    ptr->info.PhNo,ptr->info.birthday);
                        ptr=ptr->next ;
                }
        }
}
void TRANSACT ()
{

	struct trans *ppp ;
	struct trans* tempp;
    tempp=(struct trans *)malloc(sizeof(struct trans));
        if(tempp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

            printf("\nEnter the Account No For Transaction :\t");
            fflush(stdin);
            scanf ("%d",&tempp->AN);
            printf("Enter Day\n ");
            fflush(stdin);
            scanf ("%d",&tempp->date.d);
           printf("Enter Month\n ");
            fflush(stdin);
            scanf ("%d",&tempp->date.m);
            printf("Enter Year\n ");
            fflush(stdin);
            scanf ("%d",&tempp->date.y);
            printf("Enter 'd' for deposit OR Enter 'w' for withdraw \n ");
            fflush(stdin);
            scanf ("%c",&tempp->m);
            printf("enter the Amount of Money \n ");
            fflush(stdin);
            scanf ("%d",&tempp->n);
            printf("Your Transaction Successfully Done For Your Account\n");
            printf("Acount No:%d    date:%d/%d/%d   Transaction:%c  Amount:%d  \n",
                   tempp->AN,tempp->date.d,tempp->date.m,
                   tempp->date.y,tempp->m,tempp->n);

        tempp->link=NULL;
        if(head==NULL)
        {
                head=tempp;
        }
        else
        {
                ppp=head;
                while(ppp->link!=NULL)
                {
                        ppp=ppp->link;
                }
                ppp->link=tempp;
        }

}
void acount_list()
{
    int x,ch;
	struct trans* crr = head;
	if(head==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
	printf("\nEnter the Account No to Show it's Transaction :\t");
                scanf("%d",&x);

	while (crr != NULL)
	{    printf("\nThe Account List are:\n");
		if (crr->AN == x)
        {
                {       printf("Acount No:%d    date:%d/%d/%d   Transaction:%c  Amount:%d  \n",
                        crr->AN,crr->date.d,crr->date.m,
                        crr->date.y,crr->m,crr->n);

                }

        }
         crr=crr->link ;
	}
        }
}
