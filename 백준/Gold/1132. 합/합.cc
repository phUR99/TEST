#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
long long number[10];
bool notZero[10];

int main(){
    fastio;
    cin >> N;
    string str;
    long long power = 1;
    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        power = 1;
        for (int j = str.size()-1; j >= 0; j--)
        {
            number[str[j]-'A'] += power;
            power *= 10;
            if(j==0) notZero[str[j]-'A'] = true;
        }        
    }
    int idx = 0;
    long long cur = 0x7fff'ffff'ffff'ffff;
    for (int i = 0; i < 10; i++)
    {
        if(!notZero[i] && cur > number[i]){
            cur = number[i];
            idx = i;
        }
    }
    number[idx] = 0;

    for (long long i = 9; i > 0; i--)
    {
        int idx = max_element(number, number+10) - number;
        ans += number[idx] * i;
        number[idx] = 0;
    }
    cout << ans;



    return 0;
}