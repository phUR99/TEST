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

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int g;
    vector<int> ans;
    cin >> g;
    long long st = 1;
    long long ed = 1;
    bool existed = false;
    while (true)
    {
        if (ed * ed - st * st == g) {
            existed = true;
            cout << ed << '\n';
        }
        if (ed - st == 1 && ed * ed - st * st > g) break;
        if (ed * ed - st * st > g) st++;
        else ed++;
    }
    if (!existed) cout << -1;
  
}