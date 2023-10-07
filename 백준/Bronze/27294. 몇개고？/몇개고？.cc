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
	int t, s;
	cin >> t >> s;
	if (!s && t >=12 && t <=16) {
		cout << 320;
		return 0;
	}
	cout << 280;
}
