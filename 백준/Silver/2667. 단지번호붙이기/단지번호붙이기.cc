#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int visit[26][26];
char map[26][26]; 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> vec;

int bfs(int x, int y) {
	int cnt = 1;
	visit[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if ((0 <= x2 && x2 < N) && (0 <= y2 && y2 < N)) {
				if (map[x2][y2] == '1' && visit[x2][y2] == 0)
				{

					visit[x2][y2] = 1;
					cnt++;
					q.push(make_pair(x2, y2));
				}
			}

		}
		
	}
	return cnt;

}
int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			if(visit[i][j]==0 && map[i][j] =='1') vec.push_back(bfs(i, j));

		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size()<<'\n';
	for (auto i : vec) {
		cout << i << '\n';
	}


}