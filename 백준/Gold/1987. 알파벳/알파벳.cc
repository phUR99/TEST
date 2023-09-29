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
int cnt = 1, r, c;
bool isused[26];
char map[20][20];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


void func(int x, int y, int k) {
	
	cnt = max(cnt, k);
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (isused[map[nx][ny] - 'A']==true) continue;
		isused[map[nx][ny] - 'A'] = true;
		func(nx, ny, k+1);
		isused[map[nx][ny] - 'A'] = false;
	}
}




int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = temp[j];
		}
	}
	isused[map[0][0] - 'A'] = true;
	func(0, 0, 1);

	cout << cnt;
}

