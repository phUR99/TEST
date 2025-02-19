#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    multiset<int> m;
    for(int i : B) m.insert(i);
    for(int i : A){
        auto u = m.upper_bound(i);
        if(u != m.end()) {
            m.erase(u);
            answer++;
        }
        else{
            m.erase(m.begin());
        }
    }
    return answer;
}