#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
int arr[100];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int st, end, num;
		cin >> st >> end >> num;
		fill(arr + st, arr + end+1, num);

	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << ' ';
	}
}
