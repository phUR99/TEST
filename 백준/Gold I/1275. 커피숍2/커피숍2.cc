#include <bits/stdc++.h>
using namespace std;


int s = 1, n, q;
int nums[100005];
long long tree[400005];

long long query(int left, int right, int node, int qleft, int qright) {
	//1. 관련이 없을 때 
	if (qleft > right || qright < left) return 0;
	//2. 완전히 겹칠 때
	else if (right <= qright && left >= qleft) return tree[node];
	//3. 일부만 겹칠 때
	else
	{
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, qleft, qright) + query(mid + 1, right, node * 2 + 1, qleft, qright);
	}
}
void update(int left, int right, int node, int target, long long diff) {
	//1. 타겟과 연관 X
	if (target < left || target > right) return;
	//2. 타겟과 연관 O
	else
	{
		tree[node] += diff;
		if (left != right) {
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target, diff);
			update(mid + 1, right, node * 2 + 1, target, diff);
		}
	}
}




int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	while (s < n)
	{
		s *= 2;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		tree[s + i] = nums[i];
	}
	for (int i = s-1; i > 0; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	while (q--)
	{
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << query(1, s, 1, x, y) << '\n';
		update(1, s, 1, a,  b - tree[s + a -1]);
	}

}