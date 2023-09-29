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

void func(int cnt, int cur) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = cur; i < n; i++)
	{
		arr[cnt] = v[i];
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

