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
int arr[100'050][3];
int d_M[2][3];
int d_m[2][3];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	d_M[1][0] = arr[1][0]; d_M[1][1] = arr[1][1]; d_M[1][2] = arr[1][2];
	d_m[1][0] = arr[1][0]; d_m[1][1] = arr[1][1]; d_m[1][2] = arr[1][2];
	for (int i = 2; i <= n; i++)
	{
		d_M[i%2][0] = max(d_M[(i - 1)%2][0], d_M[(i - 1)%2][1]) + arr[i][0];
		d_M[i%2][1] = max({ d_M[(i - 1)%2][0], d_M[(i - 1)%2][1], d_M[(i - 1)%2][2] }) + arr[i][1];
		d_M[i%2][2] = max(d_M[(i - 1)%2][1], d_M[(i - 1)%2][2]) + arr[i][2];

		d_m[i%2][0] = min(d_m[(i - 1)%2][0], d_m[(i - 1)%2][1]) + arr[i][0];
		d_m[i%2][1] = min({ d_m[(i - 1)%2][0], d_m[(i - 1)%2][1], d_m[(i - 1)%2][2] }) + arr[i][1];
		d_m[i%2][2] = min(d_m[(i - 1)%2][1], d_m[(i - 1)%2][2]) + arr[i][2];
	}
	int M = max({ d_M[(n)%2][0], d_M[(n)%2][1], d_M[(n)%2][2] });
	int m = min({ d_m[(n)%2][0], d_m[(n)%2][1], d_m[(n)%2][2] });
	cout << M << ' ' << m;
}