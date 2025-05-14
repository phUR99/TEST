#include <bits/stdc++.h>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int arr[105];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n;

	long long MV = 1e9;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		pq.push(arr[i]);

	}
	long long cur = 0;

	while (n--)
	{
		cur = pq.top();
		pq.pop();
		for (int i = 0; i < k; i++)
		{
			pq.push(cur * arr[i]);
			if (cur % arr[i] == 0) break;
		}
	}

	cout << cur;
}