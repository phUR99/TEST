#include <bits/stdc++.h>
using namespace std;
/*
#FENCE : 분할정복으로 풀기

*/

long long arr[100005];
int n;

long long solve(int left, int right) {
	if (left == right) return arr[left];

	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));

	int lidx = mid, ridx = mid + 1;
	long long height = min(arr[lidx], arr[ridx]);
	ret = max(ret, height * 2);

	while (lidx > left || ridx < right)
	{
		if (ridx < right && (lidx == left || arr[lidx - 1] < arr[ridx + 1])) {
			ridx++;
			height = min(height, arr[ridx]);
		}
		else
		{
			lidx--;
			height = min(height, arr[lidx]);
		}
		ret = max(ret, height * (ridx - lidx + 1));
	}
	return ret;
}



int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	long long ans = solve(0, n - 1);
	cout << ans;
	/////////////////////////////////////////////////////////////////
	return 0;
}