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
	int x; int y;
	cin >> x >> y;
	if (x * y > 0) {
		if (x > 0) cout << 1;
		else cout << 3;
	}
	else {
		if (x > 0) cout << 4;
		else cout << 2;
	}
}