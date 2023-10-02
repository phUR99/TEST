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
int arr[100001];
int ans[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		ans[i] = arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		ans[i] = max(ans[i], ans[i - 1] + arr[i]);
		
	}
	cout << *max_element(ans + 1, ans + n + 1);
}