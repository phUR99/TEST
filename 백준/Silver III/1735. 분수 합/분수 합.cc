#include <bits/stdc++.h>
using namespace std;

/*
1. 분모의 최소공배수 구하기
2. 구한 최소공배수를 각 분모의 값으로 나눈 후, 그 몫을 반대쪽의 분자에 곱해서 더한다.
3. 출력이 기약분수가 아닐 수도 있다.

*/


int gcd(int a, int b) {	
	while (b != 0)
	{
		int temp;
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int a, b, c, d;
int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	
	
	cin >> a >> b >> c >> d;
	
	int s1 = a * d + c * b;
	int s2 = b * d;
	int g = gcd(s1, s2);
	s1 /= g;
	s2 /= g;
	cout << s1 << ' ' << s2;
	


	return 0;
}