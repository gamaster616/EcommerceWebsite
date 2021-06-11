// Implementations of Breadth First Search (BFS) program using queue (linked list) and adjacency matrix.

#include<stdio.h>
#include<stdlib.h>  
#define len 20

struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front=0;  
struct node *rear=0;  

int array[len][len];
int vi[len];

void insert(int new)
{
    struct node *ptr;  
    ptr = (struct node *) malloc (sizeof(struct node));  
        ptr -> data = new;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }
}

int delete()
{
    int t;
    struct node *ptr;  
    if(front == NULL)  
    {  
        return 0;  
    }  
    else   
    {  
        ptr = front;
        t=ptr->data;
        front = front -> next;  
        free(ptr);  
    }
    return t;
}

void bfs(int s, int n)
{
    int p,i,j;
    insert(s);
    vi[s]=1;
    p=delete();
    if(p!=0)
        printf("%4d",p);
    while(p!=0)
    {
        for(i=1;i<=n;i++)
            if(array[p][i]!=0 && vi[i]==0)
            {
                insert(i);
                vi[i]=1;
            }
        p=delete();
        if(p!=0)
            printf("%4d",p);
    }
    for(j=1;j<=n;j++)
        if(vi[j]==0)
        {
            front--;
            bfs(j,n);
        }
}

void main()
{
    int v,e,i,j,k,l,n;
    printf("--------BREADTH FIRST SEARCH(using adjency matrix)--------");
    printf("\nEnter Number Of VERTICES: ");
    scanf("%d",&v);
    printf("Enter Number Of EDGES: ");
    scanf("%d",&e);
    for(i=1;i<=v;i++)
        vi[i]=0;
    for(i=1;i<=v;i++)
        for(l=1;l<=v;l++)
            array[i][l]=0;
    for(i=1;i<=e;i++)
    {
        printf("Enter Pair Of VERTICES:\n");
        scanf("%d%d",&j,&k);
        array[j][k]=array[k][j]=1;
    }
    for(i=1;i<=v;i++)
    {
        for(l=1;l<=v;l++)
            printf("%4d",array[i][l]);
        printf("\n");
    }
    printf("\nSOURCE NODE: ");
    scanf("%d",&n);
    bfs(n,v);
    printf("\n");
}