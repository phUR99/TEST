#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;


bool pushed[100001] = {false};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, temp;
	stack<int> s;
	vector<char> v;
	int sum = 0;
	bool ans = true;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		if (pushed[temp]==false){
			for (int j = 1; j <= temp; j++)
			{
				if (pushed[j] == true) continue;
				else {
					pushed[j] = true;
					s.push(j);
					
					v.push_back('+');
				}
			}
			sum++;
			s.pop();
			v.push_back('-');
		}
		else 
		{
			while (!s.empty()) {
				if (s.top() == temp) {
					sum++;
					s.pop();
					v.push_back('-');
					break;
				}
				s.pop();
				v.push_back('-');
			}
		}
		
	}
	
	if (sum != n) cout << "NO";
	else {
		for (auto i : v)
		{
			cout << i << '\n';
		}
	}
}