#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} * tail;
void creat(int num)
{
    tail = 0;
    struct node *newnod, *temp;
    for (size_t i = 0; i < num; i++)
    {
        newnod = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnod->data);
        newnod->next = 0;
        if (tail == 0)
        {
            tail = newnod;
            tail->next = newnod;
        }
        else
        {
            newnod->next = tail->next;
            tail->next = newnod;
            tail = newnod;
        }
    }
}
void display()
{
    struct node *temp;
    temp = tail;
    printf("\nthe circular linklist is: \n");
    while (temp->next != tail)
    {
        printf("%d, ", temp->next->data);
        temp = temp->next;
    }
    printf("%d, ", temp->next->data);
}

int main()
{
    int n;
    printf("how many number you want to enter in crcular linklist: ");
    scanf("%d", &n);
    creat(n);
    display();

    return 0;
}