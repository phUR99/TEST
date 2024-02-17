#include <bits/stdc++.h>
using namespace std;

/*
1. 1e6 이하의 모든 정수에 대해서 에라토스테네스의 체를 이용하여 소수 배열을 만든다.
2. 2를 제외한 소수를 오름차순으로 탐색하면서 합이 n이 되는 소수가 있는지 찾는다 (탐색은 n /2까지)

*/

bool isP[1'000'005];
void func(int n) {
	for (int i = 3; i <= n / 2; i++)
	{
		if (isP[i] == true) continue;
		if (isP[n - i] == false) {
			cout << n << " = "<< i << " + " << n - i << '\n';
			return;
		}
	}
	cout <<   "Goldbach's conjecture is wrong.\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	

	for (int i = 2; i*i <= 1000000; i++)
	{
		if (isP[i] == true) continue;
		for (int j = i*i; j <= 1000000; j +=i)
		{
			isP[j] = true;
		}
	}
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		func(n);
	}
}