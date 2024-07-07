#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
set<int> pRand;
int N, M;

int main(){
    fastio;

    cin >> N >> M;
    int curPos = 1;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        if(!tmp) continue;
        pRand.insert(i);        
    }
    for (int i = 0; i < M; i++)
    {
        int c, n;
        cin >> c;
        if(c == 1){
            cin >> n;
            if(pRand.find(n) == pRand.end()) {
                pRand.insert(n);                
            }
            else{
                pRand.erase(pRand.find(n));                
            }
        }
        else if(c== 2){
            cin >> n;
            n %= N;
            curPos = curPos + n;
            if(curPos > N) curPos -= N;
        }
        else{                
            if(pRand.empty()) cout << -1 << '\n';
            else{
                auto iter = pRand.lower_bound(curPos);
                if(iter != pRand.end()){
                    cout << *iter - curPos << '\n';
                }
                else{
                    iter = pRand.begin();
                    cout << *iter - curPos + N << '\n';
                }
            }
        }
    }
        
        

    


    return 0;    
}
