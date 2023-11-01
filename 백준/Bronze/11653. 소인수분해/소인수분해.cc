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

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for ( int i = 2; i * i <= n; i++)
	{
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n != 1) cout << n;
}