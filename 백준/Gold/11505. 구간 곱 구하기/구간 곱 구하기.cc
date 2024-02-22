#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
11505 : 쿼리 -

*/

const long long d = 1'000'000'000 + 7;
long long  tree[4'000'005];
int n, m, k;

long long query(int left, int right, int node, int qLeft, int qRight) {
	if (left > qRight || right < qLeft) return 1;
	else if (left >= qLeft && right <= qRight) {
		return tree[node] % d;
	}
	else
	{
		int mid = (left + right) / 2;
		return (query(left, mid, node * 2, qLeft, qRight) * query(mid + 1, right, node * 2 + 1, qLeft, qRight)) % d;
	}
}
long long update(int left, int right, int node, int target, long long m) {
	if (left > target || right < target)
	{
		return tree[node];
	}
	if (left == right)
	{
		return tree[node] = m;
	}
	else
	{
		
		int mid = (left + right) / 2;			
		return tree[node] = update(mid + 1, right, node * 2 + 1, target, m) * update(left, mid, node * 2, target, m) % d;
	
	}
}


int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n;
	int s = 1;
	cin >> n >> m >> k;
	
	while (s < n)
	{
		s *= 2;
	}

	fill(tree + 1, tree + s + 1, 1);
	for (int i = 0; i < n; i++)
	{
		cin >> tree[s + i];
	}
	for (int i = s-1; i > 0; i--)
	{
		tree[i] = (tree[2 * i] * tree[2 * i + 1]) % d;
	}
	int t = m + k;

	while (t--)
	{
		int a;
		cin >> a;

		if (a==1)
		{
			int b;
			long long c;
			cin >> b >> c;
			update(1, s, 1, b, c);
		}
		else
		{
			int b, c;
			cin >> b >> c;
			cout << query(1, s, 1, b, c) << '\n';
		}
	}
	 
	return 0;
}