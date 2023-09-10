#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
//1. 많이 헤맸던 부분: 더하는 것을 어느 시점에서 하느냐에 대해서 많이 헤맸다.
//2. 해결책: 괄호가 닫혔는 지 확인하고 이를 나누면 해결할 수 있었다.
//3. 문자열을 다루는 것에서 이전 문자를 확인하는 것을 생각하지 못했다.
//4. 나누는 것을 생각하지 못했다. 나누면서 괄호가 닫히는 것을 처리하면 됐는데 이것을 생각히지 못해서 많이 헤맸다.
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char> s;
	string str;
	cin >> str;
	int ans = 0;
	int tmp = 1;
	for (int i =0; i <str.size(); i++)
	{
		if (str[i] == '(') {
			tmp *= 2;
			s.push(str[i]);

		}
		else if (str[i] == '[') {
			tmp *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			if (str[i-1] == '(') ans += tmp;
			s.pop();
			tmp /= 2;
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i-1] == '[') ans += tmp;
			s.pop();
			tmp /= 3;
		}

	}
	if (s.empty()) cout << ans;
	else cout << 0;
	return 0;
}
