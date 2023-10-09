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
int arr[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	while (m--)
	{
		int st, ed;
		cin >> st >> ed;

		reverse(arr + st, arr + ed + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << ' ';
	}
}