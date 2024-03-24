#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*
#12100: idea: 방향을 적은 배열 만들기 이후 방향 반대되는 순열부터 탐색 진행하기
틀린 이유 : 한번 합쳐진 블록은 같은 횟수 내에서는 다시 합쳐지면 안된다. -> 한번 합쳐지면 표시해주기
*/
int arr[5];
int n;
int board[25][25];
//회전 방향의 결정에 따른 보드의 모양의 변형을 담아줄 배열 
int curBoard[25][25][5];
//문제 조건에서 한번 합쳐진 블록은 같은 횟수 내에서는 다시 합쳐지지 않으므로, 합쳐질 때마다 표시를 해줄 배열
bool isBeforeSum[25][25][5];
int ans = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


void moveElement(int x, int y, int dir, int cur, int curValue) {
	//범위 밖으로 나갔을 때,  이전 값을 불러와서 저장해준다
	if (x < 0 || x >= n || y < 0 || y >= n) {
		x -= dx[dir];
		y -= dy[dir];
		curBoard[x][y][cur] = curValue;
		return;
	}
	//현재 값이 같고, 이전에 합친 적이 없을 경우
	if (curBoard[x][y][cur] == curValue && isBeforeSum[x][y][cur] == false) {
		isBeforeSum[x][y][cur] = true;
		curBoard[x][y][cur] *= 2;
		return;
	}
	//현재 값이랑 다를 경우
	if (curBoard[x][y][cur] != 0 ) {
		x -= dx[dir];
		y -= dy[dir];
		curBoard[x][y][cur] = curValue;
		return;
	}
	//계속 시도
	moveElement(x + dx[dir], y + dy[dir], dir, cur, curValue);
}


void play(int cur) {
	int dir = arr[cur];
	//방향에 따라 보드의 움직이는 방향이 달라진다.
	if (dir == 0) {
		for (int y = 0; y < n; y++)
		{
			for (int x = n-1; x >= 0; x--) {
				int curValue = (cur == 0 ? board[x][y] : curBoard[x][y][cur - 1]);
				if (curValue == 0) continue;
				moveElement(x, y, dir, cur, curValue);
			}
		}
	}
	else if (dir == 1) {
		for (int x = 0; x < n; x++)
		{
			for (int y = n-1; y >= 0; y--) {
				int curValue = (cur == 0 ? board[x][y] : curBoard[x][y][cur - 1]);
				if (curValue == 0) continue;
				moveElement(x, y, dir, cur, curValue);
			}
		}

	}
	else if (dir == 2) {
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++) {
				int curValue = (cur == 0 ? board[x][y] : curBoard[x][y][cur - 1]);
				if (curValue == 0) continue;
				moveElement(x, y, dir, cur, curValue);
			}
		}
	}
	else
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++) {
				int curValue = (cur == 0 ? board[x][y] : curBoard[x][y][cur - 1]);
				if (curValue == 0) continue;
				moveElement(x, y, dir, cur, curValue);
			}
		}
	}
	return;
}

//방향을 정하는 부분
void moveBoard(int cur) {
	if (cur == 5) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				ans = max(ans, curBoard[i][j][4]);
			}
		}
		return;
	}
	play(cur);
	moveBoard(cur + 1);
}


void makedir(int cur) {
	if (cur == 5) {
		memset(curBoard, 0, sizeof(curBoard));
		memset(isBeforeSum, false, sizeof(isBeforeSum));
		moveBoard(0);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		arr[cur] = i;
		makedir(cur + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	makedir(0);
	cout << ans;


	/////////////////////////////////////////////////////////////////
	return 0;
}
