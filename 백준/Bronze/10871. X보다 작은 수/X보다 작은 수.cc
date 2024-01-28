#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, tmp;
	cin >> n >> x;
	while (n--)
	{
		cin >> tmp;
		if (tmp < x) cout << tmp << ' ';
	}
	return 0;
}