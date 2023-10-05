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

int d[1'000'005];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[0] = 1; d[1] = 1;
	int n; cin >> n;
	for (int i = 2; i <=n; i++)
	{
		d[i] = (d[i-2] + d[i - 1])  % 15746;
	}
	cout << d[n];


	
	
}
