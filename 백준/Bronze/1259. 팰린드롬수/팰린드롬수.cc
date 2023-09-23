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
	while (true)
	{
		string temp;
		bool check = false;
		cin >> temp;
		if (temp == "0") break;
		if (temp.size() == 1) {
			cout << "yes\n";
			continue;

		}
		for (int i = 0; i < temp.size() / 2; i++)
		{
			if (temp[i] != temp[temp.size() - 1 - i]) {
				check = true;
				break;
			}
		}
		if (check) cout << "no\n";
		else cout << "yes\n";
	}


}
