#include <stdio.h>

int main(void)
{
	int num1;
	int i;
	int cntarr[10000] = { 0, };
	int input;
	scanf("%d", &num1);

	for (i = 0; i < num1; i++)
	{
		scanf("%d", &input);
		cntarr[input - 1]++;
	}

	for (i = 0; i < 10000; i++)
	{
		while (cntarr[i] > 0)
		{
			printf("%d\n", i + 1);
			cntarr[i]--;
		}
	}

	return (0);
}
