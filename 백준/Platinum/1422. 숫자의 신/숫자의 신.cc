#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll arr[55];

bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<>());
    vector<string> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(to_string(arr[i]));
        k--;
    }
    while (k--)
    {
        vec.push_back(to_string(arr[0]));
    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto e : vec)
    {
        cout << e;
    }


}