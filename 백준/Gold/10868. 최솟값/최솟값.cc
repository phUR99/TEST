#include <bits/stdc++.h>
using namespace std;
/*
쿼리 1 : 두 자식 노드의 값 중 최솟값을 정보로 갖는다.
쿼리 2 : 두 자식 노드의 값 중 최댓값을 정보로 갖는다.
인덱스 트리로 설계시 인덱스 트리의 정보 쓰기 N * 2
쿼리 요청시 logN * m 100000log100000 예상

*/
int curMin, curMax;
int mTree[400005], MTree[400005];
int m, M, n, k;

void minQuery(int left, int right, int node, int qLeft, int qRight) {
	//1. 쿼리에 포함이 되지 않을 때
	if (left > qRight || right < qLeft) return;
	else if(qLeft <= left && right <= qRight)
	{
		m = min(m, mTree[node]);
		return;
	}
	else
	{
		int mid = (left + right) / 2;
		minQuery(left, mid, node * 2, qLeft, qRight);
		minQuery(mid + 1, right, node * 2 + 1, qLeft, qRight);
		return;
	}
}
void maxQuery(int left, int right, int node, int qLeft, int qRight) {
	//1. 쿼리에 포함이 되지 않을 때
	if (left > qRight || right < qLeft) return;
	else if (qLeft <= left && right <= qRight)
	{
		M = max(M, MTree[node]);
		return;
	}
	else
	{
		int mid = (left + right) / 2;
		maxQuery(left, mid, node * 2, qLeft, qRight);
		maxQuery(mid + 1, right, node * 2 + 1, qLeft, qRight);
		return;
	}
}

int s = 1;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	while (s < n)
	{
		s *= 2;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> mTree[s + i];
		MTree[s + i] = mTree[s + i];
	}
	for (int i = s - 1; i > 0 ; i--)
	{
		mTree[i] = min(mTree[i * 2], mTree[i * 2 + 1]);
		MTree[i] = max(MTree[i * 2], MTree[i * 2 + 1]);
	}

	while (k--)
	{
		int l, r;
		cin >> l >> r;
		m = 1e9 + 1;
		M = 0;
		minQuery(1, s, 1, l, r);
		//maxQuery(1, s, 1, l, r);
		cout << m << '\n';
	}
}