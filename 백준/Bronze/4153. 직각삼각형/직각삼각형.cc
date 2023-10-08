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
int arr[15];
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		vector<int> vec;
		vec.push_back(a); vec.push_back(b); vec.push_back(c);
		sort(vec.begin(), vec.end());
		if (vec[2] * vec[2] == vec[0] * vec[0] + vec[1] * vec[1]) cout << "right\n";
		else cout << "wrong\n";
	}
}