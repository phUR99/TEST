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
int d[1001];
int arr[10001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	d[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = max({ arr[i], d[i],d[i-j]+arr[j]});
		}
	}
	cout << d[n];
}
