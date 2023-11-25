#include <bits/stdc++.h>

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