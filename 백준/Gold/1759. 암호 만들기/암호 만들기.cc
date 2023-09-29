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
int n, k;
char arr[20];
char odd[5] = { 'a', 'e', 'i', 'o', 'u' };
char ans[20];

void func(int cnt, int cur) {
	if (cnt == k) {
		int c = 0;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (ans[i] == odd[j]) c++;
			}
			
		}
		if (c < 1 || k - c < 2) return;
		for (int i = 0; i < k; i++)
		{
			cout << ans[i];
		}
		cout << '\n';
		return;
	}
	for (int i = cur; i < n; i++)
	{
		ans[cnt] = arr[i];
		func(cnt + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0, 0);
}

