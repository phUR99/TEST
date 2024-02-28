#include <bits/stdc++.h>
using namespace std;
/*

*/
const long long d = 1'000'000'000 + 7;
long long tree[800005], treeCnt[800005];
int n, s = 1;
long long query(int left, int right, int node, int qLeft, int qRight) {
	if (left > qRight || right < qLeft) return 0;
	else if (left >= qLeft && right <= qRight)
	{
		return tree[node];
	}
	else
	{
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 +1, qLeft, qRight);
	}
}
long long queryCnt(int left, int right, int node, int qLeft, int qRight) {
	if (left > qRight || right < qLeft) return 0;
	else if (left >= qLeft && right <= qRight)
	{
		return treeCnt[node];
	}
	else
	{
		int mid = (left + right) / 2;
		return queryCnt(left, mid, node * 2, qLeft, qRight) + queryCnt(mid + 1, right, node * 2 + 1, qLeft, qRight);
	}
}
void update(int left, int right, int node, int target, int x) {
	if (target < left || target > right) return;
	
	tree[node] += x;
	if (left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	update(left, mid, node * 2, target, x);
	update(mid + 1, right, node * 2 + 1, target, x);
}
void updateCnt(int left, int right, int node, int target) {
	if (target < left || target > right) return;

	treeCnt[node] += 1;
	if (left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	updateCnt(left, mid, node * 2, target);
	updateCnt(mid + 1, right, node * 2 + 1, target);
}

int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n;
	while (s < 400000)
	{
		s *= 2;
	}
	long long ans = 1;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x++;

		if (i == 0) {
			updateCnt(1, s, 1, x);
			update(1, s, 1, x, x - 1);
		}
		else
		{

			long long leftSum = ((x-1) * queryCnt(1, s, 1, 1, x) - query(1, s, 1, 1, x)) %d;			
			long long rightSum = (query(1, s, 1, x, s) - (x - 1) * queryCnt(1, s, 1, x, s)) %d;			
			ans %= d;
			ans *= (rightSum + leftSum);
			ans %= d;
			updateCnt(1, s, 1, x);
			update(1, s, 1, x, x-1);			
		}
	}
	cout << ans;

	/////////////////////////////////////////////////////////////////
	return 0;
}