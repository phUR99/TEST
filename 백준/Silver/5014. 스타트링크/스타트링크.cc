#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;

bool visit[1000001] = { false };

void bfs() {
	queue<pair<int, int>> q;
	q.emplace(S, 0);
	visit[S] = true;
	while (!q.empty())
	{
		
		int current = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (current==G) {

			cout << cnt;
			return;
		}
		if (0 < current+U && current+U <= F && !visit[current+U]){
			visit[current+U] = true;
			q.emplace(current + U, cnt+1);
		}
		if (0 < current - D && current -D <= F && !visit[current-D])  {
			visit[current -D] = true;
			q.emplace(current -D, cnt+1);
		}
	}
	cout << "use the stairs";
	return;
}

int main() {
	cin >> F >> S >> G >> U >> D;
	bfs();
}