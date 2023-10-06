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
ll d[205][205];
int di = 1'000'000'000;
//d[1][k]를 엄청 헤맸다.
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n ; i++)
	{
		d[i][1] = 1;
	}
	for (int i = 1; i <= k; i++)
	{
		d[1][i] = i;
	}
	fill(d[0] + 1, d[0] + k + 1, 1);
	for (int i = 2; i <=k ; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			
			for (int l = 0; l <= j ; l++)
			{
				d[j][i] += d[l][i - 1] % di;
				d[j][i] %= di;
			}
		}
	}
	cout << d[n][k] %di;

}
