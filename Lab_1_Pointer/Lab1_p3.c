//|ADMIRAL AUDITORE|//
#include<stdio.h>
#include<stdlib.h>
void delete(int *p,int *n)
{
    for (int i = 0; i < *n - 1;i++)
        if(*(p+i)<0)
        {
            for (int j = i + 1; j < *n; j++)
                *(p + j-1) = *(p + j);
            //*n = *n - 1;
            (*n)--;
        }
    if(*(p+(*n-1)<0)
    {
        *(p + *n) = 0;
        (*n)--;
    }
}
int main()
{
    int *n = (int *)malloc(1 * sizeof(int));
    scanf("%d", n);
    int *p = (int *)malloc(*n * sizeof(int));
    for (int i = 0; i < *n;i++)
        scanf("%d", (p + i));
    for (int i = 0; i < *n; i++)
        printf("%d ", *(p + i));
    printf("\n");
    delete (p, n);
    for (int i = 0; i < *n; i++)
        printf("%d ", *(p + i));
}
