#include <bits/stdc++.h>
using namespace std;
int n;
int arr[40];


int solve(int idx, int state){
    if(idx == n) return state == (1 << 26) - 1;
    int ret = 0;
    ret += solve(idx + 1, state);
    ret += solve(idx + 1, state | arr[idx]);
    return ret;

}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int cur = 0;
        for (auto &s : str)
        {
            cur |= (1<<(s - 'a'));
        }   
        arr[i] = cur;
    }
    int ret = solve(0, 0);
    cout << ret;   

    return 0;
}