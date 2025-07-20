#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

typedef struct
{
    char name[51];
    int cnt;
} book;

int compare(const void *a, const void *b)
{
    if (strcmp(((book *)a)->name, ((book *)b)->name) > 0)
    {
        return 1;
    }
    else
        return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    book b[1000];
    int total = 0;

    char str[51];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        b[i].cnt = 0;
        if (i == 0)
        {
            strcpy(b[i].name, str);
            total++;
        }
        else
        {
            int j = 0, flag = 0;
            for (; j < i; j++)
            {
                if (strcmp(str, b[j].name) == 0)
                {
                    flag = 1;
                    b[j].cnt++;
                    break;
                }
            }
            if (flag == 0)
            {
                strcpy(b[j].name, str);
                total++;
            }
        }
    }
    qsort(b, total, sizeof(b[0]), compare);
    int idx, ans = 0, max = -1;

    for (idx = 0; idx < total; idx++)
    {
        if (b[idx].cnt > max)
        {
            max = b[idx].cnt;
            ans = idx;
        }
    }

    printf("%s", b[ans].name);
    return 0;
}