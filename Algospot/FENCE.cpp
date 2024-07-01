#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector<int> h;
int T, N;

int solveStack(){
    stack<int> remaining;
    h.push_back(0);
    int ret = 0;
    for (int i = 0; i < h.size(); i++){
        while (!remaining.empty() && h[remaining.top()] >= h[i])
        {
            int j = remaining.top(); remaining.pop();
            int width = -1;

            if(remaining.empty()){
                width = i;
            }
            else{
                width = i - 1 - remaining.top();
            }
            ret = max(ret, h[j] * width);
        }
        remaining.push(i);
    }
    return ret;
}


int main(){
    fastio;
    cin >> T;
    while (T--)
    {        
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            h.push_back(tmp);
        }
        int ans = solveStack();
        cout << ans << '\n';
        h.clear();
    }
    

    return 0;
}