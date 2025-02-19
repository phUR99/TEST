#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    answer.resize(n, s/n);
    if(s/n ==0) return vector<int>(1, -1);
    int remain = s - s/n *n;
    for(int i=0; i <remain; i++) answer[i]++;
    reverse(answer.begin(), answer.end());
    return answer;
}