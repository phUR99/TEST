#include <bits/stdc++.h>
using namespace std;

int n, b, c;
int arr[1000005];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    long long ans = n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> b >> c;          
    for (int i = 0; i < n; i++)
    {
        if(arr[i] - b > 0) {
            ans += (arr[i] -b) / c;
            if((arr[i]-b) %c) ans++;
        }    
    }

    cout << ans;


    return 0;    
}