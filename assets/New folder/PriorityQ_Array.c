//5. Implementation of Priority queue (taking care of priority while deletion) program using array
#include <stdio.h>
#define N 5
int Que[N],Pri[N];
int rear=-1,front=-1;
void enqueue(int data,int p)
{
	int i;
	if((front==0)&&(rear==N-1))
		printf("Queue is full");
	else
	{
		if(front==-1)
		{
			front=rear=0;
			Que[rear]=data;
			Pri[rear]=p;
		}
		else if(rear==N-1)
		{
			for(i=front;i<=rear;i++)
                {
                    Que[i-front]=Que[i];
                    Pri[i-front]=Pri[i];
                    rear=rear-front;
                    front=0;
        for(i = rear;i>front;i--)
				{
					if(p>Pri[i])
					{
						Que[i+1]=Que[i];
						Pri[i+1]=Pri[i];
					}
					else
                    break;
					Que[i+1]=data;
					Pri[i+1]=p;
					rear++;
				}
			}
		}
		else
		{
			for(i=rear;i>=front;i--)
			{
				if(p>Pri[i])
				{
					Que[i+1]=Que[i];
					Pri[i+1]=Pri[i];
				}
                else
                break;
			}
			Que[i+1]=data;
			Pri[i+1]=p;
			rear++;
		}
	}
}
void display()
{
int i;
	for(i=front;i<=rear;i++)
	{
		printf("\nElement = %d\tPriority = %d",Que[i],Pri[i]);
	}
}
int dequeue()
{
	if(front==-1)
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("deleted Element = %d\t Its Priority = %d",Que[front],Pri[front]);
		if(front==rear)
			front=rear=-1;
		else
			front++;
	}
}
int main()
{
	int ch,n,i,data,p;
	do{
        printf("\nPRIORITY QUEUE MENU ");
		printf("\n1 INSERT \n2 DISPLAY \n3 DELETE \n0 EXIT");
		printf("\nEnter Your Choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the number of data");
				scanf("%d",&n);
				printf("\nEnter your data and Priority of data");
				i=0;
				while(i<n){
					scanf("%d %d",&data,&p);
					enqueue(data,p);
					i++;
				}
				break;
			case 2:
				display();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
		}
	}while(ch!=0);
    return 0;
}
