#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T, N;
map<int, int> nerd;                

bool canInsert(int p, int q){
    map<int, int>::iterator iter = nerd.lower_bound(p);                        
    if(iter == nerd.end()) return true;

    return q > iter->second;
}
void del(int p, int q){
    map<int, int>::iterator iter = nerd.lower_bound(p);
    if(iter == nerd.begin()) return;
    iter--;
    while (true)
    {

        if(iter->second > q) break;
        if(iter == nerd.begin()) {
            nerd.erase(iter);
            break;
        }   
        else{
            map<int, int>::iterator jter = iter;
            jter--;
            nerd.erase(iter);
            iter = jter;
        }              
    }    
}

int main(){
    fastio;
    cin >> T;
    int p, q;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        nerd.clear();
        long long ans = 0;        
        for (int i = 0; i < N; i++)
        {
            cin >> p >> q;            
               
            if(canInsert(p, q)){
                nerd[p] = q;
                del(p, q);
            }
            long long size = nerd.size();            
            ans += size;
        }
        cout << ans << '\n';        
    }    
    return 0;
}