#include <bits/stdc++.h>
using namespace std;

/*
K개의 소수가 있다. 이때, 이 소수들 중에서 몇 개를 곱해서 얻게 되는 수들이 있을 것이다. 소수들을 선택할 때에는 같은 수를 선택해도 되며, 주어지는 소수 자체도 포함시키자.
예를 들어 세 소수가 2, 5, 7이었다면, 이러한 곱들을 오름차순으로 나타내 보면, 2, 4, 5, 7, 8, 10, 14, 16, 20, 25, 28, 32, 35, 등이 된다.
K개의 소수가 주어졌을 때, 이러한 소수의 곱들 중에서 N번째 수를 구해 보자. 단 정답은 231보다 작은 자연수이다.

1. 작은 수에 작은 수를 곱하면 작은 수가 나온다
2. pq : 수를 오름차순을 정렬했을 때 가장 작은 수 -> logN의 시간복잡도
3. 사용한 제일 작은 수를 제거한다.
2 5 7 k = 0 size =3
2 5 7 4 10 14 k =0 size s = 6 total t = 6
4 5 7 10 14 k =1 s =5 t 6
4 5 7 10 14 8 20 28 k= 1 s = 8 t = 9
5 7 8 10 14 20 28 k =2 s =7 t =9
4. t가 n 이 될 때를 계산한 후에 pq를 계속해서 제거한다.
5. top을 반환한다.
-> 수가 겹치는 경우의 해결 set 이용
 메모리 초과 : 다 만드는게 문제가 되는듯.

*/
priority_queue<long long, vector<long long>, greater<long long>> pq;

int arr[1005];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n;

	long long MV = 1e9;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		pq.push(arr[i]);

	}
	long long cur = 0;

	while (n--)
	{
		cur = pq.top();
		pq.pop();
		for (int i = 0; i < n; i++)
		{
			pq.push(cur * arr[i]);
			if (cur % arr[i] == 0) break;
		}
	}

	cout << cur;
}