#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
vector<int> v;
int arr[10];
int n;
//// cnt는 arr에 들어갈 순서, cur는 정렬된 벡터에서 오름차순을 유지할 수 있게 제한하는 순서(v에서 더 높은 숫자가 앞으로 가는 것을 방지)
void func(int cnt, int cur) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	//i가 다음 함수에서 cur보다는 큰 값을 받음으로써 앞에 큰 값이 들어가는 것을 방지한다.
	for (int i = cur; i < n; i++)
	{
		arr[cnt] = v[i];
		//값이 정해졌으면 그 다음 값을 주어서 진행시킨다. 중복이 되도 된다면 i+1이 아니라 i를 줘서 중복시키기
		func(cnt + 1, i + 1);
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		v.clear();
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		func(0, 0);
		cout << '\n';
	}
	

}

