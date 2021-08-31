#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} * head;
void creat(int num)
{
    head = 0;
    struct node *newnod, *temp;
    for (size_t i = 0; i < num; i++)
    {
        newnod = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnod->data);
        newnod->next = 0;
        if (head == 0)
        {
            head = temp = newnod;
        }
        else
        {
            temp->next = newnod;
            temp = newnod;
        }
    }
    newnod->next = head;
}
void display()
{
    struct node *temp;
    temp = head;
    printf("\nthe circular linklist is: \n");
    while (temp->next != head)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d, ", temp->data);
}

void deleteDuplicatfromUNsorting()
{
    struct node *current = head, *index = 0, *temp = 0;
    if (head == 0)
    {
        printf("List is empty");
    }
    else
    {
        do
        {
            //Temp will point to previous node of index.
            temp = current;
            //Index will point to node next to current
            index = current->next;
            while (index != head)
            {
                //If current node is equal to index data
                if (current->data == index->data)
                {
                    temp->next = index->next;
                }
                else
                {
                    //Temp will point to previous node of index.
                    temp = index;
                }
                index = index->next;
            }
            current = current->next;
        } while (current->next != head);
    }
}
    int main()
    {
        int n;
        printf("how many number you want to enter in crcular linklist: ");
        scanf("%d", &n);
        creat(n);
        display();
        printf("\ndelete duplicat from unsorting circular linklist:\n ");
        deleteDuplicatfromUNsorting();
        printf("\nsorry\n");
        display();

        return 0;
    }