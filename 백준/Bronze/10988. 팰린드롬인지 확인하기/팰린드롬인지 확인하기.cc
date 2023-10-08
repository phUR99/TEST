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
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != str[str.length() - 1 - i]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}