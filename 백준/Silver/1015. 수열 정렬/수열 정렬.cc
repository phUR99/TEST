#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<int> arr, copyArr;
int n;

int main()
{
    fastio;
    cin >> n;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    copyArr = arr;
    sort(copyArr.begin(), copyArr.end());
    map<int, queue<int>> dict;
    for (int i = 0; i < n; i++)
    {
        dict[copyArr[i]].push(i);
    }
    for (auto &i : arr)
    {
        cout << dict[i].front() << ' ';
        dict[i].pop();
    }

    return 0;
}