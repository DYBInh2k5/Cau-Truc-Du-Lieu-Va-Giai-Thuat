//tính giá trị biểu thức hậu tố
#include <stdio.h>
#include <ctype.h>
#include "stack2.h"
#include <stdlib.h>

double calculate(int num1, int num2, char token)
{
    switch (token)
    {
    case '+':
        return num2 + num1;
    case '-':
        return num2 - num1;
    case '*':
        return num2 * num1;
    case '/':
        return (double)num2 / num1;
    default:
        return 0;
    }
}

double evaluate(char *postfix)
{
    STACK s;
    initialize(s);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            char t[2];
            sprintf(t, "%c", postfix[i]);
            push(s, atoi(t));
        }
        else
        {
            int num1;
            pop(s, num1);
            int num2;
            pop(s, num2);
            push(s, calculate(num1, num2, postfix[i]));
        }
    }
    int r;
    pop(s, r);
    return r;
}

int main()
{
    char *c = "23+5*921+/-";
    double x = evaluate(c);
    printf("%f", x);
}