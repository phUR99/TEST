#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
//1. 시간초과 체크,  n은 500000 까지 들어갈 수 있고, O(N^2)의 복잡도로 코드를 짜면 무조건 시간초과난다
//2. 문제해결방법 -> 거리를 받아줄 좌표와 높이를 받아줄 좌표으 정보를 쌍으로 묶어서 전달하기.
// 초기값을 int_max로 전달해서 stack이 빌 수 없게 만들어준다. 그 이후로는 stack에서 더 큰 원소를 발견할 때 까지 stack을 pop하면서 체크
// 이후 발견한다면 체크 후 거리를 증가시켜준다.(최대 N)
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> h;
	h.push(make_pair(100000001, 0));
	int n;
	cin >> n;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		while (h.top().first < temp)
		{
			h.pop();
		}
		cout << h.top().second << " ";
		h.push(make_pair(temp, i));
	}

}
