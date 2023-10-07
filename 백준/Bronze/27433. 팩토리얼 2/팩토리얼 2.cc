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
ll func(int n) {
	if (n == 0) return 1;
	return n*func(n - 1);
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k; cin >> k;
	cout << func(k);
}
