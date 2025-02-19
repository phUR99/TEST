#include <bits/stdc++.h>
using namespace std;
vector<string> parse(const string &str){
    int pos;
    int cur = 0;
    int len;  
    vector<string> ret;
    while((pos = str.find(' ', cur)) != string::npos){
        len = pos - cur;
        ret.push_back(str.substr(cur, len));
        cur = pos +1;
    }
    return ret;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> dict;
    for (string op : operations){
        op += ' ';
        vector<string> tmp = parse(op);
        if(tmp.front() == "I")
            dict.insert(stoi(tmp.back()));
        else{
            if(dict.empty()) continue;
            if(tmp.back() == "1")
                dict.erase(prev(dict.end()));
            else
                dict.erase(dict.begin());                
        }
            
    }
    if(dict.empty()) answer = {0, 0};
    else answer = {*dict.begin(), *prev(dict.end())};
    reverse(answer.begin(), answer.end());
    return answer;
}