#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cost, t, sum = 0;
	cin >> cost;
	cin >> t;
	while (t--)
	{
		int n, temp;
		cin >> n >> temp;
		sum += n * temp;
	}
	if (sum == cost) cout << "Yes";
	else cout << "No";
}
