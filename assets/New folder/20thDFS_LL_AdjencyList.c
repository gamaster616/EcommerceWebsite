#include <stdio.h>

#include <stdlib.h>

#define SIZE 50

int vn[SIZE];

int queue[SIZE];

int v, e, i;

int front = -1;

int rear = -1;

struct graph

{

    int vertex;

    struct graph *next;
};

struct graph *a[SIZE];

void enqueue(int element)

{

    if (rear == SIZE - 1)

    {

        printf("Queue full\n");
    }

    else

    {

        queue[++rear] = element;
    }

    return;
}

int dequeue()

{

    int x;

    x = queue[++front];

    if (front == -1 && rear == -1)

    {

        printf("Queue empty");

        return 0;
    }

    //queue[front] = 0;

    return x;
}

struct graph *createGraph(struct graph *root, int n)
{
    struct graph *ptr = (struct graph *)malloc(sizeof(struct graph));
    ptr->vertex = n;
    ptr->next = root;
    root = ptr;
    return root;
}

void bfs(int q, int n)
{
    int p, i, j;
    enqueue(q);
    vn[q] = 1;
    p = dequeue();
    if (p != 0)
    {
        printf("%d\t", p);
    }
    while (p != 0)
    {
        while (a[p] != NULL && vn[a[p]->vertex] == 0)
        {
            enqueue(a[p]->vertex);
            vn[a[p]->vertex] = 1;
            a[p] = a[p]->next;
        }
        p = dequeue();
        if (p != 0)
        {
            printf("%d\t", p);
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (vn[j] == 0)
        {
            front--;
            bfs(j, n);
        }
    }
}

void main()
{
    int j, k, l, n, m;
    struct graph *hp;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (i = 1; i <= v; i++)
    {
        vn[i] = 0;
    }
    for (i = 1; i <= v; i++)
    {
        a[i] = NULL;
    }
    for (i = 1; i <= e; i++)
    {
        printf("Enter pair of vertices: \n");
        scanf("%d%d", &j, &k);
        a[j] = createGraph(a[j], k);
        a[k] = createGraph(a[k], j);
    }
    printf("Adjacent List: ");
    for (i = 1; i <= v; i++)
    {
        hp = a[i];
        printf("\n");
        //printf("%d -> ",i);
        while (hp != NULL)
        {
            printf("%d -> ", hp->vertex);
            hp = hp->next;
        }
    }
    printf("\nEnter the source: ");
    scanf("%d", &n);
    bfs(n, v);
}