#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
char board[500005];

int main(){
    fastio;
    int N, K;
    cin >> N >> K;
    stack<char> s;
    int size = N - K;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];     
        while (K > 0 && !s.empty() && s.top() < board[i])
        {
            s.pop();
            K--;
        }
        if(s.size() < size) s.push(board[i]);    
    }
    string answer = "";
    while (!s.empty())
    {
        answer += s.top(); s.pop();
    }
    reverse(answer.begin(), answer.end());
    cout << answer;


    return 0;
}