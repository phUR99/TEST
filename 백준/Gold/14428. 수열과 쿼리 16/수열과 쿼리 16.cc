#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#define INF LLONG_MAX

using namespace std;

int N, M;
long long Index[100001];
vector<long long> Tree;

long long segment_tree(int st, int fin, int node) {
	if (st == fin) return Tree[node] = st;
	int mid = (st + fin) / 2;
	long long left = segment_tree(st, mid, node * 2);
	long long right = segment_tree(mid + 1, fin, node * 2 + 1);
	if (Index[left] > Index[right]) return Tree[node] = right;
	else if (Index[left] < Index[right]) return Tree[node] = left;
	else return Tree[node] = min(left, right);
}

long long change_tree(int st, int fin, int node, int loc) {
	if (loc < st || loc > fin) return Tree[node];
	if (st == fin) return Tree[node];
	int mid = (st + fin) / 2;
	long long left_index = change_tree(st, mid, node * 2, loc);
	long long right_index = change_tree(mid + 1, fin, node * 2 + 1, loc);
	if (Index[left_index] > Index[right_index]) return Tree[node] = right_index;
	else if (Index[left_index] < Index[right_index]) return Tree[node] = left_index;
	else return Tree[node] = min(left_index, right_index);
}

long long return_tree(int st, int fin, int left, int right, int node) {
	if (left > fin || right < st) return INF;
	if (left <= st && right >= fin) return Tree[node];
	int mid = (st + fin) / 2;
	long long left_index = return_tree(st, mid, left, right, node * 2);
	long long right_index = return_tree(mid + 1, fin, left, right, node * 2 + 1);
	// 두 값중 하나가 INF가 나올 경우 오류를 방지하기 위함
	if (left_index == INF) return right_index;
	if (right_index == INF) return left_index;
	if (Index[left_index] > Index[right_index]) return right_index;
	else if (Index[left_index] < Index[right_index]) return left_index;
	else return min(left_index, right_index);
}

void solve() {
	int height = ceil(log2(N));
	Tree.resize(1 << (height + 1));
	segment_tree(0, N - 1, 1);
	cin >> M;
	for (int i = 1; i <= M; i++) {
		long long a, x, y;
		scanf("%lld  %lld  %lld", &a, &x, &y);
		if (a == 1) { // x번째 칸을 y로 바꾼다.
				Index[x - 1] = y;
				change_tree(0, N - 1, 1, x - 1);
		}
		else {
			cout << return_tree(0, N - 1, x - 1, y - 1, 1) + 1 << "\n";
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%lld", &Index[i]);
	solve();
	return 0;
}
