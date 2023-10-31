//|ADMIRAL AUDITORE|//
#include<stdio.h>
#include<stdlib.h>
void sort(int *p,int *n)
{
    for (int i = 0; i < *n - 1;i++)
        for (int j = i + 1; j < *n;j++)
            if(*(p+i)>*(p+j))
            {
                int temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
}
int main()
{
    int *n = (int *)malloc(1 * sizeof(int));
    scanf("%d", n);
    int *p = (int *)malloc(*n * sizeof(int));
    for (int i = 0; i < *n;i++)
        scanf("%d", (p + i));

    sort(p, n);
    for (int i = 0; i < *n; i++)
        printf("%d ", *(p + i));
}