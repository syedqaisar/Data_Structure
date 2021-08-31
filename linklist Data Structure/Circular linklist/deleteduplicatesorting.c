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
void sortingcll()
{
    struct node *temp, *check;
    check = tail->next;
    while (check != tail)
    {
        temp = check->next;
        while (temp != tail->next)
        {
            if (check->data > temp->data)
            {
                int tempdata = check->data;
                check->data = temp->data;
                temp->data = tempdata;
            }
            temp = temp->next;
        }
        check = check->next;
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
void deleteDuplicatfromSorting()
{
    struct node *temp, *nextnode, *delete;
    do
    {
        temp = tail->next;
        nextnode = temp->next;
        if (temp->data == nextnode->data)
        {
            delete = nextnode;
            nextnode = nextnode->next;
            free(delete);
            continue;
        }
        temp = temp->next;
        nextnode = nextnode->next;

    } while (temp != tail);
}
int main()
{
    int n;
    printf("how many number you want to enter in crcular linklist: ");
    scanf("%d", &n);
    creat(n);
    display();
    printf("\nAfter sorting the circular linklist is: ");
    sortingcll();
    display();
    printf("\nAfter deleting the duplicate element from sorted Cll");
    deleteDuplicatfromSorting();
    display();

    return 0;
}