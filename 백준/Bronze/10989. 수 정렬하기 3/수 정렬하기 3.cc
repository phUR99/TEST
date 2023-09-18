#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int arr[10001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<int> vec;
	cin >> n;
	while (n--)
	{
		int temp;
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 0; i < 10001; i++)
	{
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++)
			{
				cout << i << '\n';
			}
		}
	}


}
