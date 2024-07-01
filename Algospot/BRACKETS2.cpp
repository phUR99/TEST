#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T;

string determine(const string &str){
    stack<char> leftBracket;
    for (int i = 0; i < str.size(); i++)
    {
        char cur = str[i];
        if (cur == '(' || cur =='{'|| cur =='[') leftBracket.push(cur);
        else{
            if(leftBracket.empty()) return "NO";
            char top = leftBracket.top();
            if((cur == ')' && top == '(') || (cur == '}' && top == '{') || (cur == ']' && top == '[')) leftBracket.pop();            
            else return "NO";
        }
    }
    if(leftBracket.empty()) return "YES";
    else return "NO";
}


int main(){
    fastio;

    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        string ans = "";
        ans = determine(str);
        cout << ans << '\n';
    }    
    return 0;    
}
