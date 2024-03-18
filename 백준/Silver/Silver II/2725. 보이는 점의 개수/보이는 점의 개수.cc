#include <bits/stdc++.h>
using namespace std;

/*
(N, N)까지의 모든 점을 탐색하면서 기울기를 계산하기
1000개의 tc에 대해 0(1000^2)는 시간 초과 -> dp 활용하기
기울기가 1 이 되는 지점 기준으로 반전 가능 

*/
int d[1005];

bool board[1005][1005];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	d[1] = 3;
	int t;
	cin >> t;
	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1)
				cnt++;
		}
		d[i] = d[i - 1] + 2 * cnt;
	}

	while (t--)
	{
		int n;
		cin >> n;
		cout << d[n] << '\n';

	}
}