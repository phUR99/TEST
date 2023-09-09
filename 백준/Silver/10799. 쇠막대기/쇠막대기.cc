#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {

    string str;
    int cnt = 0;
    cin >> str;
 
    stack<int> s;		
    for (int i = 0; i != str.size(); i++)
    {
        if (str[i] == '(') s.push('(');
        else {
            if (str[i - 1] == '(') {
                s.pop();
                cnt += s.size();
            }
            else {
                s.pop();
                cnt++;

            }
            
        }


    }
    cout << cnt;



}