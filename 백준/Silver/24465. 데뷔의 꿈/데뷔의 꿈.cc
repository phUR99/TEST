#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

bool chk[12];

bool func(int m, int d) {
	int tmp = 100 * m + d;

	if (tmp >= 120 && tmp < 219)		return chk[0];
	else if (tmp >= 219 && tmp < 321)	return chk[1];
	else if (tmp >= 321 && tmp < 420)	return chk[2];
	else if (tmp >= 420 && tmp < 521)	return chk[3];
	else if (tmp >= 521 && tmp < 622)	return chk[4];
	else if (tmp >= 622 && tmp < 723)	return chk[5];
	else if (tmp >= 723 && tmp < 823)	return chk[6];
	else if (tmp >= 823 && tmp < 923)	return chk[7];
	else if (tmp >= 923 && tmp < 1023)	return chk[8];
	else if (tmp >= 1023 && tmp < 1123)	return chk[9];
	else if (tmp >= 1123 && tmp < 1222)	return chk[10];
	else return chk[11];

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 7; i++)
	{
		int m, d;
		cin >> m >> d;
		int tmp = 100 * m + d;
		if (tmp >= 120 && tmp < 219)		chk[0] = true;
		else if (tmp >= 219 && tmp < 321)	chk[1] = true;
		else if (tmp >= 321 && tmp < 420)	chk[2] = true;
		else if (tmp >= 420 && tmp < 521)	chk[3] = true;
		else if (tmp >= 521 && tmp < 622)	chk[4] = true;
		else if (tmp >= 622 && tmp < 723)	chk[5] = true;
		else if (tmp >= 723 && tmp < 823)	chk[6] = true;
		else if (tmp >= 823 && tmp < 923)	chk[7] = true;
		else if (tmp >= 923 && tmp < 1023)	chk[8] = true;
		else if (tmp >= 1023 && tmp < 1123)	chk[9] = true;
		else if (tmp >= 1123 && tmp < 1222)	chk[10] = true;
		else chk[11] = true;
	}
	vector<pair<int, int>> ans;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		
		if (!func(a, b)) ans.push_back({ a, b });
	}
	if (ans.empty()) { cout << "ALL FAILED";  return 0; }
	sort(ans.begin(), ans.end());
	for (auto e : ans)
	{
		cout << e.first << ' ' << e.second << '\n';
	}
}