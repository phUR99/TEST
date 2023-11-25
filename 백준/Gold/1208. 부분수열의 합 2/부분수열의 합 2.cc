#include <bits/stdc++.h>
// 가능한 부분집합의 개수 2^40 -> 약 10^12의 연산 필요 -> 2초 안에 불가능
// 따라서 연산의 개수를 줄이기 위해서 2^20번의 연산을 2번하는 방식으로 만든다.
// 부분집합을 만들기 위해서 재귀형태의 함수 -> 선택하거나 선택하지 않거나
// s=0일 경우 공집합, 공집합의 경우를 위해서 cnt에서 하나 빼준다
// 가능 부분집합의 개수가 10^12이므로 답은 long long 으로 선언해줘야 한다.
using namespace std;
#define ll long long
map<int, long> total;
int a[50];
int n, s;
long long cnt;
void left(int st, int sum) {
    if (st == n / 2) {
        total[sum]++;
        return;
    }
    left(st + 1, sum);
    left(st + 1, sum + a[st]);
}
void right(int mid, int sum) {
    if (mid == n)
    {
        cnt += total[s-sum];
        return;
    }
    right(mid + 1, sum);
    right(mid + 1, sum + a[mid]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    left(0, 0);
    right(n / 2, 0);
    if (s == 0) cout << cnt - 1;
    else cout << cnt;
}
