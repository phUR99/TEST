#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	int n, k;
	cin >> n >> k;
	cout << "<";
	for (int i = 1; i <=n ; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		//큐를 이용해서 k번 만큼 회전시킨다고 생각하기
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		//이후 반드시 사용된 값을 제거시킨다
		cout << q.front();
		q.pop();
		if (!q.empty()) cout << ", ";
	}
	cout << ">";
}
