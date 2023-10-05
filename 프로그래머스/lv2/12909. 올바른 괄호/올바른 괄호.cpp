#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for (auto i : s){
        if(stk.empty()){
            if(i==')'){
                answer = 0;
                return answer;
            }
            stk.push(i);
        }
        else{
            if(i==')'){
                stk.pop();
            }
            else stk.push(i);
        }
        
    }
    
    answer = (stk.empty()) ? 1 : 0;
    return answer;
}