#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	list<char> l;
	for (auto i : str)
	{
		l.push_back(i);
	}
	auto cursor = l.end();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char temp;
		cin >> temp;
		if (temp == 'P') {
			char tmp;
			cin >> tmp;
			l.insert(cursor, tmp);
		}
		else if (temp == 'L') {
			if (cursor != l.begin()) cursor--;
		}
		else if (temp == 'D') {
			if (cursor != l.end()) cursor++;
		}
		else {
			if (cursor != l.begin()) {
				cursor--;
				cursor = l.erase(cursor);
			}
		}
	}
	for (auto i : l)
	{
		cout << i;
	}
}