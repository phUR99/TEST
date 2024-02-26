#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 0;
	while (true)
	{
		if (N%5==0)
		{
			cnt += N / 5;
			cout << cnt;
			break;
		}
		if (N < 3)
		{
			cout << -1;
			break;
		}
		N -= 3;
		cnt++;

	}
}