#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	int n;
	cin >> n;
	string temp;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		if (temp == "push") {
			int v;
			cin >> v;
			q.push(v);
		}
		else if (temp == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (temp == "pop") {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (temp == "size") cout << q.size() << '\n';
		else if (temp == "empty") cout << q.empty() << '\n';
		else
		{
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";

		}
	}
}