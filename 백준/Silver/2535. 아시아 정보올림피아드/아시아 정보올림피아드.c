#include <stdio.h>
#include <stdlib.h>
#define ll long long

typedef struct student
{
    int country, number, score;
} student;

student *arr;
int n;

int compare(const void *a, const void *b)
{
    if (((student *)a)->score < ((student *)b)->score)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int ratio[105];

int main()
{
    scanf("%d", &n);
    arr = (student *)malloc(sizeof(student) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &arr[i].country, &arr[i].number, &arr[i].score);
    }
    qsort(arr, n, sizeof(student), compare);
    int cnt = 0;
    for (int i = 0; i < n & cnt < 3; i++)
    {
        int nowCountry = arr[i].country;
        if (ratio[nowCountry] >= 2)
            continue;
        ratio[nowCountry]++;
        printf("%d %d\n", arr[i].country, arr[i].number);
        cnt++;
    }

    free(arr);
    return 0;
}