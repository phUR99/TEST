#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>

using namespace std;
#define ll long long



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (true)
	{
		cout << q.front() << ' ';
		q.pop();
		if (q.empty()) break;
		q.push(q.front()); q.pop();
	}

}