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
//d : 0 가로 1 세로 2 대각선일 때 이 방향일 때 올수 있는 이전의 것들의 합.
using namespace std;
#define ll long long
int d[20][20][3];
int a[20][20];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	d[1][2][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			if (a[i][j] == 0) {
				// 현재 방향이 가로가 될라면 이전 방향이 가로거나 대각선
				d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][2];
				// 현재 방향이 세로가 될라면 이전 방향이 세로거나 대각선
				d[i][j][1] = d[i - 1][j][1] + d[i - 1][j][2];
				// 대각선 3방향이 0이 아니라면 대각선은 모든 방향에서 할 수 있음.
				if(a[i-1][j] ==0 && a[i][j-1] ==0) d[i][j][2] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
			}
		}
	}
	cout << d[n][n][0] + d[n][n][1] + d[n][n][2];

}
