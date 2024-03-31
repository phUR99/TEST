#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

vector<pair<int, int>> unit = { {-1,0},{1,0},{0,-1},{0,1} };

int in_range(int n, int i, int j) {
	if (i < 0 || j < 0 || j >= n || i >= n) return 0;
	else return 1;
}

int delete_biggest(vector<vector<int>>& A) {

	pii biggest_pos = { -1,-1 };
	int biggest_zero = 0;
	set<pii> biggest;
	int n = A.size();

	vector<vector<int>> check(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 1) continue;
			if (A[i][j] <= 0) continue;
			int zeros = 0;

			queue<pair<int, int>> Q;
			Q.push({ i,j });
			set<pii> cur_blocks;
			cur_blocks.insert({ i,j });
			check[i][j] = 1;

			while (Q.size() > 0) {
				pii cur = Q.front(); Q.pop();				
				for (auto& d : unit) {
					pii next = { cur.first + d.first, cur.second + d.second };
					if (in_range(n, next.first, next.second) == 0) {
						continue;
					}
					if (A[next.first][next.second] < 0) continue;

					if (A[next.first][next.second] > 0 && A[next.first][next.second] != A[i][j])
						continue;
					if (cur_blocks.find(next) != cur_blocks.end()) continue;
					if (A[next.first][next.second] == 0) zeros += 1;

					Q.push({ next.first,next.second });
					cur_blocks.insert(next);
					if (A[next.first][next.second] != 0) check[next.first][next.second] = 1;
				}
			}
			if (biggest.size() < cur_blocks.size() || (biggest.size() == cur_blocks.size() && biggest_zero <= zeros)) {
				biggest = cur_blocks;
				biggest_pos = { i,j };
				biggest_zero = zeros;
			}
		}
	}
	if (biggest.size() < 2) return 0;

	for (auto& block : biggest) {
		A[block.first][block.second] = -2;
	}
	return biggest.size() * biggest.size();

}

vector<vector<int>> rotate(vector<vector<int>>& A) {
	int n = A.size();
	vector<vector<int>> rotated(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rotated[n-j-1][i] = A[i][j];
		}
	}
	return rotated;
}

void apply_gravity(vector<vector<int>>& A) {
	int n = A.size();
	for (int l = 0; l < n; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (A[j + 1][l] == -2 && (A[j][l] != -1))
					swap(A[j][l], A[j + 1][l]);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> A(n, vector<int>(n));
	for (auto& Ai : A) for (auto& Aij : Ai) cin >> Aij;

	int ans = 0;
	while (1) {
		int point_get = delete_biggest(A);
		if (point_get == 0) break;
		ans += point_get;

		apply_gravity(A);
		A = rotate(A);
		apply_gravity(A);
	}
	cout << ans << '\n';
}