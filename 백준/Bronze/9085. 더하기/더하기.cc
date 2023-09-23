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
	int T, N, ans;
	cin >> T;
	while (T--)
	{
		int temp;
		cin >> N;
		ans = 0;
		while (N--) {			
			cin >> temp;
			ans += temp;
		}
		cout << ans << '\n';
	}

}
