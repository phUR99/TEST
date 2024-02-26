#include <bits/stdc++.h>
using namespace std;
/*
#1327 : bfs를 실행하면서 가지치기를 셋을 이용해서 한다.
*/
int n, k;

int func(string str) {
	queue<pair<string, long long>> q;
	map<string, bool> visited;
	string target = str;
	sort(target.begin(), target.end());
	q.push({ str, 0 });

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		if  (cur.first == target) {
			return cur.second;
		}
		if (visited.count(cur.first)==true)  continue;
		visited[cur.first] = true;
		for (int i = 0; i <= target.size() - k; i++)
		{
			string tmp = cur.first.substr(i, k);
			reverse(tmp.begin(), tmp.end());
			q.push({ cur.first.substr(0, i) + tmp + cur.first.substr(i + k, cur.first.size()), cur.second + 1 });
		}

	}
	return -1;




	
}


int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	string str = "";
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		str += c;
	}
	cout << func(str) << '\n';
	return 0;
}