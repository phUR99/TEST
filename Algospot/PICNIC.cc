#include <bits/stdc++.h>
using namespace std;
/*
#PICNIC :
1. 완전탐색 시도하기 : 완전탐색을 시도했을 경우에 o(n!) 예상. 최대 10명이므로 10!은 3600000정도이므로 최악의 경우에도 통괄할 수 있다.
2. 헤맸던 부분 : 함수의 모듈화 -> 함수를 한번에 모든 기능을 처리하는 방식으로 작성하는 것을 지양하자. 현재 함수에서도 값을 선택하는 부분과 짝을 지어주는 부분을 이중 for문으로 
해결할려 했는데 중복 문제가 나서 값을 선택하는 부분과 짝을 지어주는 부분을 분리하는 것으로 해결했다.
3. 고정크기 배열을 인수로 보내기 위해서는 (&ref)[size]의 형태로 보내줘야함
4. 함수가 어떤 역할을 하는 함수인지 체크를 하면서 사용하자.
*/
bool isFriend[10][10];
int t, n, m;

// numMakePair : 불 배열 isUsed를 받아서 가능한 쌍의 개수를 출력하는 함수
int numMakePair(bool(&isUsed)[10]) {
	int ret = 0;	
	int cur = -1;
	// 아직 짝이 없는 친구를 선택하는 부분
	for (int idx = 0; idx < n; idx++)
	{
		if (isUsed[idx] == true) continue;		
		isUsed[idx] = true;		
		cur = idx;
		break;
	}
	//기저조건 1 : 짝이 전부 완성되었을 경우 1을 반환한다.
	if (cur == -1) return 1;
	// 위의 친구에서 짝을 지어주는 부분
	for (int nxt = cur + 1; nxt < n; nxt++)
	{
		//기저조건 2: 사용한 숫자거나, 친구가 될 수 없다면 종료한다.
		if (isFriend[cur][nxt] == false || isUsed[nxt] == true) continue;
		isUsed[nxt] = true;
		// 될 수 있는 값을 모두 반환한다.
		ret += numMakePair(isUsed);
		isUsed[nxt] = false;
	}
	isUsed[cur] = false;	
	// 그 값을 반환한다.
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(isFriend, false, sizeof(isFriend));
		while (m--)
		{
			int f1, f2;
			cin >> f1 >> f2;

			isFriend[f1][f2] = true;
			isFriend[f2][f1] = true;

		}
		bool arr[10];
		memset(arr, false, sizeof(arr));

		int ans = numMakePair(arr);
		cout << ans << '\n';
	}
	/////////////////////////////////////////////////////////////////
	return 0;
}
