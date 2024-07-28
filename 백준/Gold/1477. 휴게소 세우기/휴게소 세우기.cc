#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M, L;
vector<int> arr;
vector<int> diff;
bool canDivide(int x){
    int ret = 0;
    for (int i = 0; i < diff.size(); i++)
    {
        if(diff[i] < x) continue;
        if(diff[i] % x != 0){
            ret += diff[i] / x;
        }
        else{
            ret += (diff[i] / x - 1);
        }
    }
    return ret > M;
}

int main(){
    fastio;
    cin >> N >> M >> L;
    arr.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    arr.push_back(L);
    sort(arr.begin(), arr.end());
    
    for (int i = 1; i < arr.size(); i++)
    {
        diff.push_back(arr[i]-arr[i-1]);
    }
    int st = 1;
    int ed = L;
    int mid;
    while (st <= ed)
    {
        mid = (st + ed) /2;        
        if(canDivide(mid)){
            st = mid + 1;                        
        }
        else{
            ed = mid - 1 ;
        }
    }
    cout << st;

    return 0;    
}