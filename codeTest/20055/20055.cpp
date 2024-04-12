#include <bits/stdc++.h>
using namespace std;
int N, K; 
int A[200];

int solve(){
int ret = 0;
	int zero_count = 0;
	int robot[200 * 1000];
	int front = 0, back = 0;

	while (zero_count < K) {
		++ret;

		int temp = A[2 * N - 1];
		for (int i = 2 * N - 1; i >= 1; --i) {
			A[i] = A[i - 1];
		}
		A[0] = temp;
        //로봇의 움직임 구현
        //큐를 배열로 구현하는 방법..
		for (int i = front; i < back; ++i) {
			++robot[i];
			if (robot[i] == N - 1) {
				++front;
			}
		}

		for (int i = front; i < back; ++i) {
			int next = robot[i] + 1;
			if (A[next] == 0 || (i != front && robot[i - 1] == next)) {
				continue;
			}
			robot[i] = next;
			if (robot[i] == N - 1) {
				++front;
			}
			--A[next];
			if (A[next] == 0) {
				++zero_count;
			}
		}

		if (A[0] > 0 && (back == 0 || robot[back - 1] != 0)) {
			robot[back++] = 0;
			--A[0];
			if (A[0] == 0) {
				++zero_count;
			}
		}
	}

	return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i *2] >> A[i *2 +1];
    }
    int ret = solve();
    cout << ret;
    return 0;
}