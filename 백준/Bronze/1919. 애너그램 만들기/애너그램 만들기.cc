#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int answer = 0;
	int arr_1[26] = {}, arr_2[26] = {};
	for (auto i : a)
	{
		arr_1[i - 'a']++;
	}
	for (auto i : b)
	{
		arr_2[i - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr_1[i] != arr_2[i])
		{
			answer += abs(arr_1[i] - arr_2[i]);
		}
	}
	cout << answer;
}