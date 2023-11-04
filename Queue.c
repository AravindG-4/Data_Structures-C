#include<stdio.h>
#include<conio.h>
int front=-1;int rear=-1;
int size=3;
int arr[3];
void deque(){
    if (front && rear==-1){
            printf("Queue is empty\n");

    }
    else if(front==rear){
        front=-1;rear=-1;
        arr[front]=0;
    }
    else{
        printf("%d",arr[front]);

        front++;

    }
}
void enque(int temp){
if(rear==size-1){
    printf("Queue is  full\n");
}
else if(front&& rear==-1){
    front++;rear++;
    arr[front]=temp;
}
else{
    rear++;
    rear=rear;
    arr[rear]=temp;
}
}
void display(){
    if(front && rear ==-1){
        printf("Queue is empty\n");
    }
    else{
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
    }
}

int main()
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


