#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
char arr[10000][10000];
void func(int n, int x, int y) {
	if (n == 1) {
		arr[x][y] = '*';
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			func(n / 3, x + i * n / 3, y + j * n/ 3);
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
		fill(arr[i], arr[i] + n, ' ');
	}
	func(n, 0, 0);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}


}
