#include <bits/stdc++.h>

using namespace std;


bool diff(string &s1, string &s2){
    int l = s1.size();
    int ret = 0;
    for (int i =0; i < l; i++)
        ret += (s1[i] != s2[i]);
    return ret <=1;
}
int bfs(string begin, string target, vector<string>&words){
    vector<int> dist(words.size()+1, -1);
    words.push_back(begin);
    auto find = [](string s, vector<string> &words)
    {
        for (int i = 0; i< words.size(); i++) 
            if(words[i] ==s) return i;
        return -1;
    };
    queue<int> q;
    q.push(find(begin, words));
    dist[find(begin, words)] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        for (int there = 0; there < words.size(); there++){
            if(dist[there] != -1) continue;
            if(diff(words[here], words[there])){
                q.push(there);
                dist[there] = dist[here] +1;
            }
        }
    }
    if(find(target, words) == -1)
            return -1;
    return dist[find(target, words)];
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = bfs(begin, target, words);
    if(answer == -1) answer = 0;
    
    return answer;
}