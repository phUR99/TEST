#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int pp[128][128];
int cnt[2];
bool check(int n, int x, int y) {
	for (int i = x; i < n+x; i++)
	{
		for (int j = y; j < n+y; j++)
		{
			if (pp[x][y] != pp[i][j]) return false;
		}
	}
	return true;
}
void func(int n, int x, int y) {
	if (check(n, x, y)) {
		cnt[pp[x][y]] += 1;
		return;
	}
	n = n / 2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			func(n, x + i * n, y + j * n);
		}
	}
	
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> pp[i][j];
		}
	}
	func(n, 0, 0);
	for (int i = 0; i < 2; i++)
	{
		cout << cnt[i] << '\n';
	}

}
