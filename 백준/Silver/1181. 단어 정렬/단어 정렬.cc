#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string& a, const string& b) {
	if (a.size() < b.size()) return true;
	else if (a.size() == b.size()) return a < b;
	else return false;
}


int main(void) {
	vector<string> v;
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (auto i : v)
	{
		cout << i << endl;
	}
	return 0;
}