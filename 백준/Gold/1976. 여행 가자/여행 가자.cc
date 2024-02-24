#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
#1976: union-find 설계하기

*/

int node[205];
int n, m;

int find(int a) {
	//node의 부모가 자신을 가리킨다면 자신을 반환해준다.
	if (node[a] == a) return a;
	//node의 부모가 자신을 가리키지 않는다면 자신을 가리킬 때까지 탐색하고 그 값을 부모로 전달해준다. + 좌표 압축
	else return node[a] = find(node[a]);
}
void uni(int a, int b) {
	//a의 부모, b의 부모
	int aRoot = find(a);
	int bRoot = find(b);
	//a의 부모를 b로 변경해준다
	if (aRoot < bRoot) node[bRoot] = aRoot;
	else node[aRoot] = bRoot;
}


int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		node[i] = i;
	}
	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int cmd;
			cin >> cmd;
			if (cmd == 1) uni(i, j);
		}
	}
	int parent;
	
	for (int i = 0; i < m; i++)
	{
		int city;
		cin >> city;
		if(i==0) parent = find(city);
		else
		{
			if (find(parent) != find(city)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";

	return 0;
}