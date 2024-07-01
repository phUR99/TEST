#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T, N, K;


int main(){
    fastio;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        list<int> soldier;
        for (int i = 1; i <= N; i++)
        {
            soldier.push_back(i);
        }                        
        list<int>::iterator kill = soldier.begin();
        while (N > 2)
        {
            kill = soldier.erase(kill);
            if(kill == soldier.end()) kill = soldier.begin();
            --N;
            for (int i = 0; i < K-1; i++)
            {
                kill = next(kill);
                if(kill == soldier.end()) kill = soldier.begin();
            }            
        }
        for (auto sol :soldier)
        {
            cout << sol << ' ';
        }
        cout << '\n';
    }    
    return 0;
}