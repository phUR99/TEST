#include <bits/stdc++.h>
using namespace std;
/*
#10090 : counting query 구현하기


*/
int tree[4000005];

int query(int left, int right, int node, int qLeft, int qRight) {
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
void update(int left, int right, int node, int target) {
	if (left > target || right < target) return;
	else
	{
		tree[node] += 1;
		if (left == right)
		{
			return;
		}
		int mid = (left + right) / 2;
		update(left, mid, node * 2, target);
		update(mid + 1, right, node * 2 + 1, target);
	}

}
int n, s = 1, tmp;
long long ans = 0;


int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	
	cin >> n;
	while (s <n)
	{
		s *= 2;
	}
	
	while (n--)
	{
		cin >> tmp;
		ans += query(1, s, 1, tmp, s);
		update(1, s, 1, tmp);
	}
	
	cout << ans;
	
	
	
	
	
	
	/////////////////////////////////////////////////////////////////
	return 0;
}