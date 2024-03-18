#include <bits/stdc++.h>
using namespace std;
/*
#QUADTREE 
1. 4개로 분할하는 함수 : stirng 반환
2. string class 사용법
2_1. str.begin() : string::iterator 타입의 반복자 반환
2_2. str.substr(n, k) : str의 n번째 idx부터 k개의 부분 문자열을 반환. 
2_3. string(n, char) : char를 n번 반복한 string을 반환

*/
string invQuadtree(string::iterator& it) {
	
	char head = *it;
	it++;
	if (head == 'w' || head == 'b') return string(1, head);

	string upLeft = invQuadtree(it);
	string upRight = invQuadtree(it);
	string downLeft = invQuadtree(it);
	string downRight = invQuadtree(it);

	return string("x") + downLeft + downRight + upLeft + upRight;
}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		string::iterator start= str.begin();
		string ans = invQuadtree(start);
		cout << ans << '\n';


	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
