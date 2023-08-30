#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main(void) {
	string str;
	cin >> str;
	sort(str.begin(), str.end(), greater<>());
	cout << stoi(str);

	return 0;
}