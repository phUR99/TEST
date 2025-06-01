
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
#1517

*/

long long arr[1000005];
long long tree[4000050];
long long lazy[4000050];
vector<int> idx;

int n, m, k;

void update_lazy(int startidx, int endidx, int node) {
	if (lazy[node]) {
		tree[node] += (lazy[node] * (endidx - startidx + 1));
		if (startidx != endidx) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

long long query(int left, int right, int node, int qLeft, int qRight) {
	update_lazy(left, right, node);

	if (left > qRight || right < qLeft) return 0;
	else if (left >= qLeft && right <= qRight) {
		return tree[node];
	}
	else
	{
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 + 1, qLeft, qRight);
	}
}



void update(int left, int right, int node, int qLeft, int qRight, long long diff) {

	update_lazy(left, right, node);
	if (left > qRight || right < qLeft) return;

	if (left >= qLeft && right <= qRight) {
		lazy[node] += diff;
		update_lazy(left, right, node);
		return;
	}
	int mid = (left + right) / 2;
	update(left, mid, node * 2, qLeft, qRight, diff);
	update(mid + 1, right, node * 2 + 1, qLeft, qRight, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}




int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int s = 1;
	cin >> n >> m >> k;

	while (s < n)
	{
		s *= 2;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		tree[s + i] = arr[i];
	}
	for (int i = s - 1; i > 0; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	int t = m + k;

	while (t--)
	{
		int a, b, c;
		long long d;

		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, s, 1, b, c, d);
		}
		else
		{
			cin >> b >> c;
			cout << query(1, s, 1, b, c) << '\n';
		}
	}


	return 0;
}
