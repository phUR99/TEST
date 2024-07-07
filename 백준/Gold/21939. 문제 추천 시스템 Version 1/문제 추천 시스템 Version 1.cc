#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
set<int> diff[101];

int main(){
    fastio;
    int N, M;
    int P, L;

    cin >> N;
    while (N--)
    {
        
        cin >> P >> L;        
        diff[L].insert(P);
    }    
    cin >> M;
    while (M--)
    {
        string str;
        cin >> str;
        if(str == "add"){
            cin >> P >> L;            
            diff[L].insert(P);
        }
        else if(str == "solved"){
            cin >> P;
            for (int i = 100; i >= 0; i--)
            {
                if(diff[i].find(P) == diff[i].end()) continue;
                diff[i].erase(diff[i].find(P));
                break;
            }                        
        }
        else{
            cin >> L;                                  
            if(L == 1){                
                for (int i = 100; i >= 0; i--)
                {
                    if(diff[i].empty()) continue;
                    auto it = diff[i].end();
                    it--;
                    cout << *it << '\n';
                    break;
                }               
            }
            else{                
                for (int i = 1; i <= 100; i++)
                {
                    if(diff[i].empty()) continue;
                    auto it = diff[i].begin();                
                    cout << *it << '\n';
                    break;
                }
            }            
        }
    }
    


    return 0;
}