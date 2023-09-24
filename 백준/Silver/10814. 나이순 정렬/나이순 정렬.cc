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

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int age;
	string name;
	int t;
	cin >> t;
	vector<tuple<int, int, string>> vec;
	for (int i = 1; i <= t; i++)
	{
		cin >> age >> name;
		vec.push_back({ age, i, name });
	}
	sort(vec.begin(), vec.end());
	for (auto i : vec)
	{
		cout << get<0>(i) <<" "<< get<2>(i) << '\n';
	}
}
