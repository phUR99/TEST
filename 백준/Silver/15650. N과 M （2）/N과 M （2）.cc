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
int arr[30];
bool isused[30];
int n, m;
int cnt = 0;
void func(int k) {
	//base condition
	if (k == m) {
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int st = 1;
	if (k != 0) st = arr[k - 1] + 1;
	for (int i = st; i <= n; i++)
	{
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = true;
			func(k + 1);
			isused[i] = false;
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);

}

