#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>
#include <unordered_set>

using namespace std;
#define ll long long

unordered_set<string> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, state;
        cin >> name >> state;

        if (state == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<>());
    for (auto e : ans)
    {
        cout << e << '\n';
    }

}