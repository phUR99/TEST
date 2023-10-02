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
long long ans[100][2];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	ans[1][0] = 0;
	ans[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		ans[i][0] = ans[i - 1][0] + ans[i - 1][1];
		ans[i][1] = ans[i - 1][0];
	}
	cout << ans[n][0] + ans[n][1];
}