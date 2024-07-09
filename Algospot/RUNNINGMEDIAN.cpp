#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long T, N, a, b, answer;


int main(){
    fastio;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> a >> b;
        answer = 0;
        int A = 1983;
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;        

        for (int n = 0; n < N; n++)
        {
            right.push(A);
            if(right.size() > left.size()){
                left.push(right.top());
                right.pop();
            }
            if(!left.empty() && left.top() > right.top()){
                int r = right.top();
                right.pop();
                int l = left.top();
                left.pop();
                left.push(r);
                right.push(l);                
            }
            answer += left.top();
            answer %= 20090711;
            A = (A * a + b) % 20090711;
        }
        cout << answer << '\n';
    }
    

    return 0;
}