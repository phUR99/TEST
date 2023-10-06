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
int d[100050];
vector<pair<int, int>> vec;
// 0-1 knapsack problem
/*
	            if(W[row] > limit){
                DP[row][limit] = DP[row-1][limit];
            }
            //2. 담을 수 있는 경우
            else{
                DP[row][limit] = max(DP[row-1][limit - W[row]] + V[row]  ,  DP[row-1][limit]);
            }
*/
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		vec.push_back({w, v});
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j >= vec[i].first; j--) {
			d[j] = max(d[j - vec[i].first] + vec[i].second, d[j]);

		}
	}
	int ans = *max_element(d, d + k+1);
	cout << ans;
}
