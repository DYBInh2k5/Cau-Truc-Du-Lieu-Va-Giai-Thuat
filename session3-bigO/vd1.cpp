/**
Ví dụ:
f(n) = 2n2 + 3n + 5;
g(n) = n2
f(n) ≤ 2n2 + 3n2 + 5n2, với mọi n ≥ 1
f(n) ≤ 10n2 = 10.g(n), với mọi n ≥ 1
Ta viết: f(n) = O(g(n)) = O(n2)
*/

int sum(int n)
{
int s = 0; // O(1)
for (int i = 1; i <= n; i++) // n lần
s += i; // O(1)
return s; // O(1)
}
▪ f(n) = O(1) + n.O(1) + O(1)
= n.O(1) + 2.O(1)
= a.n + b (đặt a = O(1), b = 2.O(1))
= O(n)