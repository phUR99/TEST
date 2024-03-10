#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*
POLY: 현재의 모양을 결정하는 문제와 그 나머지를 재귀로 구현하는 문제
cache(i, j) : i개의 정사각형으로 이루어져있고, 맨 위 가로줄에 j개의 정사각형을 포함하는 폴리오미노의 수를 반환한다.


*/
int t;
int n, d, p, q;
double cache[50][101];
int adj[51][51];
int deg[51];

double search(int cur, int day) {
	if (day == 0) return (cur == p ? 1.0 : 0.0);
	double& ret = cache[cur][day];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int nxt = 0; nxt < n; nxt++)
	{
		if (adj[cur][nxt] == 0)  continue;
		ret += search(nxt, day - 1) / deg[nxt];
	}
	return ret;
}



int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> t;
	cout.precision(8);
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		memset(adj, 0, sizeof(adj));
		memset(deg, 0, sizeof(deg));
		cin >> n >> d >> p;
		for (int i = 0; i < n; i++)
		{			
			for (int j = 0; j < n; j++)
			{
				cin >> adj[i][j];
				if(adj[i][j]) deg[j]++;
			}
		}
		cin >> q;
		while (q--)
		{
			int city;
			cin >> city;
			
			cout << search(city, d) << ' ';
		}
		cout << '\n';
	}
	


	/////////////////////////////////////////////////////////////////
	return 0;
}
