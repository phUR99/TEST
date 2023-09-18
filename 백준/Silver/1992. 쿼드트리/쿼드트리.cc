#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
char pp[64][64];
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
		cout << pp[x][y];
		return;
	}
	n = n / 2;
	cout << "(";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			func(n, x + i * n, y + j * n);
		}
	}
	cout << ")";
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			pp[i][j] = temp[j];
		}
	}
	func(n, 0, 0);


}
