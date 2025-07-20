#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int cnt[8005];

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}

	int average = round((double)sum / n);
	int mid = arr[n / 2];

	int mostCnt = 0;
	for (int i = 0; i < 8005; i++)
	{
		if (cnt[i] > mostCnt)
		{
			mostCnt = cnt[i];
		}
	}

	int most = 0;
	int count = 0;
	for (int i = 0; i < 8005; i++)
	{
		if (cnt[i] == mostCnt)
		{
			most = i - 4000;
			count++;
			if (count == 2)
				break; // 두 번째로 작은 최빈값
		}
	}

	int range = arr[n - 1] - arr[0];

	printf("%d\n%d\n%d\n%d\n", average, mid, most, range);

	free(arr);
	return 0;
}
