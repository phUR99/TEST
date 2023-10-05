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

bool d[1001];
int cand[] = { 1, 3, 4 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	d[1] = 1; d[3] = 1; d[4] = 1;
	for (int i = 5; i <= n; i++)
	{
		for (int j : cand) {
			if (d[i - j] == 0) {
				d[i] = 1; break;
			}
			else d[i] = 0;
		}
	}

	string ans = (d[n]) ? "SK" : "CY";
	cout << ans;



	
	
}
