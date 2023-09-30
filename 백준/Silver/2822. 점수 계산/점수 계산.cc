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


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> v;
	vector<int> vec;
	for (int i = 1; i <= 8; i++)
	{
		int temp;
		cin >> temp;
		v.push_back({ temp, i });
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 3; i < 8; i++)
	{
		sum += v[i].first;
		vec.push_back(v[i].second);
	}
	sort(vec.begin(), vec.end());
	cout << sum << '\n';
	for (auto i : vec)
	{
		cout << i << ' ';
	}
}
