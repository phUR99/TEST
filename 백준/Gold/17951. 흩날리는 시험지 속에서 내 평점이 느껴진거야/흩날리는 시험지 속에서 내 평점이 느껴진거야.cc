#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int arr[100005];
int N, K;

bool match(int x){
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if(sum >= x){            
            cnt++;
            sum = 0;
        }
    }

    return cnt >= K;    
}

int main(){
    fastio;
    cin >> N >> K;
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        s += arr[i];

    }
    int st = 0;
    int ed = s;
    int ans = 0;
    while (st <= ed)
    {
        int mid = (st + ed) / 2;
        if(match(mid)){
            st = mid + 1;            
        }
        else ed = mid - 1;
    }
    cout << ed;

    return 0;
}