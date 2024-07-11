#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, L, P;
#define dest first
#define fuel second

int main(){
    fastio;
    priority_queue<int> pq;    
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].dest >> v[i].fuel;
    }
    cin >> L >> P;       
    sort(v.begin(), v.end());
    int idx = 0; 
    for (int i = 1; i < L; i++)
    {
        while (idx < v.size() && P >= v[idx].dest)
        {
            pq.push(v[idx].fuel);
            idx++;
        }
        if(i >= P){
            while (!pq.empty())
            {
                P += pq.top(); pq.pop();
                if(P > i) break;
            }            
        }
        if(i >= P) {
            cout << -1;
            return 0;
        }
    }
    cout << N - pq.size();

    return 0;
}