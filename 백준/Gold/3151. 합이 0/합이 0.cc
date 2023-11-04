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
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> group;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        group.push_back(temp);
    }
    ll ans = 0;
    sort(group.begin(), group.end());
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) {
            int goal = group[i] + group[j];
            if (binary_search(group.begin(), group.end(), -goal))
            {
                int idx_l = lower_bound(group.begin()+j+1, group.end(), -goal) - group.begin();
                int idx_u = upper_bound(group.begin()+j+1, group.end(), -goal) - group.begin();                             
 
                ans += idx_u - idx_l; 

               
            }

        }
    }
    cout << ans;
}