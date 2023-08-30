#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v;
	int n;
	cin >> n;
	int N;
	for (int i = 0; i < n; i++)
	{
		cin >> N;
		v.push_back(N);
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i << "\n";
	}


	return 0;
}