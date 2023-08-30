#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main(void) {
	int n, temp;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < 2 * n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int min_T = v[0] + v[2 * n - 1];
	for (int i = 1; i < n; i++)
	{
		min_T = min(min_T, v[i] + v[2 * n - 1 - i]);
	}
	cout << min_T;
}