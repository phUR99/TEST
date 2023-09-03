#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool chk(string a, string b) {
	if (a.size() != b.size()) return false;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string temp_a, temp_b;
	for (int i = 0; i < n; i++)
	{
		cin >> temp_a >> temp_b;
		if (chk(temp_a, temp_b)) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
}