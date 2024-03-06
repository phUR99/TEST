#include <bits/stdc++.h>
using namespace std;
/*
#CLOCKSYNC
1. 초기 입력의 어려움
2. 문제 조건 잘 읽기
3. 스택 오버플로우 조심하

*/
int t;

int buttonArr[10][16] = {
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};
int clockArr[16];

bool isSort() {
	for (int i = 0; i < 16; i++)
	{
		if (clockArr[i] != 12) return false;
	}
	return true;
}
//문제 이해 오류
//숫자가 12여야 정렬이 된건데 이걸 12로 나누니까 답이 잘 나오지 않았다.
//이렇게 함수를 짤 수 있는 이유는 순서가 의미가 없으니까 !!

void push(int button) {

	for (int i = 0; i < 16; i++)
	{
		if (buttonArr[button][i] == 0)  continue;
		clockArr[i] += 3;
		if (clockArr[i] == 15) clockArr[i] = 3;
	}
	return;
}
const int MX = 987654321;
int numClockSort(int curButton) {
	int ret = MX;

	//구현 테크닉 부족 1. curbutton이 9가 되면 정렬이 되는 지를 체크하려고 했는데 그렇게 하면 마지막 스위치는 cnt를 세지 않는 문제 발생
	//인덱스를 최대값보다 하나 더 늘려서 이를 해결
	if (curButton == 10) return (isSort()) ? 0 : MX;
	for (int cnt = 0; cnt < 4; cnt++)
	{
		//구현 테크닉 부족 2.
		//처음에는 이중포문을 사용해서 순서의 의미가 생겨버렸다.
		//그렇게 하지말고 함수의 인자로 현재의 버튼의 인덱스를 제공하는 방법으로 해결하자.
		ret = min(ret, numClockSort(curButton + 1) + cnt);
		push(curButton);
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 16; i++) {
			cin >> clockArr[i];
		}
		int ans = numClockSort(0);
		cout << (ans == MX ? -1 : ans) << '\n';
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
