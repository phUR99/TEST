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
int n;
int x[100'000'5];
vector<int> uni;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		uni.push_back(x[i]);
	}
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
	}
}