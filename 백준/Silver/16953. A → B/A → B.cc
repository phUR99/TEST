#include <iostream>
#include <queue>


using namespace std;
long long A, B;

void bfs(long long a, long long b) {
	queue<pair<long long, int>> q;
	q.emplace(a, 1);

	while (!q.empty())
	{
		long long pos = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (pos == b)
		{
			cout << cnt;
			return;
		}
		if (pos*2 <=b)
		{

			q.emplace(pos * 2, cnt + 1);
		}
		if (pos*10+1<=b){

			q.emplace(pos * 10 + 1, cnt + 1);
		}

	}
	cout << -1;
	return;
}


int main() {
	cin >> A >> B;
	bfs(A, B);



}