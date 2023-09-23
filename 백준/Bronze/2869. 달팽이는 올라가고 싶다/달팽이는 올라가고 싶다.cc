#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A, B, V, cur = 0, cnt=0;
	cin >> A >> B >> V;
	V -= A;
	cnt++;
	cnt += V / (A - B);
	if (V % (A - B) != 0) cnt++;
	cout << cnt;
}
