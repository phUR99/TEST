//정렬&중복 없애기
//정렬은 cmp를 만들어서 넣어주기
//중복을 없애줄 때 정렬하지 않으면 제대로 된 결과가 나오지 않을 수도 있음에 유의하기
//cmp의 return에 유의하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string& a, const string& b) {
	if (a.size() < b.size()) return true;
	else if (a.size() == b.size()) return a < b;
	else return false;
}


int main(void) {
	vector<string> v;
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (auto i : v)
	{
		cout << i << endl;
	}
	return 0;
}
