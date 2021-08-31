#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *top = 0;

void posh()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data in stack: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

void pop()
{
    if (top == 0)
        printf("\nunderflow condition:");
    else
    {
        struct node *delete;
        delete = top;
        top = top->next;
        printf("\nthe pop iterm is; %d \n", delete->data);
        free(delete);
    }
}

void peek()
{
    if (top == 0)
    {
        printf("\nthe stack is empty. ");
    }
    else
    {
        printf("\nthe element is: %d", top->data);
    }
}
void display()
{
    if (top == 0)
        printf("\nthe stack is empty. ");
    else
    {
        struct node *temp;
        temp = top;
        while (temp != 0)
        {
            printf("%d, ", temp->data);
            temp = temp->next;
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