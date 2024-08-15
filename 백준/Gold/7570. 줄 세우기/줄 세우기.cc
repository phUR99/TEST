#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int arr[1000005];
int n;
int LIS;

int main(){
    fastio;
    cin >> n;
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp] = arr[tmp-1] + 1;
        LIS = max(LIS, arr[tmp]);
    }
    cout << n - LIS;
    return 0;
}