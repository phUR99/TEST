#include <bits/stdc++.h>

using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b){
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);    
    int pos = -987654321;
    for(auto route : routes){
        int e = route[1];
        int s = route[0];
        if(s > pos){
            answer++;
            pos = max(e, pos);
        }        
    }
    return answer;
}