#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int N;
int dist[25][25];
bool isMin[25][25];

int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> dist[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            bool is = true;
            for (int k = 1; k <= N; k++)
            {

                if (i == k || k == j)
                    continue;
                int now = dist[i][k] + dist[k][j];
                if (now < dist[i][j])
                {
                    cout << -1;
                    return 0;
                }
                else if (now == dist[i][j])
                    is = false;
            }
            if (is)
            {
                isMin[i][j] = 1;
                isMin[j][i] = 1;
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (isMin[i][j])
                answer += dist[i][j];
        }
    }
    cout << answer;

    return 0;
}