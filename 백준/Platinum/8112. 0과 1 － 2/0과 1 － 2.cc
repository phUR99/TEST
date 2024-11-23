#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
모든 수를 체크할 수는 없음 -> 최대 100자리인데 보관할 공간 X
-> 모듈러 연산을 이용하기(항상 다 적용할 수 없는 큰 수에 대해서는 모듈러를 생각하자)
-> 이후 0으로 시작하는 원소를 제거하기 위해서 시작점에 1을 추가하고 BFS를 실행
BFS로 0에 도달할 수 있다면 역추적을 사용해서 숫자를 찾기

*/
int parent[1000005];
int choice[1000005];
string digits = "01";
void solve()
{
    memset(parent, -1, sizeof(parent));
    memset(choice, -1, sizeof(choice));
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    queue<int> q;
    q.push(1);
    parent[1] = -2;
    choice[1] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (auto i : digits)
        {
            int there = (here * 10 + (i - '0')) % (n);
            if (parent[there] == -1)
            {
                parent[there] = here;
                choice[there] = i - '0';
                q.push(there);
            }
        }
    }
    if (parent[0] == -1)
    {
        cout << "BRAK\n";
    }
    else
    {
        string ret;
        // 시작이 parent[0]이 아니라 0부터 시작해야한다
        for (int i = 0; i != -2; i = parent[i])
        {
            ret += char('0' + choice[i]);
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}