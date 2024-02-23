#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    int top;
    int stack[MAX_SIZE];
} Stack;

void push(Stack *s, int item)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->stack[++(s->top)] = item;
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[(s->top)--];
}

int evaluate(char *expression)
{
    Stack s;
    s.top = -1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            push(&s, expression[i] - '0');
        }
        else
        {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (expression[i])
            {
            case '+':
                push(&s, operand1 + operand2);
                break;
            case '-':
                push(&s, operand1 - operand2);
                break;
            case '*':
                push(&s, operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0)
                {
                    printf("Division by zero\n");
                    exit(1);
                }
                push(&s, operand1 / operand2);
                break;
            default:
                printf("Invalid operator\n");
                exit(1);
            }
        }
    }

    return pop(&s);
}

int main()
{
    char expression[MAX_SIZE];
    printf("Enter the postfix expression: ");
    fgets(expression, MAX_SIZE, stdin);

    // Remove newline character from fgets
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluate(expression);
    printf("Result: %d\n", result);

    return 0;
}
