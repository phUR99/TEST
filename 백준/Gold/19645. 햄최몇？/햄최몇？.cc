#include <bits/stdc++.h>
using namespace std;
int n;
int arr[55];
int cache[2505][2505];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = accumulate(arr, arr+ n, 0);
    cache[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            for (int k = sum; k >= 0; k--)
            {
                if (j - arr[i] >= 0)
                    cache[j][k] |= cache[j - arr[i]][k];
                if (k - arr[i] >= 0)
                    cache[j][k] |= cache[j][k - arr[i]];
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= sum; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(cache[i][j] && j >= sum - i - j)
                ret = max(ret, sum - i - j);
        }
        
    }
    cout << ret;

    return 0;
}