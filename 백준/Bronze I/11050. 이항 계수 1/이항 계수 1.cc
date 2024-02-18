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
int arr[15];
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = n-k; i < n; i++)
	{
		arr[i] = 1;
	}
	int ans = 0;
	do
	{
		ans++;
	} while (next_permutation(arr, arr + n));

	cout << ans;
}