#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<double> vec;
	double m = 0;
	int num = n;
	while (n--)
	{
		double temp; cin >> temp;
		vec.push_back(temp);
		m = max(m, temp);
	}
	double sum = 0;
	for (double i : vec)
	{
		sum += i / m * 100;

	}
	cout << sum / num;
}
