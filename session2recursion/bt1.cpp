
// Tính lũy thừa: power(a,n)
// a: số thực khác 0
// n: số nguyên >= 0
#include <stdio.h>

double power(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, n - 1);
    }
}

int main()
{
    printf("power(5,3) = %.2lf\n", power(5, 3));
    return 0;
}
1