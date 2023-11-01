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
vector<bool> state(1000001, true);
void chk(int n) {
	state[1] = false;
	for (int i = 2; i*i <= n; i++)
	{
		if (!state[i]) continue;
		for (int j = i*i; j <= n; j +=i)
		{
			state[j] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	chk(n);
	for (int i = m; i <= n; i++)
	{
		if (state[i]) cout << i << '\n';
	}
}