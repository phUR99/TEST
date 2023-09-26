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

int arr[10];
int num[10];
int isused[10];
int n, m;

void func(int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}


	int tmp = 0;
	for (int i = st; i < n; i++) {
		if(tmp != num[i])
		{
			arr[k] = num[i];
			tmp = arr[k];
			func(k + 1, i);
		}
	}
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num+n);
	func(0, 0);

}

