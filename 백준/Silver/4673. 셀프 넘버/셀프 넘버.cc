#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
bool check[10001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 10001; i++)
	{
		int n = i;
		string temp = to_string(i);
		for (int j = 0; j < temp.size(); j++)
		{
			n += temp[j] - '0';
		}
		if (n < 10001) check[n] = true;
	}
	for (int i = 1; i < 10001; i++)
	{
		if (!check[i]) cout << i << '\n';
	}


}