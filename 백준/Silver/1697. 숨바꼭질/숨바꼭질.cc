#include <iostream>
#include <queue>
using namespace std;

bool visit[100001] = {false};
int cnt = 0;



void bfs(int N,int K) {
	visit[N] = true;
	queue<pair<int, int>> q;
	q.emplace(N, 0);
	while (!q.empty())
	{
		int loc = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (loc == K) {
			cout << cnt;
			break;
		}
		
		int plus1 = loc + 1;
		int minus1 = loc - 1;
		int product2 = loc * 2;

		if (plus1 <= K && (visit[plus1] == false))
		{
			visit[plus1] = true;
			q.emplace(plus1, cnt+1);
		}
		if (minus1 >= 0 && (visit[minus1] == false)) {
			visit[minus1] = true;
			q.emplace(minus1, cnt + 1);
		}
		if (0 < product2 && product2<= K+1 && (visit[product2] ==false)) {
			visit[product2] = true;
			q.emplace(product2, cnt+1);
		}
	}
	

}

int main() {

	int N, K;
	
	cin >> N >> K;
	bfs(N, K);

}