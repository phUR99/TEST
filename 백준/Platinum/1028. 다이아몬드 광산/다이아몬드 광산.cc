#include <bits/stdc++.h>

using namespace std;
#define ll long long

string arr[756];
int a[756][756];
int d[756][756][2];
int r, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        cin >> arr[i];
        for (int j = 1; j <= c; j++) 
        {
            a[i][j] = arr[i][j - 1] - '0';
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++) {
            if (a[i][j])
            {
                d[i][j][0] = d[i - 1][j - 1][0] + 1;
                d[i][j][1] = d[i - 1][j + 1][1] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++) {
            if (a[i][j])
            {
                int dist = min(d[i][j][0], d[i][j][1]);
                for (int k = dist; k > 0; k--)
                {
                    if (d[i - k + 1][j - k + 1][1] >= k && d[i - k + 1][j + k - 1][0] >= k) ans = max(ans, k);
                }
                
            }
        }
    }
    cout << ans;
}