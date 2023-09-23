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
	int n = 5;
	int ans = 0;
	while (n--)
	{
		int temp;
		cin >> temp;
		ans += temp;
	}
	cout << ans;

}
