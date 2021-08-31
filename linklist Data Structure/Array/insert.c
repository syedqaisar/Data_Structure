#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, *ptr, update, entry, j, num, x;
    int a[3];
    ptr = a;
    printf("how many number yoou want in array:");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    int size = sizeof(a);
    printf("%d", size);
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", (ptr + i));
    // }
    // printf("the orignal array is: \n");
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d, ", *(ptr + i));
    // }
    // printf("enter the update expanded siza:\n");
    // scanf("%d", &update);
    // update = n + update;
    // ptr = (int *)realloc(ptr, update * sizeof(int));
    // printf("\nIn which place you want to update the array");
    // scanf("%d", &entry);
    // // for (j = 1; j < update - n; j++)
    // // {
    // for (i = update - 1; i >= entry; i--)
    // {
    //     *(ptr + (n-1)) = *(ptr + n);
    //     n--;
    // }
    // // }
    // x = update - entry - 1;
    // // for (i = entry; i <= x; i++)
    // // {
    // scanf("%d", &num);
    // *(ptr + entry) = num;
    // // entry++;
    // // }

    // printf("after update the array is: \n");
    // for (i = 0; i < update; i++)
    // {
    //     printf("%d, ", *(ptr + i));
    // }
    free(ptr);
    return 0;
}
