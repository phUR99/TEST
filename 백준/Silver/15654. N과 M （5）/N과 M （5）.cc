#include <bits/stdc++.h>
using namespace std;
/*

*/
int num[9];
int arr[9];
bool isUsed[9];
int n, m;
// idx번째를 현재 함수를 실행시켜서 채우고, 그 이후는 자기 자신을 불러서 동일한 방식으로 해결하는 방식의 백트래킹 구현
void func(int idx, int cur) {
	//기저조건 1: 사용한 숫자면 종료한다.
	if (isUsed[cur]) return;
	//기저조건 2: m번째 idx까지 배열을 채웠을 경우 그 값을 출력하고 종료한다.
	//주의 : 기저조건 2에서 함수를 종료시켰을 경우 isused[cur] = false 구문을 실행하지 않고 종료시키게 되어 탐색을 하지 않는 문제가 생김.
	arr[idx] = num[cur];
	isUsed[cur] = true;
	if (idx == m) {
		for (int i = 1; i <= m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else
	{			
		for (int i = 1; i <= n; i++)
		{
			func(idx + 1, i);
		}
	}
	isUsed[cur] = false;
	return;
}




int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	
	cin >> n >> m;	
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	sort(num + 1, num + n + 1);
	func(0, 0);
	/////////////////////////////////////////////////////////////////
	return 0;
}