#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*
#NUMB3RS: 앞으로 세는 것보다 뒤로 세는 것이 더 유리하다
-> 현재 마을에서 D일 후의 마을 P로 가는 것보다는 현재 마을 P에서 시작해서 D일 후에 CUR 마을로 가는 것이 훨씬 직관적이다.
확률이 indegree에 비례하므로 indegree에 담아줄 정보 배열이 필요하다.
-> 다음에 가능한 마을을 선택하는 것은 현재 마을의 상황에 의해서만 결정하는 것도 유의깊게 생각해보기 ->MDP
cout.precision(n) 을 이용해서 n자리 이하 소수까지 출력이 가능하게 할 수 있다.

*/
int t;
int n, d, p, q;
double cache[50][101];
int adj[51][51];
int deg[51];

double search(int cur, int day) {
	//기저조건 1 : day가 지났을 때 p 마을에 있다면 1을 반환한다.
	if (day == 0) return (cur == p ? 1.0 : 0.0);
	double& ret = cache[cur][day];
	//메모이제이션 활용
	if (ret > -0.5) return ret;
	ret = 0.0;
	//순회 가능한 마을들을 순회하면서 deg로 나눠준다.
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
