#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[10050];
int n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret =0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i+1] > arr[i+2])
        {
            if(arr[i] && arr[i+1]){
                int m = min({arr[i], arr[i+1], arr[i+1] - arr[i+2]});
                arr[i] -= m;
                arr[i+1] -= m;
                ret += 5 * m;
            }
        }
        
        if(arr[i] && arr[i+1] && arr[i+2]){
            int m = min({arr[i], arr[i+1], arr[i+2]});
            arr[i] -= m;
            arr[i+1] -= m;
            arr[i+2] -= m;
            ret += 7 *m;
        }
        if(arr[i] && arr[i+1]){
            int m = min(arr[i], arr[i+1]);
            arr[i] -= m;
            arr[i+1] -= m;
            ret += 5 * m;
        }
        if(arr[i]){
            ret += 3 * arr[i];
            arr[i] -= arr[i];
        }
    }
    cout << ret;
    return 0;
}