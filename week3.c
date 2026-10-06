#include<stdio.h>
#define max 5
int front=-1;
int rear =-1;
int queue[max];
void enqueue(int data)
{
    if(rear==max-1)
    {
        printf("\nQueue is full !!\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=data;
}
int dequeue()
{
    int item;
    if((front==-1)||(front>rear))
    {
        printf("\nQueue is empty !!\n");
        return 0;
    }
    item=queue[front];
    front++;
    printf("\nDeleted item is %d\n",item);
}
void display()
{
    if((front==-1)||(front>rear))
    {
        printf("\nQueue is empty !!\n");
        return;
    }
    printf("\nQueue elements\n");
    for(int i=front;i<=rear;i++)
    {
            printf("%d\n",queue[i]);
    }

}
void main()
{
    int choice;
    int end;
    do
    {
        printf("\n1 for enqueue\n2 for dequeue\n3 for display\n4 for exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                int data;
                printf("enter the element:");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("---Exited---");
                end=-1;
                break;
        }
    }while(end!=-1);
}
