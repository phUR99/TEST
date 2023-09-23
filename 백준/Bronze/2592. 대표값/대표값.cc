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
	n = 10;
	int ans = 0;
	
	vector<int> vec;
	
	while (n--)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
		ans += temp;
	}
	sort(vec.begin(), vec.end());
	int rate_v = 0;
	int rate = 0;
	for (auto i :vec)
	{
		int temp = upper_bound(vec.begin(), vec.end(), i) - lower_bound(vec.begin(), vec.end(), i);
		if (rate < temp) {
			rate = temp;
			rate_v = i;
		}
	}
	cout << ans/10 << '\n' << rate_v;

}
