#include <bits/stdc++.h>
using namespace std;
/*
#11066 : 사선 DP
d[i][j] = i ~ j 번째까지의 최소 합
d[i][j] = (d[i][k] + d[k+1][j] + i ~ j까지의 누적합) 중의 최솟값 (k는 i~j 사이)
*/

int arr[505], sum[505];
int d[505][505];

int n, t;


int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; i + j <= n; j++) {
				d[j][j + i] = 999999999;
				for (int k = j; k < i + j; k++)
				{
					d[j][j + i] = min(d[j][j + i], d[j][k] + d[k + 1][j + i] + sum[j + i] - sum[j - 1]);
				}
			}
		}
		cout << d[1][n] << '\n';
	}


	return 0;
}