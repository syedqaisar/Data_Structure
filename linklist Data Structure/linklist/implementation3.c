#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *new, *temp;
    head = 0;
    int n = 1, i;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &new->data);
        new->next = 0;
        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
    }

    temp = head;
    printf("the given linklist is:");
    while (temp != 0)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    return 0;
}