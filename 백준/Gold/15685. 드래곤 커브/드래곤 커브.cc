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
int arr[11][1030];
bool map[105][105];

void func(int x, int y, int d, int g) {
	int k = (int)pow(2, g);
	map[y][x] = true;
	for (int i = 0; i < k; i++)
	{
		switch ((d+arr[g][i])%4)
		{
		case 0:
			x = x + 1;
			break;
		case 1:
			y = y - 1;			
			break;
		case 2:
			x = x - 1;			
			break;
		case 3:
			y = y + 1;			
			break;
		}
		map[y][x] = true;
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp = 2;
	for (int i = 1; i < 11; i++)
	{
		
		for (int j = 0; j < temp/2; j++) {
			arr[i][j] = arr[i-1][j];
			arr[i][temp - j-1] = (arr[i-1][j] +1) %4;
		}
		temp *= 2;
	}

	int t; cin >> t;
	int ans = 0;
	while (t--)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		func(x, y, d, g);

	}
	for (int j = 1; j <= 100; j++)
	{
		for (int i = 1; i <= 100; i++) {
			if (map[i][j] && map[i - 1][j] && map[i][j - 1] && map[i - 1][j - 1]) ans++;
		}

	}
	cout << ans;
}