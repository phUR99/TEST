#include <bits/stdc++.h>
using namespace std;
/*
#12899 : 카운팅 쿼리 구현하기
*/
int tree[8'000'005];
int n, s = 1;

int query(int left, int right, int node, int target) {
	if (left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	if (tree[node*2] >= target)
	{
		return query(left, mid, node * 2, target);
	}
	else
	{
		return query(mid + 1, right, node * 2 + 1, target - tree[node * 2]);
	}
}
void update(int left, int right, int node, int target, int diff) {
	if (target < left || target > right) return;

	tree[node] += diff;
	if (left == right) return;
	int mid = (left + right) / 2;
	update(left, mid, node * 2, target, diff);
	update(mid + 1, right, node * 2 + 1, target, diff);
}


int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n;
	while (s < 2000000)
	{
		s *= 2;
	}
	while (n--)
	{
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			update(1, s, 1, x, 1);
		}
		else
		{
			
			int target = query(1, s, 1, x);
			update(1, s, 1, target, -1);
			cout << target << '\n';
		}
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}