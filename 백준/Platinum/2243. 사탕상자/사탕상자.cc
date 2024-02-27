#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>

using  namespace std;
int s = 1;
int tree[4000005];
int n, a, b, c;

//. 그림 기억하기
int query(int left, int right, int node, int target) {
	// 리프 노드일 경우 인덱스를 반환
	if (left == right) {
		return left;
	}
	//1. 왼쪽 자식이 타겟의 값보다 크거나 같다면 왼쪽으로 쿼리를 수행
	int mid = (left + right) / 2;
	if (tree[node * 2] >= target) {
		return query(left, mid, node * 2, target);
	}
	//2. 작다면 타겟의 값을 왼쪽 자식의 노드의 값만큼 수정한 후 오른쪽으로 쿼리를 수행
	else
	{
		return query(mid + 1, right, node * 2 + 1, target - tree[node * 2]);
	}

}

void update(int left, int right, int node, int target, int diff) {
	//1. 타겟과 무관한 경우
	if (target < left || right < target) {
		return;
	}
	//2. 타겟 연관
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

/*
long long bQuery(int qleft, int qright) {
	int leftNode = s - 1 + qleft;
	int rightNode = s - 1 + qright;
	long long sum = 0;
	while (leftNode <= rightNode)
	{
		if (leftNode % 2 == 1) {
			sum += tree[leftNode++];
		}
		if (rightNode % 2 == 0) {
			sum += tree[rightNode--];
		}
		leftNode /= 2;
		rightNode /= 2;
	}
	return sum;
}

void bUpdate(int target, long long value) {
	int node = s + target - 1;
	tree[node] = value;
	node /= 2;
	while (node > 0)
	{
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		node /= 2;		
	}
}
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	//init
	while (s < 1e6) s *= 2;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1) {
			cin >> b;
			int cnt = query(1, s, 1, b);
 			cout <<  cnt << '\n';
			update(1, s, 1, cnt, -1);
		}
		else
		{
			cin >> b >> c;
			update(1, s, 1, b, c);
		}
	}

	//system("pause");
	return 0;

}
