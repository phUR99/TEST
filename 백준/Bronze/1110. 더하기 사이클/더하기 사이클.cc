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
	string a;
	cin >> a;
	int origin = stoi(a);
	int cnt = 0;
	while (true)
	{
		if (a.size() == 1) {
			a += a;
		}
		else
		{
			int temp = 0;
			for (int i = 0; i < 2; i++)
			{
				temp += a[i] - '0';
			}
			if (temp >= 10) temp %= 10;
			swap(a[0], a[1]);
			a[1] = temp + '0';
		}
		cnt++;
		if (stoi(a) == origin) {
			cout << cnt;
			break;
		}
	}

}
