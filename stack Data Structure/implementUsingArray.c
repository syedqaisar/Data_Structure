#include <stdio.h>
#define N 5
int stack[N];
int top = -1;

void posh()
{
    int data;
    if (top >= 4)
    {
        printf("overflow condition");
    }
    else
    {
        printf("enter the data:\n ");
        scanf("%d", &data);
        top++;
        stack[top] = data;
    }
}

void pop()
{
    int popitem;
    if (top == -1)
    {
        printf("underflow condition occur. \n");
    }
    else
    {
        popitem = stack[top];
        top--;
        printf("\nthe pop element is: %d", popitem);
    }
}
void peek()
{
    int popitem;
    if (top == -1)
    {
        printf("the stack is empty. \n");
    }
    else
    {
        popitem = stack[top];
        printf("\nthe element is: %d", popitem);
    }
}
void display()
{
    int i;
    if (top == -1)
        printf("\nthe stack is empty: \n");
    else
    {
        printf("\nthe stack is: \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d, ", stack[i]);
        }
    }
}
int main()
{
    int number;
    do
    {
        printf("\nenter the number:- 1:push, 2:pop, 3:peek, 4:display, 0:exit ");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            posh();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("invalid number");
            break;
        }
    } while (number != 0);
}