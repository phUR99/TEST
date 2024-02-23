#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*



*/
struct node
{
	int x, y;
	bool operator<(const node& a) {
		if (a.x == x) {
			return a.y > y;
		}
		return a.x < x;
		
	}
};
node arr[75005];
int h[75005];
int tree[300000];

int query(int left, int right, int node, int qLeft, int qRight) {
	if (left > qRight || right < qLeft) {
		return 0;
	}
	else if (left >= qLeft && right <= qRight) {
		return tree[node];
	}
	else
	{
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 + 1, qLeft, qRight);
	}

}
void update(int left, int right, int node, int target) {
	if (left > target || right < target) return;
	else
	{
		tree[node] += 1;
		if (left == right) return;
		int mid = (left + right) / 2;
		update(left, mid, node * 2, target);
		update(mid + 1, right, node * 2 + 1, target);
	}


}

int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;

	while (t--)
	{
		int n;
		int s = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].x >> arr[i].y;
			h[i] = arr[i].y;
		}
		sort(arr, arr + n);
		sort(h, h + n);
		while (s < n)
		{
			s *= 2;
		}
		long long ans = 0;
	
		for (int i = 0; i < n; i++)
		{
			int l = lower_bound(h, h + n, arr[i].y + 0.1) - h;
			ans += query(1, s, 1, 1, l);
			update(1, s, 1, l);
		}

		cout << ans << '\n';

		fill(h, h + n, 0);
		fill(tree, tree + 4 * n + 1, 0);
		
	}
	return 0;
}