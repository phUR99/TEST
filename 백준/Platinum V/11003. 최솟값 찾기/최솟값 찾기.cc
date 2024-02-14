#include <bits/stdc++.h>
using namespace std;
int arr[5'000'005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dq.empty() && dq.front() < i - l + 1) dq.pop_front();
		while (!dq.empty() && arr[dq.back()] > arr[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
		cout << arr[dq.front()] << ' ';
	}
}