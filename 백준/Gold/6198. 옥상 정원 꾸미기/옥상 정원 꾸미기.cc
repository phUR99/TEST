#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
//1. 유의사항: 답이 매우 큰 숫자로 나올 수 있기 때문에 ans를 long long 으로 선언하는 것을 생각해볼 것
//2. 스택을 어떻게 활용할 지에 대한 생각. 
//3. while 문의 종료 조건에 대해서 엄밀하게 생각해보기
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int temp;
	int n;
	long long int ans = 0;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> temp;
		while (!s.empty() && s.top() <= temp) {
			s.pop();
		}
		ans += s.size();
		s.push(temp);

	}
	cout << ans;

}
