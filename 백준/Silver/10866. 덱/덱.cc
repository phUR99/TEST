#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> D;
	int n;
	cin >> n;
	string temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		if (temp == "push_front") {
			int v;
			cin >> v;
			D.push_front(v);
		}
		else if (temp == "push_back") {
			int v;
			cin >> v;
			D.push_back(v);
		}
		else if (temp == "pop_front") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		else if (temp == "pop_back") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		else if (temp == "size") cout << D.size() << '\n';
		else if (temp == "empty") cout << D.empty() << '\n';
		else if (temp == "front") {
			if (D.empty()) cout << -1 << '\n';
			else cout << D.front() << '\n';

		}
		else if (temp == "back") {
			if (D.empty()) cout << -1 << '\n';
			else cout << D.back() << '\n';

		}
	}
}