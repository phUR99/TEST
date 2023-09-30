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
int arr[8];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	do
	{
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(arr, arr+n));
}
