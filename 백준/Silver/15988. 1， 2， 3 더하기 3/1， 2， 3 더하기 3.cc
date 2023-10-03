#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
#define ll long long
ll d[1'000'001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	int t; cin >> t;
	for (int i = 4; i <= 1'000'000; i++)
	{
		d[i] = (d[i - 1] % 1'000'000'009 + d[i - 2] % 1'000'000'009 + d[i - 3] % 1'000'000'009)% 1'000'000'009;
	
	}
	while (t--)
	{
		int n; cin >> n;
		cout << d[n] << '\n';
	}
	
}
