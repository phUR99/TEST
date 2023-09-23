#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> num;
	int n;
	cin >> n;
	while (n--)
	{
		int temp; cin >> temp;
		num.push_back(temp);
	}

	int cnt = 0;
	for (auto i : num)
	{
		if (i == 1) continue;
		if (i == 2 || i == 3) {
			cnt++;
			continue;
		}
		bool check = false;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0) {
				check = true;
				break;
			}
		}
		if (!check) cnt++;
	
	}
	cout << cnt;
}
