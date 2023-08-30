#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.second) if (a.second < b.second) return true;
	return a < b;
}


int main(void) {
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	int tmp_1, tmp_2;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp_1 >> tmp_2;
		v.push_back({tmp_1, tmp_2});
	}
	sort(v.begin(), v.end(), cmp);
	
	for (auto i : v)
	{
		cout << i.first << " " << i.second << '\n';
	}
	return 0;
}