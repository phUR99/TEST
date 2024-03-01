#include <bits/stdc++.h>
using namespace std;
/*
#1065: 재귀함수로 구현해보려 했는데 잘 안됐다.
체크하는 함수를 만들고 커지는 등차수열과 작아지는 등차수열의 함수를 만들어서 해결하려 했는데 잘 되지 않았다.
3자리 수 전까지는 무조건 한수의 조건을 만족하므로 3자리가 넘어가는 숫자만 한수인지를 체크
4자리는 1000밖에 없으므로 무조건 한수가 되지 못한다.


*/

int ans = 0, n;
bool isAns(string& str) {
	return str[2] - str[1] == str[1] - str[0];
}



int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n;

	if (n < 100)
	{
		cout << n;
		return 0;
	}
	int ans = 99;
	for (int i = 100; i <= n; i++)
	{
		string cur = to_string(i);
		if (isAns(cur)) ans++;
	}
	cout << ans;

	/////////////////////////////////////////////////////////////////
	return 0;
}