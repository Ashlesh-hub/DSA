#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct day
{
    char *name;
    int date;
    char *description;
};
void create(struct day calendar[7])
{
    for(int i=0;i<7;i++)
    {
        calendar[i].name = (char *)malloc(50 * sizeof(char));
        calendar[i].description = (char *)malloc(100 * sizeof(char));
    }
}
void read(struct day calendar[7])
{
    for (int i = 0; i < 7; i++)
    {
        printf("Enter the name for the day %d: ", i+1);
        scanf("%49s", calendar[i].name);
        printf("Enter the date for the day %d: ", i+1);
        scanf("%d", &calendar[i].date);
        printf("Enter the description for the day %d:\n", i+1);
        scanf("%99s", calendar[i].description);
    }
    
}
void display(struct day calendar[7])
{
    for (int i = 0; i < 7; i++)
    {
        printf("Day name: %s \n", calendar[i].name);
        printf("Date: %d\n", calendar[i].date);
        printf("Description:%s\n\n", calendar[i].description);
        printf("\n");
    }
    
}
int main()
{
    struct day calendar[7];
    create(calendar);
    read(calendar);
    printf("Weekly planner:\n");
    display(calendar);
    for (int i = 0; i < 7; i++)
    {
        free(calendar[i].name);
        free(calendar[i].description);
    }
    return 0;
}
