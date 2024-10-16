#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#define MAX 5
int top=-1,stack[MAX];
void push();
void pop();
void display();

int main()
{   int ch;
    printf("Stack as Array");
    printf("\nMenu\n1.PUSH\n2.POP\n3.DISPLAY\n4.Quit\n");
    while(1)
    {
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
void push()
{
    int val;
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else
        printf("Enter the Value to push into stack\n");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
}
void pop()
{
    if(top==-1)
        printf("Stack Underflow\n");
    else
        printf("value popped: %d\n",stack[top]);
        top=top-1;

}
void display()
{
    int i;
    if(top==-1)
    {
         printf("Stack Underflow\n");
    }
    else
    {   for(i=top;i>=0;i--)
        {
           printf("\nstack[%d]=%d",i,stack[i]);
        }
    }

}
