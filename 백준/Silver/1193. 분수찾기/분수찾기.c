#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	int r;
	for (r = 1;; r++)
	{
		if ((r + 1) * r / 2 >= x)
		{
			break;
		}
	}
	int i = x - r * (r - 1) / 2;
	int j = r + 1 - i;
	if (r % 2)
	{
		printf("%d/%d\n", j, i);
	}
	else
	{
		printf("%d/%d\n", i, j);
	}

	return 0;
}