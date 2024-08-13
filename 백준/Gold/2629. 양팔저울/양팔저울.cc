#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[40];
bool cache[35][40050];
void solution(int idx, int w){
    if(idx > n) return;
    bool & ret = cache[idx][w];
    if(ret) return;
    ret = true;

    solution(idx+1, arr[idx] + w);
    solution(idx+1, w);
    solution(idx+1, abs(w-arr[idx]));
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    solution(0, 0);
    int w;
    for (int i = 0; i < m; i++)
    {
        cin >> w;
        if(w > 15000) cout << "N ";
        else if(cache[n][w]) cout << "Y ";
        else cout << "N ";

    }
    



    return 0;
}