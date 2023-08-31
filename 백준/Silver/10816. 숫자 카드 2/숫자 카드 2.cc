//이분 탐색을 사용하되, binary_search는 true / false 만 반환하므로 upper_bound와 lower_bound를 이용해서 중복되는 원소의 개수를 반환할 수 있다.
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
