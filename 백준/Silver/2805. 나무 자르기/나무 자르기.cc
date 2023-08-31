//이분탐색
//나무의 길이가 최대 20억을 넘어갈 수 있으므로 순차탐색으로는 시간초과를 절대 피할 수 없음
//whlie문의 종료 조건 체크
//answer가 바뀌는 조건 체크

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m, temp;
	cin >> n >> m;
	vector<int> h;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		h.push_back(temp);
	}
	int M = *max_element(h.begin(), h.end());
	long long f=0, med=(M+0)/2, l=M;
	long long tmp;
	long long answer = 0;
	while (f <= l)
	{	
		tmp = 0;
		for (auto i : h) {
			if(i > med) tmp += i - med;
		}
		if (tmp < m) {		
			l= med - 1;
			med = (f + l) / 2;
		}
		else 
		{
			if (med >= answer) answer = med;
			f = med + 1;
			med = (f + l) / 2;		
 		}
		
	}
	cout << answer;
}
