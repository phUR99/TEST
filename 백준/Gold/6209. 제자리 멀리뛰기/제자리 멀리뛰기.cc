#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int d, n, m;
vector<int> island;
bool determine(int x){
    int cnt = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if(island[i] - prev >= x){
            prev = island[i];
        }
        else{
            cnt++;
        }
    }
    return cnt <= m;
}


int main(){
    fastio;
    cin >> d >> n >> m;
    island.resize(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> island[i];
    }
    island[n] = d;
    sort(island.begin(), island.end());
    int left = 1;
    int right = d;
    while (left <= right)
    {
        int mid = (left + right) /2;
        if(determine(mid)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    cout << right;

    return 0;
}