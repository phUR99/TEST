#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	stack<char> s;
	string temp;
	while (n--)
	{
		
		getline(cin, temp);
		for (auto i : temp)
		{
			if (i == ' ') {
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << i;
			}
			else s.push(i);
		}
		if (!s.empty()) {
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << '\n';
		}
	}
}
