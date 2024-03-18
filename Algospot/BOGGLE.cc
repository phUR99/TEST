#include <bits/stdc++.h>
using namespace std;
/*
#BOGGLE : 재귀함수를 구성하는데 항상 헤메는 부분은 뭘까?
1. n개 중 1개의 정보를 처리하고 나머지 정보는 자기 자신을 호출해서 처리하는 것을 항상 기억하자.
2. 다음 처리하는 함수에 대해서 최대한 인자를 줄이는 방향으로 가자. 
즉 현재의 값은 항상 현재의 실행에서만 다 쓰고 나서 더 미래의 값으로 전달하지 않는 것이다.
3. 함수를 정의할 때, 이 함수가 무슨 입력을 받아서 무슨 출력을 반환하는 지를 쓰고 가자. 좀 덜 헷갈릴 것 같다.
4. for문에서 다시 isword를 체크한다는 생각을 잘 하지 못했다. 재귀의 작동 방식에 대해서 더 이해가 필요할 것 같다.
*/

bool outOfBound(int x, int y) {
	return x < 0 || x >=5 || y < 0 || y >= 5;
}
int dx[8] = { -1, 1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
char board[5][5];
int t;
/*
완전탐색: isword의 구현이 x, y에 대해서 word를 만들 수 있는 지에 대해서 출력하므로, 이 전체문제를 부분문제를 바꿀 수 있다.
//isWord : (현재 좌표, 현재 인덱스, 목표 스트링)를 받아서 (x, y)부터 시작해서 word를 만들 수 있는 지에 대한 결과를 반환하는 함수
//재귀적 구현: isWord를 word의 사이즈보다 커지지 않을 때까지 좌표를 탐색하면서 자기 자신을 재귀로 구현.
bool isWord(int x, int y, int idx, string& word) {
	//기저조건 0: idx >= word.size() (탐색 종료)
	if (idx >= word.size()) return 1;
	//기저조건 1: 범위를 벗어난 경우
	if (outOfBound(x, y)) return 0;
	//기저조건 2: 현재의 값으로 word를 만들 수 없을 경우
	if (board[x][y] != word[idx]) return 0;
	// 다음 좌표로 idx+1을 넘겨준다.
	for (int dir = 0; dir < 8; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		// 구현이 막힌 부분 1. isWord의 다음을 탐색하라는 명령을 어떻게 주어야 할지 고민
		// isWord는 무조건 word를 만들 수 있는 지에 대한 결과를 반환하는 함수이므로 밑의 구문을 통해서 함수의 동작이 가능하다.
		if (isWord(nx, ny, idx + 1, word) == 1) return 1;
	}
	return 0;
}
*/
//부분문제 : word의 가능을 반환하는 것이 아닌 word[idx]의 가능성을 반환하게 만든다.
//중복된 탐색이 발생할 경우 그 값을 읽어서 그대로 반환해준다.
int cache[5][5][10];
int isWord(int x, int y, int idx, string& word) {
	//기저조건 1: 인덱스가 사이즈를 넘어갈 경우
	if (idx >= word.size()) return 1;
	//기저조건 2: 범위를 넘어갈 경우
	if (outOfBound(x, y) || word[idx] != board[x][y]) return 0;
	//기저조건 3: 맞지 않을 경우
	//ret를 0으로 바꿔 준후 그 값을 반환한다.
	int& ret = cache[x][y][idx];
	if (ret != -1) return ret;

	for (int dir = 0; dir < 8; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (isWord(nx, ny, idx + 1, word) == 1) {
			return ret = 1;
		}
	}
	return ret = 0;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> t;
	while (t--)
	{

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
			{
				cin >> board[i][j];
			}
		}
		int n;
		cin >> n;
		while (n--)
		{
			string word;
			cin >> word;
			bool ans = false;
			//cache의 초기화를 여기서 해야한다.
			memset(cache, -1, sizeof(cache));
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++)
				{
					if (isWord(i, j, 0, word)) ans = true;
				}
			}
			// cout에서 3항 연산자를 이용해서 출력을 하고 싶다면 괄호를 이용해서 우선순위를 높여줘야 한다.
			// <<의 연산 우선순위는 ?의 우선순위보다 높다.
			cout << word << ((ans) ? " YES\n" : " NO\n");
		}
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
