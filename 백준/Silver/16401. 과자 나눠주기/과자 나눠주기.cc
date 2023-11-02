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
int m, n;
int l[100'000'5];

bool solve(int x) {
	if (x == 0) return true;
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += l[i] / x;
	}
	return cnt >= m;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	int st = 0;
	int ed = *max_element(l, l + n);
	while (st<ed)
	{
		int mid = (st + ed + 1) / 2;
		if (solve(mid)) st = mid;
		else ed = mid - 1;
	}
	cout << st << '\n';
}