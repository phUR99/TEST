#include <bits/stdc++.h>
using namespace std;
/*
#13023 : dfs 구현




*/
int n, m;
vector<int> adj[2005];
bool isUsed[2005];
bool ans = false;

void func(int cur, int cnt) {
	isUsed[cur] = true;	
	if (cnt == 5) {
		ans = true;
		return;
	}
	else
	{
		for (auto nxt : adj[cur])
		{
			if (isUsed[nxt] == true) continue;
			func(nxt, cnt + 1);
		}
	}
	isUsed[cur] = false;
}



int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	while (m--)
	{
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	for (int i = 0; i < n; i++)
	{
		func(i, 1);
		if (ans == true) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}