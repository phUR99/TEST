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
int arr[30];
int n, s;
int cnt = 0;


void func(int cur, int sum) {
	//base condition
	if (cur == n) {
		if (sum == s) cnt++;
		return;
	}
	//현재 값을 더하지 않고 넘어갈 경우에
	func(cur + 1, sum);
	//현재 값을 더하고 넘어갈 경우에
	func(cur + 1, sum + arr[cur]);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	func(0, 0);
	//sum=0이면 공집합을 제외하기
	if (s == 0) cnt--;
	cout << cnt;
}
