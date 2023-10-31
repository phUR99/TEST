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
vector<int> M, P;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		int temp;
		cin >> temp;
		if (temp > 0) P.push_back(temp);
		else M.push_back(temp);
	}
	sort(M.begin(), M.end());
	sort(P.begin(), P.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < M.size(); i = i+m)
	{
		ans -= 2*M[i];
	}for (int i = 0; i < P.size(); i = i + m)
	{
		ans += 2*P[i];
	}
	if (M.empty())
	{
		ans -= P[0];
	}
	else if (P.empty()) {
		ans += M[0];
	}
	else
	{
		if (abs(M[0]) > P[0]) ans += M[0];
		else ans -= P[0];
	}
	cout << ans;
}