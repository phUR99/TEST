#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str, boom, ans = "";
	cin >> str >> boom;
	stack<char> s;
	for (int i = (int)str.length()-1; i >= 0; i--)
	{
		string t = "";
		t += str[i];
		while (!s.empty() && str[i] == boom[0] && t.length() < boom.length()) {
			t += s.top();		
			s.pop();			
		}
		if (t == boom) continue;
		else {
			for (int i = (int)t.length()-1; i >= 0; i--)
			{
				s.push(t[i]);
			}
		}
		
	}
	if (s.empty()) cout << "FRULA";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	

}