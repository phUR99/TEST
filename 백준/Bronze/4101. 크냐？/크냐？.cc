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
int arr[1050];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		string ans = (a > b) ? "Yes" : "No";
		cout << ans << '\n';
	}
}