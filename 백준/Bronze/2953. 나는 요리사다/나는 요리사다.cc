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
	int ans, prize = 0;

	while (n--)
	{
		int temp_v = 0;
		for (int i = 0; i < 4; i++)
		{
			int temp;
			cin >> temp;
			temp_v += temp;
		}
		if (prize <= temp_v) {
			ans = 5 - n;
			prize = temp_v;
		}
	}
	cout << ans << " " << prize;

}
