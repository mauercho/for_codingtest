#include <stdio.h>

int calculate(int num)
{
    int x;
    int cnt;
    int sum;

    cnt = 1;
    x = 6;
    sum = 1 + x;
    while (1)
    {
        if (num <= sum)
        {
            break;
        }
        x += 6;
        sum += x;
        cnt++;
    }
    return (cnt + 1);
}

int main()
{
    int input;
    int i = 1;
    int cnt = 1;
    scanf("%d", &input);
    if (input == 1)
    {
        printf("%d", i);
        return (0);
    }
    i = calculate(input);
    printf("%d", i);
    return (0);
}