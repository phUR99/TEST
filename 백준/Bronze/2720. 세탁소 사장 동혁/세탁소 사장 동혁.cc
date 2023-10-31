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
int coin[4] = { 25, 10, 5, 1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int money;
		cin >> money;
		for (int i = 0; i < 4; i++)
		{
			cout << money / coin[i] << ' ';
			money %= coin[i];
		}
		cout << '\n';
	}
}