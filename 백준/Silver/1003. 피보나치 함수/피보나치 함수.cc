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

int ans[41][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;
	for (int i = 2; i <= 40; i++)
	{
		ans[i][0] = ans[i - 1][0] + ans[i - 2][0];
		ans[i][1] = ans[i - 1][1] + ans[i - 2][1];
	}

	while (n--)
	{
		int temp;
		cin >> temp;
		cout << ans[temp][0] << ' ' << ans[temp][1] << '\n';
	}
}
