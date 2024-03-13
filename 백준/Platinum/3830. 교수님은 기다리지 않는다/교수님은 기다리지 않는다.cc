#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

//n은 1e6 이내므로 배열로 충분히 만들 수 있다.
int graph[1000005], weight[1000005];
int n, m;

int find(int x) {


	if (graph[x] == x) return x;
	// return find[graph] chaining의 문제가 발생할 수 있음
	// 좌표 압축
	int parent = find(graph[x]);
	weight[x] += weight[graph[x]];
	return graph[x] = parent;
	
};

void uni(int a, int b, int w) {
	int aRoot = find(a);
	int bRoot = find(b);
	//a의 부모를 확인해서 b의 부모로 바꿔줌(거리 압축)
	if (aRoot > bRoot) {
		int temp = weight[b] - w;
		weight[aRoot] = temp - weight[a];
		graph[aRoot] = bRoot;
	}
	else
	{
		int temp = weight[a] + w;
		weight[bRoot] = temp - weight[b];
		graph[bRoot] = aRoot;
	}

	

};

int main() {
	//빠른 입출력을 위해서 사용하기
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

	//init
	while (true)
	{
		int n, t;
		cin >> n >> t;
		if (n == 0 && t == 0) break;

		for (int i = 1; i <= n; i++)
		{
			graph[i] = i;
		}

		fill(weight + 1, weight+n+1, 0);

		while (t--)
		{
			char c;
			cin >> c;
			if(c == '!')
			{

				int a, b, w;
				cin >> a >> b >> w;
				uni(a, b, w);
			}
			else
			{
				int a, b;
				cin >> a >> b;
				if (find(a) != find(b))
				{
					cout << "UNKNOWN\n";
				}
				else
				{
					cout << weight[b] - weight[a] << '\n';
				}

			}
		}
	}


	return 0;
}