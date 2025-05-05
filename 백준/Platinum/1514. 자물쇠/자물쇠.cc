#include <bits/stdc++.h>
using namespace std;
int cache[105][10][10][10];
int arr[105];
int ans[105];
int n;
int solve(int idx, int s1, int s2, int s3){
    if (idx == n)
        return 0;
    int &ret = cache[idx][s1][s2][s3];
    if (ret != -1) return ret;
    ret = 987654321;

    int up = (ans[idx] - s1 + 10) % 10;
    int down = (s1 - ans[idx] + 10) % 10;
    int dx[] = {up, down};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= dx[i]; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                int second = (s2 + (!i ? j : -j)+ 10) % 10;
                int third = (s3 + (!i ? k : -k)+ 10) % 10;
                ret = min(ret, solve(idx+1, second, third, arr[idx+3]) + (dx[i] - j + 2) /3 + (j - k + 2)/ 3 + (k + 2)/ 3);
            }
        }
    }
    return ret;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char tmp;
        cin >> tmp;
        arr[i] = (tmp - '0');
    }
    for (int i = 0; i < n; i++)
    {
        char tmp;
        cin >> tmp;
        ans[i] = (tmp - '0');
    }
    int ret = solve(0, arr[0], arr[1], arr[2]);
    cout << ret;
    return 0;
}