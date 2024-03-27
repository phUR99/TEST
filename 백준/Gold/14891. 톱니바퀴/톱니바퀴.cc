#include <bits/stdc++.h>
using namespace std;
string chain[4];
int score[] = {1, 2, 4, 8};

void rotate(int p, int d){
    int dirChange[4];
    dirChange[p] = d;

    for (int i = p; i < 3; i++)
    {
        if(chain[i][2] == chain[i+1][6]) dirChange[i+1] = 0;
        else dirChange[i+1] = -dirChange[i];
    }
    for (int i = p; i > 0; i--){
        if(chain[i][6] == chain[i-1][2]) dirChange[i-1] = 0;
        else dirChange[i-1] = -dirChange[i];
    }
    for (int j = 0; j < 4; j++){
        queue<char> q;
        for (int i = 0; i < 8; i++)
        {
            int k = (i - dirChange[j] < 0) ? 7 : (i - dirChange[j]) % 8;
            q.push(chain[j][k]);
        }
        for (int i = 0; i < 8; i++)
        {
            chain[j][i] = q.front(); q.pop();
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    for (int i = 0; i < 4; i++)
    {
        cin >> chain[i];
    }
    int k;
    cin >> k;

    while (k--)
    {
        int pos, dir;
        cin >> pos >> dir;
        pos--;        
        rotate(pos, dir);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if(chain[i][0] == '1')  ans += score[i];
    }
    cout << ans;

    return 0;    
}