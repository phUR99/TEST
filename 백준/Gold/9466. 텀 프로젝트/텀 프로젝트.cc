#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
//이전에 방문했던 학생을 방문했을 때, 이 방문했던 학생이 사이클에 포함되는 것을 알 수 있다면, 이번에 방문하는 학생은 사이클에 포함되지 않음을 알 수 있다.
//방문 표시를 하나만 하는 것이 아니라 값을 분리해서 하는 것에 주안점을 주고 생각해보자.
using namespace std;
int arr[100005];
int state[100005];
const int not_visit = 0;
const int is_cycle = -1;
void chk(int x) {
	int cur = x;
	while (true)
	{
		state[cur] = x;
		cur = arr[cur];
		if (state[cur] == x) {
			while (state[cur] == x)
			{
				state[cur] = is_cycle;
				cur = arr[cur];
			}
			return;
		}
		else if (state[cur] != 0) return;
	}

}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		//not_visit으로 초기화
		fill(state+1, state + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (state[i] == not_visit) chk(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (state[i] != is_cycle) cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;	
}
