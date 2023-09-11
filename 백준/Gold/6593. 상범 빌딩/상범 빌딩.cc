#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;

char building[31][31][31];
int t[31][31][31];

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int R, L, C;
	while (true)
	{
		bool flag = true;
		cin >> L >> R >> C;
		if (R == 0 && L == 0 && C == 0) return 0;
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++) {
				string temp;
				cin >> temp;
				for (int k = 0; k < C; k++)
				{
					building[j][k][i] = temp[k];
					t[j][k][i] = -1;
					if (temp[k] == 'S') {
						q.push({ j, k, i });
						t[j][k][i] = 0;
					}
				}
			}
		}
		while (!q.empty())
		{
			tuple<int, int, int> cur = q.front(); q.pop();
			for (int iter = 0; iter < 6; iter++)
			{
				int nx = get<0>(cur) + dx[iter];
				int ny = get<1>(cur) + dy[iter];
				int nz = get<2>(cur) + dz[iter];
				int nt = t[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
				if (t[nx][ny][nz] >= 0 || building[nx][ny][nz] == '#') continue;
				if (building[nx][ny][nz] == 'E') {
					cout << "Escaped in " << nt << " minute(s)." << '\n';
					flag = false;
				}
				t[nx][ny][nz] = nt;
				q.push({ nx, ny, nz });


			}
		}
		if(flag) cout << "Trapped!" << '\n';
	}
	

	return 0;	
}
