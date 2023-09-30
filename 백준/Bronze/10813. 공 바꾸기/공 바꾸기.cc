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
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	while (m--)
	{
		int st, end;
		cin >> st >> end;
		int temp;
		temp = arr[end];
		arr[end] = arr[st];
		arr[st] = temp;

	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << ' ';
	}
}
