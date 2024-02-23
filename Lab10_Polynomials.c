#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coeff;
    int expo;
    struct node *ptr;
};
struct node *head1, *head2, *head3, *temp, *temp1, *temp2, *temp3, *list1, *list2, *list3, *list;
struct node *dummy1, *dummy2, *dummy3;
struct node *create_poly(i nt,
 int, struct node *);
// void create_poly2(int , int);
void display(struct node *);
void add_poly();
void eval_poly(int);
int n, ch;
int c, e, i;
void main()
{
    int x;
    list1 = list2 = list3 = NULL;
    printf("1.Create first polynomial\n2.Create Second Polynomial\n3.Display both the polynomials\n");
    printf("4.Add Polynomials\n5.Evaluate a Polynomial\n6.Exit\n");
    while (1)
    {
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of terms\n");
            scanf("%d", &n);
            printf("Enter coefficient & power of each term\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d%d", &c, &e);
                list1 = create_poly(c, e, list1);
            }
            break;
        case 2:
            printf("Enter the number of terms\n");
            scanf("%d", &n);
            printf("Enter coefficient & power of each term\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d%d", &c, &e);
                list2 = create_poly(c, e, list2);
            }
            break;
        case 3:
            display(list1);
            display(list2);
            break;
        case 4:
            add_poly();
            display(list3);
            exit(0);
            break;
        case 5:
            printf("Enter the value for x\n");
            scanf("%d", &x);
            eval_poly(x);
            break;
        case 6:
            exit(0);
        }
    }
}
struct node *create_poly(int c, int e, struct node *list)
{
    if (list == NULL)
    {
        dummy1 = (struct node *)malloc(1 * sizeof(struct node));
        dummy1->coeff = 0;
        dummy1->expo = 0;
        dummy1->ptr = list1;
        list = (struct node *)malloc(1 * sizeof(struct node));
        list->coeff = c;
        list->expo = e;
        // list1->ptr=list1;
        head1 = list;
        head1->ptr = dummy1;
    }
    else
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        temp->coeff = c;
        temp->expo = e;
        head1->ptr = temp;
        temp->ptr = dummy1;
        head1 = temp;
    }
    return list;
}
void add_poly()
{
    if (list3 == NULL)
    {
        dummy3 = (struct node *)malloc(1 * sizeof(struct node));
        dummy3->coeff = 0;
        dummy3->expo = 0;
        dummy3->ptr = list3;
        temp1 = list1;
        temp2 = list2;
    }
    while ((temp1->coeff != 0) && (temp2->coeff != 0))
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        if (list3 == NULL)
        {
            list3 = temp;
            head3 = list3;
        }
        if (temp1->expo == temp2->expo)
        {
            temp->coeff = temp1->coeff + temp2->coeff;
            temp->expo = temp1->expo;
            head3->ptr = temp;
            head3 = temp;
            head3->ptr = dummy3;
            // head3=temp;
            temp1 = temp1->ptr;
            temp2 = temp2->ptr;
        }
        else if (temp1->expo > temp2->expo)
        {
            temp->coeff = temp1->coeff;
            temp->expo = temp1->expo;
            head3->ptr = temp;
            head3 = temp;
            head3->ptr = dummy3;
            // head3->ptr=temp;
            // head3=temp;
            temp1 = temp1->ptr;
        }
        else
        {
            temp->coeff = temp2->coeff;
            temp->expo = temp2->expo;
            // temp->ptr=list3;
            head3->ptr = temp;
            head3 = temp;
            head3->ptr = dummy3;
            // head3=temp;
            temp2 = temp2->ptr;
        }
    }
    if (temp1->coeff == 0)
    {
        while (temp2->coeff != 0)
        {
            temp = (struct node *)malloc(1 * sizeof(struct node));
            temp->coeff = temp2->coeff;
            temp->expo = temp2->expo;
            head3->ptr = temp;
            head3 = temp;
            head3->ptr = dummy3;
            // head3=temp;
            temp2 = temp2->ptr;
        }
    }
    if (temp2->coeff == 0)
    {
        while (temp1->coeff != 0)
        {
            temp = (struct node *)malloc(1 * sizeof(struct node));
            temp->coeff = temp1->coeff;
            temp->expo = temp1->expo;
            head3->ptr = temp;
            head3 = temp;
            head3->ptr = dummy3;
            // head3=temp;
            temp1 = temp1->ptr;
        }
    }
}
void display(struct node *list)
{
    temp = list;
    printf("\nPOLYNOMIAL:");
    while (temp->coeff != 0)
    {
        printf("%dX^%d+", temp->coeff, temp->expo);
        temp = temp->ptr;
    }
    printf("\b ");
}
void eval_poly(int x)
{
    int result = 0;
    temp1 = list1;
    temp2 = list2;
    while (temp1->coeff != 0)
    {
        result += (temp1->coeff) * pow(x, temp1->expo);
        temp1 = temp1->ptr;
    }
    printf("Polynomial 1 Evaluation:%d\n", result);
    result = 0;
    while (temp2->coeff != 0)
    {
        result += (temp2->coeff) * pow(x, temp2->expo);
        temp2 = temp2->ptr;
    }
    printf("Polynomial 2 Evaluation: %d \n", result);
}