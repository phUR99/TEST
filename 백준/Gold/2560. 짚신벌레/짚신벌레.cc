#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int a, b, d, n;
queue<ll> life, dead, mature;

int main()
{
    fastio;
    cin >> a >> b >> d >> n;
    ll sum = 0;
    for (int i = 0; i < a-1; i++)
    {
        mature.push(0);
    }
    mature.push(1);
    for (int i = 0; i < b-a; i++)
    {
        life.push(0);
    }
    
    for (int i = 0; i < d-b; i++)
    {
        dead.push(0);
    }
    for (int i = 0; i <n; i++)
    {
        ll adult = mature.front(); 
        mature.pop();
        sum += adult;
        life.push(adult);

        ll old = life.front();
        life.pop();

        sum -= old;
        sum = (sum+1000)%1000;
        mature.push(sum);
        dead.push(old);
        dead.pop();
        
    }
    while (!dead.empty())
    {
        sum += dead.front(); dead.pop();
        sum %= 1000;
    }
    while (!mature.empty())
    {
        sum += mature.front(); mature.pop();
        sum %= 1000;
    }
    
    
    cout << sum;
    
    

    return 0;
}