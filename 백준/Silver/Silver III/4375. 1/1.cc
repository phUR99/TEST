#include <bits/stdc++.h>
using namespace std;

/*


*/


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(a % b, b);
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	int tmp, a, cnt;

	while (cin >> tmp)
	{
		a = 1;
		cnt = 1;
		while (true)
		{
			if (a % tmp == 0) break;
			else
			{
				cnt++;
				a = 10 * a + 1;
				a %= tmp;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}