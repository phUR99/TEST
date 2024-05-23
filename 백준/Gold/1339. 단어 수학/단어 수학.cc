#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    while (N--)
    {
        string str;
        cin >> str;
        int power = 1;
        for (int i = str.length()-1; i >= 0; i--)
        {
            char c = str[i];
            cnt[c-'A'] += power;
            power *= 10;
        }
        

    }
    int ans = 0;    

    for (int i = 9; i >= 0; i--)
    {
        auto M = max_element(cnt, cnt+26);
        ans += i * (*M);
        *M = 0;
    }

    cout << ans;
    
    return 0;

}