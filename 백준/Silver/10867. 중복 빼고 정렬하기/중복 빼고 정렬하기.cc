#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main(void) {
	int n;
	int temp;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end()); 
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (auto i : vec) {
		cout << i << " ";
	}
}