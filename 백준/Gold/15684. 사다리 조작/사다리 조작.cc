#include <bits/stdc++.h>
using namespace std;




int n, m, h;
int ladderInfo[50][50];
const int MX = 987654321;
int ans = MX;

bool exam(int st, int cur, int cnt){
    bool ret = false;
    while (ladderInfo[cnt][cur] == 0 && cnt <=h) cnt++;   
    if(cnt == h+1){
        if(cur == st)return true;        
        else return false;
    }                      
    if (ladderInfo[cnt][cur] == 1){
        ret = ret || exam(st, cur+1, cnt+1);
    }
    else{
        ret = ret || exam(st, cur-1, cnt+1);
    }
    return ret;
}

bool examine(){
    for (int i = 1; i <= n; i++)
    {
        if(!exam(i, i, 1)){
            return false;
        }
    }    
    return true;
}


void makeladder(int xPos, int cur){
    if(cur > 3){     
        return;
    }
    if (examine()){
        ans = min(ans, cur);
        return;
    }
    for (int j = xPos; j <= h; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if(ladderInfo[j][i] == 0 && ladderInfo[j][i+1] == 0){
                ladderInfo[j][i]=1; ladderInfo[j][i+1] =2;
                makeladder(j, cur+1);
                ladderInfo[j][i]=0; ladderInfo[j][i+1] =0;
            }
        }
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> n >> m >> h;
    while (m--)
    {
        int num, pos;
        cin >> num >> pos;
        ladderInfo[num][pos] =1; ladderInfo[num][pos+1] = 2;        
    }
    makeladder(1, 0);
    cout << (ans == MX ? -1 : ans);    
    return 0;
}