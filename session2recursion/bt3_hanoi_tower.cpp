
// void move(int n, char a, char b, char c): di chuyen n dia tu cot
// a sang cot c lay b lam trung gian
#include <stdio.h>

void move(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("Move 1 disk from %c to %c\n", a, c);
    }
    else
    {
        move(n - 1, a, c, b);
        move(1, a, b, c);
        move(n - 1, b, a, c);
    }
}

int main()
{
    move(3, 'A', 'B', 'C');
    return 0;
}
1