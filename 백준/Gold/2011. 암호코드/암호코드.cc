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
int arr[5001];
int d[5001];
int mod = 1000000;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 1; i <= n; i++)
	{
		arr[i] = str[i - 1]-'0';
	}
	d[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (arr[i] > 0) d[i] = (d[i] + d[i - 1]) % mod;
		int x = arr[i - 1] * 10 + arr[i];
		if (x >= 10 && x <= 26) d[i] = (d[i] + d[i - 2]) % mod;
	}
	cout << d[n];
	
	
}
