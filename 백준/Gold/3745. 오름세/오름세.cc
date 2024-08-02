#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int great[100000];
int idx, tmp;
int N;

int main(){
    fastio;
    while (cin >> N)
    {
        memset(great, 0, sizeof(great));
        idx = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            if(tmp > great[idx]) {
                idx++;
                great[idx] = tmp;
            }
            else{
                int pos = lower_bound(great, great+idx+1, tmp) - great;
                great[pos] = tmp;
            }
        }
        cout << idx << '\n';
    }
    

    return 0;
}