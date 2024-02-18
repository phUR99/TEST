#include <bits/stdc++.h>
using namespace std;

/*
1. 소수 판정 배열 만들기 + 등장하는 소수를 셀 배열 하나 만들기
2. 원소를 받을 때마다 소인수 분해 후 소수를 셀 배열 원소에 더하기
3. 소수 배열을 순회하면서 원소를 n으로 나눈 값이 될 수 있을 때까지 cnt++;
4. 남아있는 배열의 모든 값을 곱하면 답

소인수 분해한 결과를 효율적으로 저장할 방법

*/


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(a % b, b);
}

bool nP[1000005];
int cP[1000005];
int cnt = 0;
int n;
int arr[105];
set<int> prime;

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 2; i * i < 1000001; i++)
	{
		if (nP[i] == true) continue;
		for (int j = i * i; j < 1000001; j += i) {
			nP[j] = true;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
		for (int j = 2; j <= tmp; j++)
		{
			int c = 0;
			if (nP[j] == true) continue;
			while (tmp % j == 0)
			{
				c++;
				tmp /= j;
			}
			if (c == 0) continue;
			cP[j] += c;
		}
	}
	long long ans = 1;
	for (int i = 2; i < 1000001; i++)
	{
		if (cP[i] < n) continue;
		for (int j = 1; j *n <= cP[i]; j++)
		{
			ans *= i;
		}
		prime.insert(i);
	}
	for (int i = 0; i < n; i++)
	{
		int g = gcd(ans, arr[i]);
		if (g == ans) continue;
		g = ans / g;
		for (auto e : prime)
		{
			while (g % e == 0)
			{
				g /= e;
				cnt++;
			}
		}
		
		
	}
	cout << ans << ' ' << cnt ;


	return 0;
}