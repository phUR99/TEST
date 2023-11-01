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
bool isprime(int n) {
	if (n == 1) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	int ans = 0;
	while (t--)
	{
		int temp;
		cin >> temp;
		ans += isprime(temp);
	}
	cout << ans;
}