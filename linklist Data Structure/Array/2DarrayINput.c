#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row, collum, i, j;
    printf("enter the row and collum:");
    scanf("%d %d", &row, &collum);
    int arr[row][collum];
    printf("enter the array through rows: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < collum; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < collum; j++)
        {
            // printf("%d", arr[i][j]);

            printf("%d", *(*(arr + i) + j));
            printf(" ");
        }
        printf("\n\n");
    }

    return 0;
}
