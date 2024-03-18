#include <bits/stdc++.h>
using namespace std;

//에라토스테네스 체 구현하기
/*
2부터 시작해서 2로 나눴을 때 나머지가 0인 수들을 전부 체크해주기 + 지울 때마다 cnt++; 실행해주기
그 다음 2로 나눠지지 않은 수로 탐색 반복하기
*/
bool isprime[1005];
int ans;

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

	int n, k, cnt = 0;
	

	cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            if (isprime[j] == false) { cnt++; isprime[j] = true; }
            if (cnt == k) { ans = j; break; }
        }
        if (cnt == k)break;
    }
    cout << ans << '\n';

}