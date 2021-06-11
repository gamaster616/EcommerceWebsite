#include<stdio.h>

 #include<stdlib.h>

 struct ll_node

 {

 int data;

 struct ll_node *next;

 struct ll_node *prev;

 };
struct ll_node *head = NULL;


struct ll_node* insert(struct ll_node *list,int value)

 {

 struct ll_node *help_ptr = list;

 struct ll_node *pnew = (struct ll_node *)malloc(sizeof(struct ll_node));

 pnew->data = value;

 pnew->next = NULL;

 pnew->prev=NULL;


 if(list == NULL || list->data>value)

 {

 pnew->next = list;

 list = pnew;

 list->prev=pnew;


 printf("Node has been added!\n");

 return list;

 }

else

 {

 while(help_ptr->next != NULL && help_ptr->next->data < value)

 help_ptr = help_ptr->next;
pnew->next = help_ptr->next;

 if(help_ptr->next!=NULL)

 (pnew->next)->prev=pnew;

 help_ptr->next = pnew;

 pnew->prev=help_ptr;


 printf("Node has been added!\n");

 return list;

 }

 }

struct ll_node *searchNode(int value)
{
struct ll_node* list = head->next;
while(list != head)
{
if(list->data == value)
return list;
if(list->data < value)
list = list->next;
else
break;
}
return NULL;
}

 void display(struct ll_node *list)

 {

 struct ll_node *help_ptr = list;

 while(help_ptr != NULL)

 {

 printf("%d\n",help_ptr->data);

 help_ptr = help_ptr->next;

 }

 }

 struct ll_node* Delete(struct ll_node *list,int value)

 {

 struct ll_node *help_ptr=list,*tobedeleted;

 if(help_ptr != NULL)

 {

 if(help_ptr->data == value)

 {

 list = help_ptr->next;

 if(help_ptr->next!=NULL)

 list->prev=NULL;

 free(help_ptr);

 printf("\nNode has been deleted!\n");

 return list;

 }

 while(help_ptr->next != NULL)

 {

 if(help_ptr->next->data == value)

 {

 tobedeleted = help_ptr->next;


 help_ptr->next = tobedeleted->next;

 if(tobedeleted->next!=NULL)

 (tobedeleted->next)->prev=help_ptr;

 free(tobedeleted);

 printf("\nNode has been deleted!\n");

 return list;

 }

 help_ptr=help_ptr->next;

 }

 }

 printf("Node not found!\n");

 return list;

 }

void main()

 {

 int arr[100],n,choice,num,ll_flag =0;

 struct ll_node *myList = NULL;

 do

 {

 printf("1.Add nodes\n2.Delete a node\n3.Display List\n4.Search\n5.EXIT\n");

 scanf("%d",&choice);

 if(choice == 1)

 {

 printf("Enter the number you want to insert :");

 scanf("%d",&num);

 myList = insert(myList,num);

 }

 else if(choice == 2)

 {

 printf("Enter the number you want to delete :");

 scanf("%d",&num);

 myList = Delete(myList,num);

 }

 else if(choice == 3)

 {

 printf("\n-------------------\n");

 display(myList);

 printf("\n-------------------\n");

 }
 else if(choice==4)
 {
     printf("Enter the value to be searched: ");
     scanf("%d",&num);
     searchNode(num);
 }


}while(choice != 5);

 }
