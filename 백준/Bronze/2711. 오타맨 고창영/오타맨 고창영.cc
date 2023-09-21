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
	int n;
	cin >> n;
	while (n--)
	{
		int k; string temp;

		cin >> k >> temp;
		temp.erase(k - 1, 1);
		cout << temp << '\n';
	}
}
