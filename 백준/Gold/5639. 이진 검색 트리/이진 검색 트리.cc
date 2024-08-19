#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int N;

int tree[10005];
/*
이진 트리를 세 구간으로 분할한다 1. 왼쪽 서브트리, 2. 루트, 3. 오른쪽 서브트리
오른쪽 서브트리의 모든 원소는 항상 루트보다 크므로 반복문을 돌면서 루트보다 커지는 지점을 찾는다.
그 지점을 기준으로 왼쪽과 오른쪽 서브트리로 나눠서 분할 진행
*/

void solve(int st, int ed)
{
    if (ed <= st)
        return;

    int i;
    for (i = st + 1; i < ed; i++)
    {
        if (tree[st] < tree[i])
            break;
    }
    solve(st + 1, i);
    solve(i, ed);
    cout << tree[st] << '\n';
}

int main()
{
    fastio;
    int now = 0;

    while (cin >> N)
    {
        tree[now++] = N;
    }
    solve(0, now);
    return 0;
}