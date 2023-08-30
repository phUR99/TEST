#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//가장 낮은 사람으로 갈까 높은 방식으로 할까 하다 시간을 많이 잡아먹은 것 같다
//서류 심사대로 순위를 정렬한 후, 면접 점수를 비교하면서 temp를 바꿔주는 방식으로 체크해야 답이 나온다.
//정렬을 어떻게 해야할 지에 대한 고민
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
