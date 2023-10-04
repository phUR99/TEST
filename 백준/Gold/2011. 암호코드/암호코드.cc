#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>
using namespace std;
#define ll long long
int arr[5001];
int d[5001];
int mod = 1000000;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 1; i <= n; i++)
	{
		arr[i] = str[i - 1]-'0';
	}
	//i번째 일 때 i-1을 선택하거나 선택하지 않는 경우의 합이므로 피보나치 수열의 합을 따른다.
	//다만 범위가 벗어난 값일 때의 처리를 어떻게 할지 생각해보기. i번 째일때 0이면 경우가 고정되버린다.
	d[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (arr[i] > 0) d[i] = (d[i] + d[i - 1]) % mod;
		int x = arr[i - 1] * 10 + arr[i];
		if (x >= 10 && x <= 26) d[i] = (d[i] + d[i - 2]) % mod;
	}
	cout << d[n];
	
	
}
