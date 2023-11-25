#include <bits/stdc++.h>
// 좌 -> 우로 내려가서 탐색하는 일반적인 방식으로는 좌->우, 상->하 방향의 원소의 대해서는 DP를 실행할 수 있으나 반대방향으로는 불가능하다.
// 따라서 좌->우, 상->하로 갈 수 있는 꼭짓점만 체크하면서 넘어가기
//idea -> d[i][j][0] : (i, j)의 꼭짓점에서 최대의 길이를 가지는 북서쪽 방향의 대각선의 길이
// d[i][j][1] (i, j)의 꼭짓점의 최대의 길이를 가지는 북동쪽 방향의 대각선의 길이
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
                // 꼭짓점의 길이가 서로 같지 않을 경우 최솟값부터 0까지를 체크한다.
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
