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
int arr[1'000'001];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n; cin >> n; 
		int max_cost = 0;
		int max_cnt;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			if (max_cost <= arr[i]) {
				max_cost = arr[i];
				max_cnt = i;
			}
		}
		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i <= max_cnt) {
				sum += max_cost - arr[i];
			}
			else {
				max_cost = 0;
				for (int j = i; j <= n; j++)
				{
					if (max_cost <= arr[j]) {
						max_cost = arr[j];
						max_cnt = j;
					}
				}
				sum += max_cost - arr[i];;
			}
		}
		cout << sum << '\n';
	}


}