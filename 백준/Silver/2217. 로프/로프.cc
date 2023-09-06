#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> vec;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	int M = vec[0];
	for (int i = 0; i < N; i++)
	{
		vec[i] = vec[i] * (N - i);
		M = max(M, vec[i]);
	}
	cout << M;
}