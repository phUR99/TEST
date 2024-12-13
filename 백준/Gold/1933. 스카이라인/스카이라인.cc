#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
/*
x좌표는 큰 값을 먼저 확인
y좌표는 작은 값을 먼저 확인
map을 사용하였으나 multiset을 사용하는 방법도 있음

고려해야하는 케이스 2
1. 건물이 겹칠 때
2. 건물이 붙어있을 때때
*/

int main()
{
    fastio;
    cin >> n;
    vector<array<int, 3>> arr;
    for (int i = 0; i < n; i++)
    {
        int x, y, h;
        cin >> x >> h >> y;
        arr.push_back({x, -1, -h});
        arr.push_back({y, 1, h});
    }
    sort(arr.begin(), arr.end());
    multiset<int> height;
    height.insert(0);
    for (auto i : arr)
    {

        int x = i[0];
        int end = -i[1];
        int h = i[2] * i[1];
        if (end == 1)
        {
            if (*prev(height.end()) < h)
            {
                cout << x << ' ' << h << ' ';
            }
            height.insert(h);
        }
        else
        {
            height.erase(height.find(h));
            if (*prev(height.end()) < h)
            {
                cout << x << ' ' << *prev(height.end()) << ' ';
            }
        }
    }

    return 0;
}