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

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int solve(int m, int n, int x, int y) {
	if (x == m) x = 0;
	if (y == n) y = 0;
	int l = lcm(m, n);
	for (int i = x; i <= l; i += m )
	{
		if (i == 0) continue;
		if (i% n == y) return i;
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	while (n--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		cout << solve(m, n, x, y) << '\n';
	}

}