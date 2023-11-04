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
int a[100'005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 1e9 + 1;
	int st = 0;
	int ed = n - 1;
	while (st < ed)
	{
		int val = a[st] + a[ed];
		if (abs(val) < abs(ans)) ans = val;
		if (val < 0) st++;
		else ed--;
	}
	cout << ans;

}