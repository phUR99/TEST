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
#define ll long long
int d[10001];
int arr[10001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int k; cin >> k;
		fill(d, d + k + 1, 0);
		d[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = arr[i]; j <= k; j++) {
				d[j] += d[j - arr[i]];
			}
		}
		cout << d[k] << '\n';
	}
}
