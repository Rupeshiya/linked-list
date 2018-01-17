#include<stdio.h>
struct node
{
    int info;
    struct node* link;

};
struct node * start=NULL;
struct node *createnode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return(n);
};
void insertnode()
{
    struct node* temp;
    temp=createnode();
    printf("enter the info\n");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;

    }
    else
    {
        struct node *t;
        t=start;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;

    }

}
void insert_n()//insertion at second position;
{
    struct node * ptr;
    struct node * y;
    y=start;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to insert");
    scanf("%d",&ptr->info);
    ptr->link=y->link;
    y->link=ptr;

}
void insertafter()
{int x;
    struct node *p,*k;
    k=createnode();
    printf("\nenter the element to insert after");
    scanf("%d",&x);
    printf("\nenter the element to insert");
    scanf("%d",&k->info);
    p=start;
    while(p!=NULL)
    {
        if(p->info==x)
        {
            k->link=p->link;
            p->link=k;
        }
        p=p->link;
    }
}
void viewlist()
{
    struct node *p;

    if(start==NULL)
    {
        printf("linked list is empty\n");

    }
    else
    {
          p=start;
          while(p!=NULL)
          {
              printf("%d ",p->info);
              p=p->link;
          }
    }
}
void insertbefore()
{
    struct node *p,*y;
    int x;
    y=createnode();
    printf("\nenter the element to insert");
    scanf("%d",&y->info);
    printf("\nenter the number before which to insert");
    scanf("%d",&x);
    if(start==NULL)
       {
           printf("not possible");
       }
    else
    {p=start;
        while(p->link!=NULL)
        if(p->link->info==x)
       {
        y->link=p->link;
            p->link=y;
        }
        p=p->link;
    }
}
void deletelast()
{
    struct node *t,*y;

    t=start;
    int n;
    printf("\nenter the element to delete");
    scanf("%d",&n);

    while(t->link!=NULL)
    {
        if(t->link->info==n)
        {
            y=t->link;
            t->link=y->link;
            free(y);
            return start;
        }
        t=t->link;
    }
}

void search()
{
    int n;
    struct node *x,*p;
    x=createnode();
    printf("\nenter the element to search");
    scanf("%d",&n);
    p=start;
    int pos=1;
    if(start==NULL)
        printf("\n %d not found",n);
    while(p!=NULL)
    {
        if(p->info==n)
        {
            printf("%d found at %d pos",n,pos);
        }
        p=p->link;
        pos++;
    }
}
void deletenode()
{
    struct node *r;
    if(start==NULL)
        printf("\n linked list is empty");

    r=start;
    start=start->link;
    free(r);

}
int main()
{int n;
    while(1)
    {printf("\n 1.add value");
    printf("\n 2.view value");
    printf("\n 3.delete value");
    printf("\n 4.insert at 2nd position");
    printf("\n 5.insert after the number ");
    printf("\n 6.insert before");
    printf("\n 7.search");
    printf("\n 8.exit");
    printf("\n 9.delete last");
    printf("\n enter your choice");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            insertnode();
            break;
        case 2:
            viewlist();
            break;
        case 3:
            deletenode();
            break;
        case 4:
            insert_n();
            break;
        case 5:
            insertafter();
            break;
        case 6:
            insertbefore();
            break;
        case 7:
            search();
            break;

        case 8:
            exit(0);
            break;
        case 9:
            deletelast();
            break;
        default:
            printf("\n invalid choice");

    }
    }
}
