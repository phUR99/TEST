#include <iostream>
#include <string.h>

using namespace std;
int arr[10005][2];
int cache[10050][2][2][2][2];
int n, w;
int caching(int idx, int upper, int lower, int first_upper, int first_lower){
    if (idx == n)
        return 0;
    int &ret = cache[idx][upper][lower][first_upper][first_lower];
    if (ret != -1) return ret;
    ret = 987654321;
    if (idx == n-2)
    {
        if (!upper && !lower){
            ret = min(ret, 2 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][0] + arr[idx][1] <= w)
                ret = min(ret, 1 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][0] + arr[idx+1][0] <= w && !first_upper)
                ret = min(ret, 2 + caching(idx+1, 1, 0, first_upper, first_lower));
            if (arr[idx][1] + arr[idx+1][1] <= w && !first_lower)
                ret = min(ret, 2 + caching(idx+1, 0, 1, first_upper, first_lower));
            if (arr[idx][0] + arr[idx+1][0] <= w && arr[idx][1] + arr[idx+1][1] <= w &&!first_lower && !first_upper) 
                ret = min(ret, 2 + caching(idx+1, 1, 1, first_upper, first_lower));
        }
        else if(upper && !lower){
            ret = min(ret, 1 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][1]+ arr[idx+1][1] <=w && !first_lower)
                ret = min(ret, 1 + caching(idx+1, 0, 1, first_upper, first_lower));
            
        }
        else if(!upper && lower){
            ret = min(ret, 1 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][0]+arr[idx+1][0] <= w && !first_upper)
                ret = min(ret, 1 + caching(idx+1, 1, 0, first_upper, first_lower));
            
        }
        else
            ret = min(ret, caching(idx+1, 0, 0, first_upper, first_lower));
        
    }
    else
    {
        if (idx == n-1)
        {
            upper |= first_upper;
            lower |= first_lower;
        }
        
        if (!upper && !lower){
            ret = min(ret, 2 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][0] + arr[idx][1] <= w)
                ret = min(ret, 1 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][0] + arr[idx+1][0] <= w)
                ret = min(ret, 2 + caching(idx+1, 1, 0, first_upper, first_lower));
            if (arr[idx][1] + arr[idx+1][1] <= w)
                ret = min(ret, 2 + caching(idx+1, 0, 1, first_upper, first_lower));
            if (arr[idx][0] + arr[idx+1][0] <= w && arr[idx][1] + arr[idx+1][1] <= w)
                ret = min(ret, 2 + caching(idx+1, 1, 1, first_upper, first_lower));
        }
        else if(upper && !lower){
            ret = min(ret, 1 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][1]+ arr[idx+1][1] <=w)
                ret = min(ret, 1 + caching(idx+1, 0, 1, first_upper, first_lower));
            
        }
        else if(!upper && lower){
            ret = min(ret, 1 + caching(idx+1, 0, 0, first_upper, first_lower));
            if (arr[idx][0]+arr[idx+1][0] <= w)
                ret = min(ret, 1 + caching(idx+1, 1, 0, first_upper, first_lower));
            
        }
        else
            ret = min(ret, caching(idx+1, 0, 0, first_upper, first_lower));
        
        
    }

    return ret;
}

void solve(){
    
    cin >> n >> w;
    memset(cache, -1, sizeof(cache));
    memset(arr, 0x3f, sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1];
    }
    int ret = 987654321;
    ret = min(caching(0, 0, 0, 0, 0), ret);
    if (arr[0][0] + arr[n-1][0] <=w)
        ret = min(ret, caching(0, 1, 0, 1, 0) +1);
    if (arr[0][1] + arr[n-1][1] <=w)
        ret = min(ret, caching(0, 0, 1, 0, 1) +1);
    if (arr[0][0] + arr[n-1][0] <=w && arr[0][1] + arr[n-1][1] <=w)
        ret = min(ret, caching(0, 1, 1, 1, 1) +2);
    cout << ret << '\n';
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    


    return 0;
}