#include <bits/stdc++.h>
using namespace std;
list<char> L;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int n;
	cin >> n;
	for (auto e : str)
	{
		L.push_back(e);
	}
	auto t = L.end();
	while (n--)
	{
		char  c;
		cin >> c;
		if (c == 'L') if (t != L.begin()) t--;
		if (c == 'D') if (t != L.end()) t++;
		if (c == 'B') if (t != L.begin()) {
			//커서를 앞으로 땡기고 그 위치에 있는 원소를 삭제한 뒤에 가리키는 값까지 반환이 필요
			t--;
			t = L.erase(t);
		}
		if (c == 'P') {
			char tmp;
			cin >> tmp;
			L.insert(t, tmp);

		}

	}
	for (auto e : L)
	{
		cout << e;
	}
}
