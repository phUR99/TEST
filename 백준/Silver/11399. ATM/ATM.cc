#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int p;
	cin >> n;
	vector<int> vec;
	
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	int temp = 0;
	for (auto i : vec)
	{
		temp += i;
		sum += temp;
		
	}
	cout << sum;
}