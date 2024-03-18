#include <bits/stdc++.h>
using namespace std;

long long x, y, z;

int main() {
    ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y;
	z = (y * 100) / x;
	if (z >= 99) {
		cout << -1;
		return 0;
	}
	int st = 0, ed = 1e9;
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		long long cur = (y + mid) * 100 / (x + mid);
		if (z < cur) ed = mid - 1;
		else st = mid + 1;
	}
	cout << st;
}