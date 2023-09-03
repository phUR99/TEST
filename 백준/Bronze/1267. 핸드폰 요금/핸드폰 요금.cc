#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, time;
	int y = 0, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> time;
		y += time / 30 * 10 + 10;
		m += time / 60 * 15 + 15;
		
	}
	if (y == m) cout << "Y M " << y;
	else if (y > m) cout << "M " << m;
	else cout << "Y " << y;

}