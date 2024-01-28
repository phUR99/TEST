#include <bits/stdc++.h>
using namespace std;
int arr[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	for (auto e : str)
	{
		if (e != '6' && e != '9') arr[e - '0']++;
		else {
			if (arr[6] > arr[9]) arr[9]++;
			else arr[6]++;
		}
	}
	cout << *max_element(arr, arr + 10);
}