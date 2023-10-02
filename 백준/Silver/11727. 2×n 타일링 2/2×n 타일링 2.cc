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
int ans[1001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	ans[1] = 1;
	ans[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		ans[i] = (ans[i - 1] + 2 * ans[i - 2]) % 10007;
	}
	cout << ans[n];
}
