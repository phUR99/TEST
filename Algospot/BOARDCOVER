#include <bits/stdc++.h>
using namespace std;
/*
#BOARDCOVER
1. PICNIC이랑 비슷한 문제 
1_1반복문을 돌면서 아직 채워지지 않은 블록을 찾는다.
1_2블록을 찾지 못했다면 전부 채운 것이므로 1을 반환한다.
2. 블록을 찾았다면 가능한 모양대로 시도해본다. (가능한 경우의 수를 줄이기 위해서 모양은 4가지로, 좌상에서 우하로 내려가는 방식을 취한다.
3. 놓으려는 자리가 이전에 있던 자리면 함수를 종료한다. 다만 이 경우에서는 한번에 3칸을 간다는 것에 유의한다.
4. 막히는 부분 : 현재 안 갔던 부분을 탐색하는 부분에서 무조건 처음부터 끝까지 탐색하게 만들어서 불가능한테 탐색하지 못하는 경우를 계속해서 탐색해서 중복되는 문제가 생김
-> 입력 오류 조심하기 : 완전 헤맴


*/
int h, w, t;
char board[20][20];
bool isUsed[20][20];

int d[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1}}
};
// 범위를 넘어갔는 지를 판단하는 함수
bool outOfBound(int x, int y) {
	return x < 0 || x >= h || y < 0 || y >= w;
}
// 원하는 모양대로 채울 수 있는 지 확인 후, 채운 후 그 여부를 반환하는 함수
bool fillCover(int x, int y, int shape) {

	int nx;
	int ny;

	for (int i = 0; i < 3; i++)
	{

		nx = x + d[shape][i][0];
		ny = y + d[shape][i][1];
		if (outOfBound(nx, ny) || isUsed[nx][ny] == true || board[nx][ny] == '#') {
			return false;
		}
	}
  // 이후 채울 수 있다면 채운다.
	for (int i = 0; i < 3; i++)
	{
		nx = x + d[shape][i][0];
		ny = y + d[shape][i][1];
		isUsed[nx][ny] = true;
	}
	return true;
}
//제거하는 함수
void removeCover(int x, int y, int shape) {
	int nx;
	int ny;
	for (int i = 0; i <3; i++)
	{
		nx = x + d[shape][i][0];
		ny = y + d[shape][i][1];
		isUsed[nx][ny] = false;
	}
	return;
}
//쓰지 않은 칸이 있는 지를 확인하는 함수
//순서를 강제한 것에 유의!
bool findNotUsed(int& x, int& y) {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) {
			if (board[i][j] != '#' && isUsed[i][j] == false) {
				x = i;
				y = j;
				return true;
			}
		}
	}
	return false;
}
int numOfFill() {
	int x = -1, y = -1;
	if (findNotUsed(x, y) == false) return 1;

	int ret = 0;	
	for (int dir = 0; dir < 4; dir++)
	{
		bool canFill = fillCover(x, y, dir);
		if (canFill == false) continue;
		ret += numOfFill();
		removeCover(x, y, dir);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> t;
	while (t--)
	{
		memset(isUsed, false, sizeof(isUsed));
		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}
		int ans = numOfFill();
		cout << ans << '\n';
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
