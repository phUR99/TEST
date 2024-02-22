#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
1516: indegree를 이요애서 푸는 위상 정렬 문제
indegree를 확인하고 indegree를 연결되어 있는 번호 중에서 최댓값 + 자신의 건설 시간으로 자신의 시간 번호를 업데이트 해줘야한다.

*/
int indegree[505];
int dist[505];
int cost[505];
int n;
vector<int> adj[505];

int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int from;
		cin >> cost[i];
		dist[i] = cost[i];

		while (true)
		{
			cin >> from;
			if (from == -1) break;
			adj[from].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		
		for (auto nxt : adj[cur])
		{
			dist[nxt] = max(dist[nxt], dist[cur] + cost[nxt]);
			indegree[nxt]--;
			if (indegree[nxt] == 0) q.push(nxt);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << '\n';
	}
	 
	return 0;
}