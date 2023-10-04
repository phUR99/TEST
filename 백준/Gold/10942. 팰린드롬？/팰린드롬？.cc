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
int arr[2001];
bool d[2001][2001];




int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int t; cin >> t;
	fill(d[1], d[1] + n + 1, true);
	//d[i][j] i번째 간격의 j번째 펠린들롬;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i - 1] == arr[i]) d[2][i] = true;
	}

	for (int i = 3; i <=n; i++)
	{
		for (int j = i; j <= n; j++) {
			if (arr[j-i+1] == arr[j] && d[i-2][j-1]) d[i][j] = true;
		}
	}

	while (t--)
	{
		int st, ed;
		cin >> st >> ed;
		cout << d[ed-st+1][ed] << '\n';
	}
	
}
