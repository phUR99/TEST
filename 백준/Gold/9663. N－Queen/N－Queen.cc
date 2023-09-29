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
int cnt = 0, n;
bool isused1[40], isused2[40], isused3[40];



void func(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) continue;
		isused1[i] = true;
		isused2[i + cur] = true;
		isused3[cur - i + n - 1] = true;

		func(cur + 1);

		isused1[i] = false;
		isused2[i + cur] = false;
		isused3[cur - i + n - 1] = false;
	}
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
	func(0);
	cout << cnt;


}

