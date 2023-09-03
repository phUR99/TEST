#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[2000001] = {};
//중복되는 i를 생각을 안해서 틀린 문제
//i = x-i 일 경우 생기는 예외를 제거합시다
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int tmp;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a[tmp] = 1;
	}
	int x;
	cin >> x;
	for (int i = 1; i < x; i++)
	{
		if (a[i] == 1) 
			if (a[x - i] == 1 && i != x-i) 
			{
				a[i] = 0;
				a[x - i] = 0;
				cnt++;
			}
	}
	cout << cnt;
}
