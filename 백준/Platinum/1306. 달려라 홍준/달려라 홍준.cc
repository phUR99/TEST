#include <bits/stdc++.h>
using namespace std;
/*
#12899 : 카운팅 쿼리 구현하기
*/
int tree[4'000'005];
int n, s = 1, m;

int query(int left, int right, int node, int qLeft, int qRight) {
	if (left > qRight || right < qLeft) return 0;
	else if (left >= qLeft && right <= qRight) {
		return tree[node];
	}
	else
	{
		int mid = (left + right) / 2;
		return max(query(left, mid, node * 2, qLeft, qRight), query(mid + 1, right, node * 2 + 1, qLeft, qRight));
	}
}
void update(int left, int right, int node, int target, int diff) {
	if (target < left || target > right) return;

	tree[node] = max(diff, tree[node]);
	if (left == right) return;
	int mid = (left + right) / 2;
	update(left, mid, node * 2, target, diff);
	update(mid + 1, right, node * 2 + 1, target, diff);
}


int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> n >> m;
	while (s < n)
	{
		s *= 2;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tree[s + i];
	}
	for (int i = s-1; i > 0; i--)
	{
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}
	for (int i = m; i <= n - m +1; i++)
	{
		int left = i - (m - 1);
		int right = i + (m - 1);
		cout << query(1, s, 1, left, right) << ' ';
	}


	/////////////////////////////////////////////////////////////////
	return 0;
}