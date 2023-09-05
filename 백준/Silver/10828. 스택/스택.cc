#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push") {
			int temp;
			cin >> temp;
			s.push(temp);
		}
		else if (str == "pop") {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (str == "size") cout << s.size() << "\n";
		else if (str == "empty") cout << s.empty() << '\n';
		else {
			if (s.empty()) cout << -1 << '\n';
			else cout << s.top() << '\n';
		}
	}
}