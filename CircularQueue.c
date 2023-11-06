#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define size 3
int front=-1;int rear=-1;
int print=0;

int arr[size];
void deque(){
    if (front && rear==-1){
            printf("Queue is empty\n");

    }
    else if(front==rear){
            arr[front]=0;
        front=-1;rear=-1;

    }
    else{
        printf("%d",arr[front]);
        arr[front]=0;
        front++;
        front=front%size;



    }
}
void enque(int temp){
if((rear+1)%size == front){
    printf("Queue is  full\n");
}
else if(front && rear==-1){
    front++;rear++;
    arr[front]=temp;
}
else{
    rear++;
    rear=rear%size;
    arr[rear]=temp;
}
}
void display(){
    if(front && rear ==-1){
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=front; i<size; (i++)%size)
        {
            if(i==rear)
            {
                printf("%d ",arr[i]);
                break;
            }
            else
                printf("%d ",arr[i]);
        }
    }
}
void main()
{
   int option,in=0;

   while(1)
    {
        printf("\nQueue Menu\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the no. : ");
                scanf("%d",&in);
                enque(in);
                break;
            case 2:
                deque();
                break;

            case 3:
                display();
                printf("\n");
                break;
            case 4:
                exit(0);
        }

    }

}

