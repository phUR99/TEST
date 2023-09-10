#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

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
