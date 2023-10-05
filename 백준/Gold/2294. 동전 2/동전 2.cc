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

int d[10005];
int arr[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	fill(d, d + 10005, 100005);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		
	}
	d[0] = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++)
			d[j] = min(d[j], d[j - arr[i]] + 1);
	}
	cout << (d[k] == 100005 ? -1 : d[k]) << '\n';



	
	
}
