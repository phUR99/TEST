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
ll arr[85];
ll d[85];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	d[1] = 4;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 2 * arr[i];
	}
	cout << d[n];
}