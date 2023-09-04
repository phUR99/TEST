#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
//list를 이용해서 해결하는 문제

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	list<char> l;
	//리스트 생성
	for (auto i : str)
	{
		l.push_back(i);
	}
	//end를 이용하면 맨 뒤의 위치의 iter.를 알아낼 수 있다.
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
			//cursor의 앞에 tmp 삽입
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
				//erase는 제거된 마지막 원소의 following을 가리키는 iter를 반환해줌.
				cursor = l.erase(cursor);
			}
		}
	}
	for (auto i : l)
	{
		cout << i;
	}
}
