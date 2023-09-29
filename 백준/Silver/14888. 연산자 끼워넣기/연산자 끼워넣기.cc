#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>

#define MAX 1000000001
#define MIN -1000000001

using namespace std;
int n;
int arr[15];
int num[4];
int used[4];
int M = MIN, m = MAX;

int op(int a, int b, int i) {
	switch (i)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
}

void func(int k, int sum) {
	if (k == n - 1) {
		M = max(M, sum);
		m = min(m, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (num[i] > used[i]) {
			used[i]++;
			func(k + 1, op(sum, arr[k + 1], i));
			used[i]--;
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}
	func(0, arr[0]);
	cout << M << '\n' << m;
}

