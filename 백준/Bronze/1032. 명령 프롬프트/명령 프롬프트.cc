#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	if (t == 1) {
		string temp;
		cin >> temp;
		cout << temp;
		return 0;
	}
	string cur = "";
	while (t--)
	{
		string temp;
		cin >> temp;
		if (cur.empty()) {
			cur = temp;
			continue;
		}
		for (int i = 0; i < cur.size(); i++)
		{
			if (cur[i] != temp[i]) cur[i] = '?';
		}
	}
	cout << cur;

}
