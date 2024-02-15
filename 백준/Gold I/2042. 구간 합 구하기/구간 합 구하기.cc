#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>

using  namespace std;
int n, m, k;
int s = 1;
long long tree[20000005];
long long nums[1000005];


//. 그림 기억하기
long long query(int left, int right, int node, int qleft, int qright) {
	//1. 쿼리 범위 밖
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
void update(int left, int right, int node, int target, long diff) {
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	//init
	while (s < n) s *= 2;
	for (int i = 0; i < n; i++)
	{
		tree[s + i] = nums[i];

	}
	for (int i = s-1; i > 0 ; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	for (int i = 0; i < m+k; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			// a가 1인 경우 b(1 ≤ b ≤ N)번째 수를 c로 바꾸고			
			bUpdate(b, c);
		}
		else {
			// a가 2인 경우에는 b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합
			cout << bQuery(b, c) << '\n';
		}
	}
	// system("pause");
	return 0;

}
