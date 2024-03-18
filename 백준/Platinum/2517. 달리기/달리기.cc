#include <bits/stdc++.h>
using namespace std;

int tree[2000005];
int n;
int s = 1;
int nums[500005];

// 인덱스 트리의 인덱스 : 실력, 트리의 원소 : 자신 기준 왼쪽에 있는 원소의 개수 
// 현재 순위대로 값을 넣어주면서 자신의 왼쪽에 들어가는 사람을 체크한다.

// 쿼리
int query(int left, int right, int node, int qleft, int qright) {	
	//1. 범위 값을 벗어나는 경우
	if (qright < left || right < qleft) {
		return 0; //영향이 없는 값 반환
	}
	//2. 쿼리 범위 내
	else if (qleft <= left && right <= qright) {
		return tree[node];
	}
	//3. 걸쳐 있을 때
	else
	{
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, qleft, qright) + query(mid + 1, right, node * 2 + 1, qleft, qright);
	}
}
void update(int left, int right, int node, int target) {
	//1. 타겟과 무관한 경우
	if (target < left || right < target) {
		return;
	}
	//2. 타겟 연관
	else
	{
		tree[node] += 1;
		if (left != right) {
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target);
			update(mid + 1, right, node * 2 + 1, target);
		}
	}
}
// 업데이트


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (s < n)
	{
		s *= 2;
	}
	vector<pair<int, int>> v;
	vector<int> pri;
	// 점수를 받아서 좌표압축
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		pri.push_back(nums[i]);
	}
	sort(pri.begin(), pri.end());
	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(pri.begin(), pri.end(), nums[i]) - pri.begin();
		v.push_back({ i + 1, n - it});
	}
	for (auto e : v)
	{
		update(1, s, 1, e.second);
		cout << query(1, s, 1, 1, e.second) << '\n';

	}
	// 현재 순위대로 정렬
    return 0;
}