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
bool cmp(tuple<int, int, int, string>& a, tuple<int, int, int, string>& b) {
	int a1 = get<0>(a); int a2 = get<1>(a); int a3 = get<2>(a); string a4 = get<3>(a);
	int b1 = get<0>(b); int b2 = get<1>(b); int b3 = get<2>(b); string b4 = get<3>(b);
	if (a1 == b1)
	{
		if (a2 == b2){
			if (a3 == b3) {
				return a4 < b4;
			}
			return a3 > b3;
		}
		return a2 < b2;
	}
	return a1 > b1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string name;
	int kor, eng, maths;
	int n; cin >> n;
	vector<tuple<int, int, int, string>> arr;
	while (n--)
	{
		cin >> name >> kor >> eng >> maths;
		arr.push_back({ kor, eng, maths, name });
	}
	sort(arr.begin(), arr.end(), cmp);
	for (auto i : arr) {
		cout << get<3>(i) << '\n';
	}
}
