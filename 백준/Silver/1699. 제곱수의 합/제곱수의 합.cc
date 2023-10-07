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
int arr[100'005];
int d[100'005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;

	for (int i = 1; i <=100'000; i++)
	{
		arr[i] = i * i;
		d[i] = 100'000'000;
	}
	for (int i = 1; arr[i] <= n; i++)
	{
		d[arr[i]] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j =1; arr[j] <= n; j++) {
			if(i+arr[j] <=n) d[i + arr[j]] = min(d[i] + 1, d[i + arr[j]]);
		}
	}
	cout << d[n];
}
