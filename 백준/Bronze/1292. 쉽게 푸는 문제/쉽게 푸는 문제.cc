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
	vector<int> ans;
	int sum = 0;
	for (int i = 1; i <=50; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			ans.push_back(i);
		}
	}
	int a, b;
	cin >> a >> b;
	for (int i = a-1; i < b; i++)
	{
		sum += ans[i];
	}
	cout << sum;
}