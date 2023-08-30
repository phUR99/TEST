#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	vector<int>	A, B;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		B.push_back(temp);
	}
	sort(A.begin(), A.end());
	for (auto i : B)
	{
		cout << binary_search(A.begin(), A.end(), i) << "\n";
	}
	
}