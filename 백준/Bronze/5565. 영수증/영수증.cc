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
	int total;
	cin >> total;
	for (int i = 0; i < 9; i++)
	{
		int temp;
		cin >> temp;
		total -= temp;
	}
	cout << total;
}
