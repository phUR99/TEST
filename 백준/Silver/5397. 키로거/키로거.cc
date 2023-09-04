#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
//연결 리스트를 이용하는 문제
void keyloger(string a) {
	list<char> l;
	// 비어있어도 주소는 있으니까
	auto cursor = l.begin();
	for (auto i : a) {
		if (l.empty()) {
			if (isalnum(i)) {
				//insert!!
				l.insert(cursor, i);			
			}
		}
		else {
			if (i == '<') {
				if (cursor != l.begin()) cursor--;
			}
			else if (i == '>') {
				if (cursor != l.end()) cursor++;
			}
			else if (i == '-') {
				if (cursor != l.begin()) {
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else {
				l.insert(cursor, i);		
			}
		}
	}
	for (auto i : l)
	{
		cout << i;
	}
	cout << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		keyloger(temp);
	}
}
