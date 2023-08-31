#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m, temp;
	vector<int> vec_n, vec_m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vec_n.push_back(temp);
	}
	sort(vec_n.begin(), vec_n.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		vec_m.push_back(temp);
	}
	for (auto i : vec_m) {
		cout << binary_search(vec_n.begin(), vec_n.end(), i) << " ";
	}

}