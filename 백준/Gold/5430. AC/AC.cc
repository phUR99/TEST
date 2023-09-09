#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
//1. 틀린 이유: 초기화를 안해줘서. 반복문을 돌릴 때마다 초기화해야할 것을 체크하고 갈 것.
//2. 문자열 파싱
//3, 덱의 장점. 리버스 함수를 계속 쓰면 시간초과 확률 있음. 이를 방지하기 위해서 덱을 뒤집는 것보다는 뒤집는지 여부만 체크해서 마지막에 
//덱을 뒤집을 지 말지를 결정하기.

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<char> D;
	deque<int> v;
	int n;
	cin >> n;
	string temp, t="", arr;
	int chk;
	int cnt;
	int cnt_D;
	while(n--) {
		chk = 0;
		cnt_D = 0;
		cin >> temp;
		for (auto i : temp)
		{
			D.push_back(i);
			if (i == 'D') cnt_D++;
		}
		cin >> cnt;
		cin >> arr;
		if (cnt == cnt_D) {
			cout << "[]" << '\n';
			D.clear();
		}
		else if (cnt < cnt_D) {
			cout << "error" << '\n';
			D.clear();
		}
		else {
			for (int i = 1; i < arr.size(); i++)
			{
				if(isdigit(arr[i])) t += arr[i];
				else {
					v.push_back(stoi(t));
					t.clear();
				}
			}
			while (!D.empty()) 
			{
				if (D.front() == 'R') {
					D.pop_front();
					chk++;
				}
				else if(D.front() == 'D'){
					if (chk % 2 == 0) v.pop_front();
					else v.pop_back();
					D.pop_front();
				}
			}
			cout << "[";
			if (chk % 2 == 1) reverse(v.begin(), v.end());
			while(!v.empty())
			{
				cout << v.front();
				v.pop_front();
				if (v.empty()) cout << "]" << '\n';
				else cout << ",";
			}
			
		}
	}
}
