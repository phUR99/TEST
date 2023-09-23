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
	int n = 5;
	int sum = 0;
	while (n--)
	{
		int temp;
		cin >> temp;
		sum += pow(temp, 2);
	}
	cout << sum % 10;
}
