#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n;
int idxEnter[26];

int main(){
    fastio;

    cin >> n;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        memset(idxEnter, -1, sizeof(idxEnter));
        for (int j = 0; j < str.length(); j++)
        {
            if(idxEnter[str[j]-'a'] == - 1) idxEnter[str[j]-'a'] = j;
            else{
                if(j - idxEnter[str[j]-'a'] != 1){
                    ans--;
                    break;
                }
                idxEnter[str[j]-'a'] = j;
            }            
        }        
    }
    cout << ans;

    return 0;
}