#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
int d[50005];

int main(){
    fastio;
    cin >> N;
    int pSum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> d[i];
        pSum += d[i];
    }
    int st = 0, ed = 0;
    int dRight = 0, dLeft = pSum;
    int ans = -1;
    int tmp;

    while (st <= ed && ed < N)
    {
        tmp = min(dRight, dLeft);        
        /*
        cout << "dRight, dLeft : " << dRight << ", " << dLeft << '\n';
        cout << "tmp : " << tmp  << '\n';        
        */
        if(dRight < pSum / 2){               
            dRight += d[ed];
            dLeft -= d[ed];
            ed++;
        }
        else{
            dLeft += d[st];
            dRight -= d[st];
            st++;
        }
        ans = max(ans , tmp);
    }
    cout << ans;

    return 0;
}