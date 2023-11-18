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
	for (int i = 0; i < n; i++)
	{
		d[i] = arr[i];
		for (int j = 0;  j < i; j++)
		{
			if (arr[i] > arr[j]){
				d[i] = max(d[i], d[j] + arr[i]);				
			}
		}
	}
	cout << *max_element(d, d + n);
}