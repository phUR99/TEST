#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> vec;
	int t;
	cin >> t;
	if (t == 1) {
		int temp;
		cin >> temp;
		cout << temp * temp;
		return 0;
	}
	while (t--)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	cout << vec[0] * vec[vec.size() - 1];
}
