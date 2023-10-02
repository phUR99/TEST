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



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int len = s.length();
	int cnt[2] = { 0,0 };
	cnt[s[0] - '0']++;
	for (int i = 1; i < len; ++i) if (s[i] != s[i - 1]) cnt[s[i] - '0']++;
	cout << min(cnt[0], cnt[1]);
}