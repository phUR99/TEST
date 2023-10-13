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


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	string str;
	cin >> str;
	for (auto i: str )
	{
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') ans++;
	}
	cout << ans;

}