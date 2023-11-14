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
#include <unordered_map>

using namespace std;
#define ll long long

unordered_map<string, int> s1;
string s2[100005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string name;
        cin >> s2[i];
        s1[s2[i]] = i;
    }
    while (m--)
    {
        string temp;
        cin >> temp;
        if (isdigit(temp[0])) {
            cout << s2[stoi(temp)] << '\n';
        }
        else
        {
            cout << s1[temp] << '\n';
        }
    }

}