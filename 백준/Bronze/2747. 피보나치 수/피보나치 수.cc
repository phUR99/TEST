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

ll d[50];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	d[0] = 0; d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];
	
}