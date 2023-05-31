#include<stdio.h>
#define N 5 
int queue[N];
int front = -1;
int rear = -1;
                         // Linear queue
void enqueue(int x)
{
    if(rear == N-1)                      //full
    {
        printf("\nOverflow\n");
    }
    else if(front == -1 && rear == -1)   //empty
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else if(front == rear)      // only one element in queue
    {
        front = rear = -1;      // after deleting this one element queue is empty
    }
    else
    {
        printf("The dequeued element from the queue is %d.\n",queue[front]);
        front++;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        for(int i=front; i<=rear; i++)
        {
           printf("%d\t",queue[i]);  
        }
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Data at front is %d.\n",queue[front]);
    }
}

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    dequeue();
    dequeue();
    dequeue();
    peek();
    display();
    enqueue(10);
    return 0;
}