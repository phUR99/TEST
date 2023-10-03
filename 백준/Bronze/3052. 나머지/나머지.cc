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

bool arr[42];



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 10; i++)
	{
		int temp; cin >> temp;
		arr[temp % 42] = true;
	}
	int ans = 0;
	for (auto i : arr)
	{
		if (i == true) ans++;
	}
	cout << ans;

}
