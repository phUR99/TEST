#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout.precision(num) 연산으로 필요한 자릿수까지 출력할 수 있다.
	cout.precision(10);
	double a, b;
	cin >> a >> b;
	cout << a / b;
}
