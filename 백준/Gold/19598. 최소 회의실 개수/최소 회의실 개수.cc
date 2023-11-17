#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<>> end;
    vector<pair<int, int>> sc;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        sc.push_back({ st, ed });
    }
    sort(sc.begin(), sc.end());
    end.push(sc[0].second);
    for (int i = 1; i < n; i++)
    {
        end.push(sc[i].second);
        if (sc[i].first >= end.top()) end.pop();
        
        
    }
    cout << end.size();
}