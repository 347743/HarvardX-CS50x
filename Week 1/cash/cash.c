#include <cs50.h>
#include <stdio.h>

int cal_q(int cents);
int cal_d(int cents);
int cal_n(int cents);
int cal_p(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Changed owed: ");
    }
    while (cents < 0);

    int q = cal_q(cents);
    cents = cents - (q * 25);

    int d = cal_d(cents);
    cents = cents - (d * 10);

    int n = cal_n(cents);
    cents = cents - (n * 5);

    int p = cal_p(cents);
    cents = cents - (p * 1);

    int cash = q + d + n + p;
    printf("%d\n", cash);
}
int cal_q(int cents)
{
    int q = 0;

    while (cents >= 25)
    {
        q++;
        cents = cents - 25;
    }
    return q;
}
int cal_d(int cents)
{
    int d = 0;
    while (cents >= 10)
    {
        d++;
        cents = cents - 10;
    }
    return d;
}
int cal_n(int cents)
{
    int n = 0;
    while (cents >= 5)
    {
        n++;
        cents = cents - 5;
    }
    return n;
}
int cal_p(int cents)
{
    int p = 0;
    while (cents >= 1)
    {
        p++;
        cents = cents - 1;
    }
    return p;
}
