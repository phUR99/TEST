#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[1005];
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ans = 0;
	//d[i] : i번째의 증가하는 부분수열의 최댓값
	for (int i = 0; i < n; i++)
	{
		d[i] = arr[i];
		for (int j = 0;  j < i; j++)
		{
			//arr[i] >arr[j] 라면 i보다 작은 j를 순회하면서 최댓값을 d[i]에 저장한다.
			if (arr[i] > arr[j]){
				d[i] = max(d[i], d[j] + arr[i]);				
			}
		}
	}
	cout << *max_element(d, d + n);
}
