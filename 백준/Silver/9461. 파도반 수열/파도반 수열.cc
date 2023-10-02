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
long long arr[101];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	arr[1] = 1; arr[2] = 1; arr[3] = 1;
	for (int i = 4; i <= 100; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	int n; cin >> n;
	while (n--)
	{
		int temp; cin >> temp;
		cout << arr[temp] << '\n';
	}
}