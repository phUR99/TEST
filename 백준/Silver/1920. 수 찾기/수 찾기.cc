//이분탐색을 써야하는 이유
//최악의 경우 10^5번의 탐색을 진행해야 하는데, 순차 탐색일 경우에는 o(N^2)이므로 10억번의 연산이 넘게 필요할 수도 있다.
//무조건 시간 초과가 뜰 것이므로 algortihm 헤더의 binary_search 를 이용해서 i가 있는 지를 탐색한다.
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
