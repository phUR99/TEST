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
ll d[1001][10];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		d[i][0] = 1;
		for (int j = 1; j < 10; j++)
			d[i][j] = (d[i][j - 1] + d[i - 1][j]) % 10007;
		
	}
	cout << accumulate(d[n], d[n] + 10, 0) % 10007;

}
