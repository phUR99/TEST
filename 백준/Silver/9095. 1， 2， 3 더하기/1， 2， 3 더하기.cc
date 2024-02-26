#include <bits/stdc++.h>
using namespace std;
/*
#9095 : Top_down 방식의 DP 설계하기

d[i] : i일 때 연산 3개를 사용해서 만들 수 있는 가짓수
d[i] = d[i-1] + d[i-2] + d[i-3]
d[1] =1, d[2] =2, d[3] = 4;

*/
int n, t;
int d[21];
const int MX = 0x3f3f3f3f;

int func(int n) {
	//종료조건 
	if (n < 1) {
		return d[0];
	} 
	if (d[n] != MX) return d[n];
	else
	{
		return d[n] = func(n - 1) + func(n - 2) + func(n - 3);
	}
}



int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	fill(d+1, d + 21, MX);
	d[1] = 1; d[2] = 2; d[3] = 4;
	func(20);
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << d[n] << '\n';
	}
	


	return 0;
}