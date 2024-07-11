#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, D;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) 
        return a.first < b.first;
    else 
        return a.second < b.second;
}
 

int main(){
    fastio;
    int l, r;
    cin >> N;
    priority_queue<int> pq;
    vector<pair<int, int> > v;

    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;        
        v.push_back({min(l, r), max(l, r)});
    }
    cin >> D;
    int answer = 0;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++)
    {
        int st = v[i].first;
        int ed = v[i].second;
        if(ed - st <= D) pq.push(-st);
        else continue;
        while (!pq.empty())
        {
            if(-pq.top() < ed - D) pq.pop();
            else {answer = max(answer, (int)pq.size()); break;}            
        }
        
    }
    cout << answer;
    
    return 0;
}