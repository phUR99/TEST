#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string temp;
	getline(cin, temp);
	
	if (temp.empty()) cout << 0;
	int ans = 1;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == ' ') ans++;
	}
	if (temp[0] == ' ' ) ans--;
	if (temp[temp.size() - 1] == ' ') ans--;
	cout << ans;

}
