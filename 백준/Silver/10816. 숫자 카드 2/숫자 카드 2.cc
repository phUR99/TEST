#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main(void) {
	int n, m, temp;
	cin >> n;
	vector<int> vecN, vecM;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vecN.push_back(temp);
	}
	sort(vecN.begin(), vecN.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		vecM.push_back(temp);
	}

	for (auto i : vecM) {
		cout << upper_bound(vecN.begin(), vecN.end(), i) - lower_bound(vecN.begin(), vecN.end(), i) << " ";
	}
}