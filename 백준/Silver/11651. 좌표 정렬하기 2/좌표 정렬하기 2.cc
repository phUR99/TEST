#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(const pair<int, int> &temp1, const pair<int, int> &temp2) {
	if (temp1.second > temp2.second) return false;
	else if (temp1.second == temp2.second) {
		if (temp1.first >= temp2.first) return false;
		return true;
	}
	return true;
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<pair<int ,int>> vec;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		vec.push_back({x, y});
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << " " << vec[i].second << '\n';
	}
}
