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
vector<string> arr;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		string temp = str.substr(i);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (auto i : arr)
	{
		cout << i << '\n';
	}
}
