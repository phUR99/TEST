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
vector<pair<int, int>> vec;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		bool chk = false;
		for (auto &i : vec) {
			if (i.second == temp) {
				chk = true;
				i.first++;
				break;
			}
		}
		if (chk == false) vec.push_back({ 1, temp });
	}
	stable_sort(vec.begin(), vec.end(), cmp);
	for (auto i : vec)
	{
		while (i.first--) cout << i.second << ' ';
	}

}
