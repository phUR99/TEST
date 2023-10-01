#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> vec;
	while (n--)
	{
		long long tmp; cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	int cnt = 0, temp_cnt=0;
	long long ans = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (i == 0 || vec[i - 1] == vec[i]) cnt++;
		else
		{
			if (cnt > temp_cnt) {
				temp_cnt = cnt;
				ans = vec[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > temp_cnt)
	{
		ans = vec[vec.size() - 1];
	}
	cout << ans;
	
}
