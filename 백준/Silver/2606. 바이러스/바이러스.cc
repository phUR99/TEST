#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[101];
bool visit[101];
int cnt = 0;
void dfs(int X) {
	visit[X] = true;
	for (int i = 0; i < vec[X].size(); i++)
	{
		int y = vec[X][i];
		if (!visit[y])
		{
			dfs(y);
			cnt++;
		}
	}
}


int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1);
	cout << cnt << '\n';

}