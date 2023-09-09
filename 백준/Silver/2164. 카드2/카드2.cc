#include <iostream>
#include <queue>
using namespace std;
int main() {
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		q.push(i);
	}
	while (true) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		q.pop();
		q.push(q.front());
		q.pop();
	}


}