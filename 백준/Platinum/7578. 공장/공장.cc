#include <bits/stdc++.h>
using namespace std;

/*
인덱스 트리 구성
	인덱스의 정보 : 윗 열의 순서
	내용의 정보 : 아랫 열의 순서
	쿼리의 구현 : 자신보다 오른쪽에 있는 원소의 수를 반환한다
	업데이트의 구현 : 타겟 노드에 대해서 +1

	정렬 시 벡터의 선언으로 인해서 시간 복잡도가 크게 늘어났다.
	해결방법: 두 번쨰로 받는 배열은 순서 기준으로 일련번호를 저장하는 것이 아닌 일련번호 기준으로 순서를 저장하게 만든다.
	이후 쿼리를 수행할 때 arr 배열의 일련번호를 이용해서 num 배열에서 순서를 찾는다.
*/

int tree[2000005];
int s = 1;
int n;
int arr[500005], num[1000001];

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
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		num[tmp] = i;
	}

	long long ans = 0;

	for (int i =0; i <n; i++)
	{
		
		ans += query(1, s, 1, num[arr[i]]+1, s);
		update(1, s, 1, num[arr[i]] + 1);
	}
	cout << ans;
	return 0;
}