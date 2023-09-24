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
vector<int> a;
int num[30];

bool isused[30];
int n, m;
int cnt = 0;

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
		{
			cout << a[num[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	int st = 0;
	if (k != 0) st = num[k - 1];

	for (int i = st; i < n; i++)
	{
		if (!isused[i]) {
			num[k] = i;
			isused[i] = true;
			func(k + 1);
			isused[i] = false;
		}
	}

}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	func(0);
}

