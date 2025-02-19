#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i : works) pq.push(i);
    int sum = accumulate(works.begin(), works.end(), 0);
    if(sum <= n) return 0;
    while(n--){
        int here = pq.top(); pq.pop();
        here--;
        if(here == 0) continue;
        pq.push(here);
    }
    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        answer += 1LL * cur * cur;
    }
        
    
    return answer;
}