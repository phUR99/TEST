#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>

using namespace std;
#define ll long long
int n;
int x[100'5];
vector<int> two;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> x[i];
	}
	sort(x, x + t);
	for (int i = 0; i < t; i++)
	{
		for (int j = i; j < t; j++) {
			two.push_back(x[i] + x[j]);
		}
	}
	sort(two.begin(), two.end());
	for (int i = t-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++) 
		{
			if (binary_search(two.begin(), two.end(), x[i]-x[j]))
			{
				cout << x[i];
				return 0;
			}
		}
	}
}