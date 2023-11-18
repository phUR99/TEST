#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> vec[1001];
bool visit[1001];
void reset() {
	for (int i = 0; i < 1001; i++)
	{
		visit[i] = false;
	}
}
void dfs(int X) {

	sort(vec[X].begin(), vec[X].end());
	visit[X] = true;
	for (int i = 0; i < vec[X].size(); i++)
	{
		int y = vec[X][i];
		if (!visit[y])
		{
			cout << y << " ";
			dfs(y);
			
		}
	}
}
void bfs(int X) {
	queue<int> q;
	q.push(X);
	visit[X] = true;
	cout << X << " ";
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); i++)
		{
			if (visit[vec[x][i]]==false)
			{
				q.push(vec[x][i]);
				visit[vec[x][i]] = true;
				cout << vec[x][i] << " ";
			}
			
		}
	}
}


int main() {
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	cout << V << " ";
	dfs(V);
	reset();
	cout << '\n';
	bfs(V);


}