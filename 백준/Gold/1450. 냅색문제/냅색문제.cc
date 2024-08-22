#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

vector<int> l, r;
int N, C;
int a[35];

void query(int st, int ed, int now, vector<int> &arr)
{
    if (now > C)
        return;
    if (st == ed)
    {
        arr.push_back(now);
        return;
    }
    query(st + 1, ed, now + a[st], arr);
    query(st + 1, ed, now, arr);
}

int main()
{
    fastio;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    query(0, N / 2, 0, l);
    query(N / 2, N, 0, r);
    int len = l.size();
    long long answer = 0;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    for (int i = 0; i < len; i++)
    {
        answer += r.size() - (r.end() - upper_bound(r.begin(), r.end(), C - l[i]));
    }
    cout << answer;

    return 0;
}