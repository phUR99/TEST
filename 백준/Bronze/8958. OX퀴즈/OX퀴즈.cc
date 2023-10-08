#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>
int arr[15];
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int ans = 0, cnt=0;
		for (auto i : str)
		{
			if (i == 'X') cnt = 0;
			else {
				cnt++;
				ans += cnt;
			}
		}
		cout << ans << '\n';
	}
	
}