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
int map[1050][1050];
int d[1050][1050];




int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 1; j <= m; j++) {
			map[i][j] = str[j - 1]-'0';
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		
		for (int j = 1; j <= m; j++) {
			
			if (map[i][j] == 1) {
				d[i][j] = min({ d[i - 1][j - 1], d[i - 1][j], d[i][j - 1] }) + 1;
				ans = max(ans, d[i][j]);
			}
		}
	}
	cout << ans * ans;
	
	
}
