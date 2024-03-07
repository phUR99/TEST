#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
#define X first
#define Y second
int map[50][50];
int dist[50][50];
int n, m;
vector<pair<int, int>> v, b;
int ans = 100'000'001;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back({ i, j });
			if (map[i][j] == 1) b.push_back({ i, j });
		}
	}

	int len = b.size();
	vector<int> check((int)v.size());
	for (int i = 0; i < m; i++) {
		check[i] = 1;
	}
	sort(check.begin(), check.end());
	do
	{
		int temp = 0;
		for (int i = 0; i < len; i++)
		{
			pair<int, int> cur_home = b[i];
			int x = cur_home.X;
			int y = cur_home.Y;
			int cur_dist = 10000;
			for (int j = 0; j < v.size(); j++)
			{
				if (check[j] == 0) continue;
				cur_dist = min(cur_dist, abs(x - v[j].X) + abs(y - v[j].Y));
			}
			temp += cur_dist;
		}
		ans = min(ans, temp);

	} while (next_permutation(check.begin(),check.end()));
	cout << ans;
}

