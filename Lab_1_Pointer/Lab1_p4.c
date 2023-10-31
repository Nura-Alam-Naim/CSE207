#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct std
{
    char name[50];
    char id[20];
    float cgpa;
};
int main()
{
    printf("Enter the number of students: ");
    int *n = (int *)malloc(sizeof(int));
    scanf("%d", n);
    int *max = (int *)malloc(sizeof(int));
    *max = -1;
    struct std *p = (struct std *)malloc(*n * sizeof(struct std));
    struct std *m = ((struct std *)malloc(sizeof(struct std)));
    for (int i = 0; i < *n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", (p + i)->name);
        printf("ID: ");
        scanf("%s", (p + i)->id);
        printf("CGPA: ");
        scanf("%f", &(p + i)->cgpa);
        
        if(*max< (p+i)->cgpa)
            m = (p + i);
    }
    printf("\nAll student: \n");
    for (int i = 0; i < *n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", (p + i)->name);
        printf("ID: %s\n", (p + i)->id);
        printf("CGPA: %.2f\n\n", (p + i)->cgpa);
    }
    printf("\nBest Stundent: \n");
    printf("Nams: %s\n",m->name);
    printf("ID: %s\n", m->id);
    printf("CGPA: %.2f\n", m->cgpa);
    return 0;
}
