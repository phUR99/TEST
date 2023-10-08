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
bool map[105][105];
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x +10; i++)
		{
			for (int j = y; j < y + 10; j++) {
				map[i][j] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 100 ; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (map[i][j]) cnt++;
		}
	}
	cout << cnt;
	
}