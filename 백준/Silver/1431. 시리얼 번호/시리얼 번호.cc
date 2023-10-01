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

string arr[100];

bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) {
		int len = a.size();
		int sum_a = 0, sum_b = 0;
		for (size_t i = 0; i < len; i++)
		{
			if (isdigit(a[i])) sum_a += a[i]-'0';
			if (isdigit(b[i])) sum_b += b[i]-'0';
		}
		if (sum_a == sum_b) {
			for (size_t i = 0; i < len; i++)
			{
				if (a[i]==b[i]) continue;
				else return a[i] < b[i];
			}
		}
		else {
			return sum_a < sum_b;
		}
	}
	else return a.size() < b.size();
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}
}
