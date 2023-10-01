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

int arr[1'000'001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	arr[1] = 0;
	for (int i = 2; i <=n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 ==0) arr[i] = min(arr[i], arr[i / 2]+1);
		if (i % 3 ==0) arr[i] = min(arr[i], arr[i / 3]+1);
	}
	cout << arr[n];
	
}
