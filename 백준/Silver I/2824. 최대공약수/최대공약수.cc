#include <bits/stdc++.h>
using namespace std;

/*
상근이는 학생들에게 두 양의 정수 A와 B의 최대공약수를 계산하는 문제를 내주었다. 그런데, 상근이는 학생들을 골탕먹이기 위해 매우 큰 A와 B를 주었다.

상근이는 N개의 수와 M개의 수를 주었고, N개의 수를 모두 곱하면 A, M개의 수를 모두 곱하면 B가 된다.

이 수가 주어졌을 때, 최대공약수를 구하는 프로그램을 작성하시오.

1. gcd(a, b) = gcd(n1*n2*n3..., m1*m2*m3...) ex = gcd(2 * 3 * 5 * 7, 2 * 3 * 7)  = gcd(a, 2) * gcd(a, 3) * gcd(a, 7)
2. 큰 수 a를 처리하는 방법 -> a의 곱이 아닌 원소 하나당 소인수 분해
3. b의 원소를 소인수분해하는 방법 -> 소인수분해하지 않는 대신 계속해서 확인하기
gcd(2 * 4 * 3 * 5 * 7, 2 * 3 * 4)
.1. gcd(2, 2), gcd(4,2) 한쪽이 한쪽을 나눌 수 있는 경우에는 더 큰 값으로 갱신해준다.
.2. 그 외에는 전부 곱해준다. gcd(a, 2) = 2;


*/

//최대공약수를 구해주는 gcd

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long n, m, a, b;
int ea[1005], eb[1005];

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	a = 1; b = 1;


	for (int i = 0; i < n; i++)
	{
		cin >> ea[i];
	}

	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> eb[i];
	}
	long long ans = 1;
	bool flag = false;
	long long div = 1e9;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			long long g = gcd(ea[i], eb[j]);
			ans *= g;
			if (ans >= div)  flag = true;
			ans %= div;
			ea[i] /= g;
			eb[j] /= g;

		}
	}
	if (flag) {
		string str = to_string(ans);


		for (int i = 0; i < 9 - str.size(); i++)
		{
			cout << "0";
		}

		cout << str;
	}
	else
	{
		cout << ans;
	}
}