#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
// 1. 사용한 값을 추가하지 않을 방법 -> pushed arr를 선언하여 chk된 element는 stk에 push하지 않게 함.
// 2. 전부 다 사용했는 지 확인할 방법 -> cnt 역할의 sum을 이용하여 sum이 n과 같은지를 체크. 같지 않다면 전부 사용된 것이 아니므로 NO를 출력하게 한다.
// 3. 그 외는 stk의 성질을 이용해서 구현하기
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
