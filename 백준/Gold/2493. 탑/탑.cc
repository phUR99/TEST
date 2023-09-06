#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> h;
	h.push(make_pair(100000001, 0));
	int n;
	cin >> n;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		while (h.top().first < temp)
		{
			h.pop();
		}
		cout << h.top().second << " ";
		h.push(make_pair(temp, i));
	}

}