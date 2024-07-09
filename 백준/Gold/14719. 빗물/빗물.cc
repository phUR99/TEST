#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int arr[505];

int main(){
    fastio;
    int h, w;
    cin >> h >> w;    
    for (int i = 0; i < w; i++) cin >> arr[i];
    int answer = 0;

    for (int i = 1; i < w-1; i++)
    {
        int left =0, right = 0;
        for(int j = 0; j < i; j++) left = max(left, arr[j]);
        for(int j = w-1; j > i; j--) right = max(right, arr[j]);
        answer += max(0, min(left, right) - arr[i]);
    }
    cout << answer;
    return 0;
}