#include <bits/stdc++.h>
using namespace std;

/*
인덱스 트리 구성
	인덱스의 정보 : 윗 열의 순서
	내용의 정보 : 아랫 열의 순서
	쿼리의 구현 : 자신보다 오른쪽에 있는 원소의 수를 반환한다
	업데이트의 구현 : 타겟 노드에 대해서 +1
*/

long long tree[2000005];
int s = 1;
int n;
int arr[500005], o[500005];
vector<pair<int, int>> v1, v2;
map<int, pair<int, int>> info;

long long query(int left, int right, int node, int qleft, int qright) {
	//1. 타겟을 벗어났을 때
	if ( qright < left || right  < qleft) return 0;
	//2. 사이에 들어왔을 때
	else if (left >= qleft && right <= qright) return tree[node];
	//3. 겹칠 때
	else
	{
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, qleft, qright) + query(mid + 1, right, node * 2 + 1, qleft, qright);
	}
}
void update(int left, int right, int node, int target) {
	//1. 타겟과 무관
	if (left > target || right < target) return;
	//2. 타겟 연관
	else {
		tree[node] += 1;
		if (left != right) {
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target);
			update(mid + 1, right, node * 2 + 1, target);
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (s < n)
	{
		s *= 2;
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		info[tmp].first = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		info[tmp].second = i + 1;
	}
	vector<pair<int, int>> v;
	for (auto it : info)
	{
		v.push_back({ it.second.first, it.second.second });
	}
	sort(v.begin(), v.end());
	long long ans = 0;

	for (auto e : v)
	{
		
		ans += query(1, s, 1, e.second, s);
		update(1, s, 1, e.second);
	}
	cout << ans;
	return 0;
}