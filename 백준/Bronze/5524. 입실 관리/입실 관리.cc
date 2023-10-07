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




int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		string temp = "";
		for (char i : str)
		{
			temp += tolower(i);
		}
		cout<< temp << '\n';
	}
}
