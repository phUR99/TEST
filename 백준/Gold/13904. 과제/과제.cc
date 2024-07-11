#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define prize first
#define deadline second
int arr[1005];

int N;

int main(){
    fastio;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].deadline >> v[i].prize;        
    }
    sort(v.begin(), v.end(), greater<>());
    int ans = 0;
    for (int i = 0; i < N; i++)
    {        
        for (int j = v[i].deadline; j > 0; j--)
        {
            if(!arr[j]){
                arr[j] = v[i].prize;
                ans += arr[j];
                break;
            }
        }        
    }
    cout << ans;
    

    return 0;
}