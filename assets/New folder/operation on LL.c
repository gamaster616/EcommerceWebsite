#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * insert(struct node *head,int value)
{
    struct node * help_ptr;
    struct node * pNew = (struct node*) malloc(sizeof(struct node));
    help_ptr = head;
    pNew -> data = value;

    if(head == NULL || head -> data > value)
    {
        pNew -> next = head;
        head = pNew;
        return head;
    }
    while(help_ptr -> next != NULL && help_ptr -> next -> data < value)
    {
        help_ptr = help_ptr -> next;
    }
        pNew -> next = help_ptr -> next;
        help_ptr -> next = pNew;
        return head;
}

void copy(struct node *head1)
{

    struct node *head2 = NULL;
    printf("Copying Linked list\n");
    if(head1 != NULL)
    {
        head2 = head1;

        printf("Original Linked list: \n");
        while(head1 != NULL)
        {
            printf("%d  ",head1 -> data);
            head1 = head1 -> next;
        }
        printf("\n");

        printf("Copied Linked list: \n");
        while(head2 != NULL)
        {
            printf("%d  ",head2 -> data);
            head2 = head2 -> next;
        }
        printf("\n");
    }

    else
    {
        printf("Linked List is empty");
    }
    return;
}

void concatenate(struct node * head1, struct node * head2)
{
    if(head1 == NULL)
    {
        printf("head1 is empty");
        head1 = head2;
    }
    else if(head2 == NULL)
    {
        printf("head2 is empty");
    }
    else
    {
        struct node *help_ptr = head1;
        while(help_ptr -> next != NULL)
        {
            help_ptr = help_ptr -> next;
        }
        help_ptr -> next = head2;
    }
    printf("concatenated Linked List: \n");
    while(head1 != NULL)
        {
            printf("%d  ",head1 -> data);
            head1 = head1 -> next;
        }
        printf("\n");
        return;
}

void split(struct node *head1,int ele)
{
    struct node *head2 = NULL;
    struct node *help_ptr;
    help_ptr = head1;
    while(help_ptr -> data != ele)
    {
        help_ptr = help_ptr -> next;
    }
    head2 = help_ptr -> next;
    help_ptr -> next = NULL;
        printf("First Linked List: \n");
    while(head1 != NULL)
        {
            printf("%d  ",head1 -> data);
            head1 = head1 -> next;
        }
        printf("\n");

    printf("Second Linked List: \n");
    while(head2 != NULL)
        {
            printf("%d  ",head2 -> data);
            head2 = head2 -> next;
        }
        printf("\n");
        return;
}

void reverse(struct node *head1)
{
  struct node *prev, *curr, *help_ptr = NULL;
    curr = head1;
    prev = NULL;
    while (curr != NULL)
    {
        help_ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = help_ptr;
    }
    head1 = prev;

    printf("Rveresed Linked List: \n");
    help_ptr = head1;
    while(help_ptr != NULL)
        {
            printf("%d  ",help_ptr -> data);
            help_ptr = help_ptr -> next;
        }
        printf("\n");
}

void count(struct node *head1)
{
    int c = 0;
    while(head1 != NULL)
        {
            c++;
            head1 = head1 -> next;
        }
        printf("Number of Nodes = %d \n",c);
        return;
}

int menu()
{
int choice;
printf("MENU \n1. To create \n2. To copy \n3. To concatenate \n4. To split \n5. To reverse \n6. To count \n7. To Exit\n");
printf("Enter your choice \n");
scanf("%d",&choice);
return choice;
}
void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int choice,value,element;
do
{
choice = menu();
switch(choice)
{

case 1:
       value = 0;
       printf("Press -1 to exit \n");
       while(value != -1)
       {
        printf("Enter the elements \n");
        scanf("%d",&value);
        if(value != -1)
        {
            head1 = insert(head1,value);
        }
      }
       break;

case 2:
       copy(head1);
       break;

case 3:
       head2 = NULL;
       value = 0;
       printf("Press -1 to exit \n");
       while(value != -1)
       {
        printf("Enter the elements \n");
        scanf("%d",&value);
        if(value != -1)
        {
            head2 = insert(head2,value);
        }
      }
      concatenate(head1,head2);
		break;

case 4:
       element = 0;
       printf("Enter the elements \n");
       scanf("%d",&element);
      split(head1,element);
      break;

case 5:
    reverse(head1);
    break;

case 6:
    count(head1);
    break;
}
}while (choice!=7);
}
