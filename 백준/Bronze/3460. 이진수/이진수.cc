#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
char arr[5] = { 'a', 'e', 'i', 'o', 'u' };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		int temp;
		cin >> temp;
		int ans = 0;
		while (temp > 0)
		{
			if (temp & 1) cout << ans << ' ';
			temp = temp >> 1;
			ans++;
		}
	}

}
