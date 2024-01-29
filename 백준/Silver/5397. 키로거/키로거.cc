#include <bits/stdc++.h>
using namespace std;

list<char> L;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str;
		auto t = L.begin();
		for (auto e : str)
		{
			if (e =='<')
			{
				if (t != L.begin()) t--;
			}
			else if (e == '>') {
				if (t != L.end()) t++;
			}
			else if (e == '-') {
				if (t != L.begin() && !L.empty()) {
					t--;
					t = L.erase(t);
				}
			}
			else
			{
				L.insert(t, e);
			}
		}
		for (auto e : L)
		{
			cout << e;
		}
		cout << '\n';
		L.clear();
	}

}