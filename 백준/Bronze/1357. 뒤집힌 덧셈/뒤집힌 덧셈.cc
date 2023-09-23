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
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
	int temp = stoi(a) + stoi(b);
	string ans = to_string(temp);
	reverse(ans.begin(), ans.end());
	cout << stoi(ans);


}
