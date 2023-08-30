#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<pair<int, int>> v;
	int N;
	cin >> N;
	int n;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		int temp_1, temp_2;
		v.clear();
		for (int j = 1; j <= n; j++) {
			cin >> temp_1 >> temp_2;
			v.push_back(make_pair(temp_1, temp_2));
		}
		sort(v.begin(), v.end());
		int temp = 0;
		int result = 1;

		for (int i = 1; i < n; i++) {
			if (v[temp].second > v[i].second) {
				result++;
				temp = i;
			}
		}
		cout << result << endl;
	}
	return 0;
}