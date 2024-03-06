#include <bits/stdc++.h>
using namespace std;
/*
#JUMPGAME:
완전탐색 + 동적 계획법 적용해서 풀기

*/
int n;
int cache[105][105];
int board[105][105];
bool ooB(int x, int y) {
	return x >= n || y >= n;
}
//numRoute : 현재의 좌표의 값을 받아서 갈 수 있는 경로의 개수를 반환하는 함수
int numRoute(int x, int y) {
	//기저조건 1 : 칸을 넘어갔을 때
	if (ooB(x, y)) return 0;
	//기저조건 2 : 도착했을 때
	if (x == n - 1 && y == n - 1) return 1;

	int& ret = cache[x][y];
	//기저조건 3 : 가본적이 있을 때
	if (ret != -1) return ret;

	int jumpSize = board[x][y];
	return ret = numRoute(x + jumpSize, y) || numRoute(x, y + jumpSize);

}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		cout << (numRoute(0, 0) ? "YES" : "NO") << '\n';

	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
