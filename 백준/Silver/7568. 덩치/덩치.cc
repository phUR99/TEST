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
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		int w, h;
		cin >> w >> h;
		vec.push_back({ w, h });
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		
		for (int j =0; j < n; j++)
		{
			if (i == j) continue;
			if (vec[j].first > vec[i].first && vec[j].second > vec[i].second) cnt++;
		}
		cout << cnt << ' ';
	}
}