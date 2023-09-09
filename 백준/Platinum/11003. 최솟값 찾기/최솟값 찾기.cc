#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>


using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<pair<int, int>> d;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		while (!d.empty() && d.back().second >= temp)
		{
			d.pop_back();
		}
		d.push_back({i, temp});
		if (d.front().first <= i - m) d.pop_front();
		cout << d.front().second << " ";
	}
	return 0;
}