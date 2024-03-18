#include <bits/stdc++.h>
using namespace std;




int n, m, h;
int ladderInfo[50][50];

bool exam(int st, int cur, int cnt){
    bool ret = false;
    if(cnt == h+1){
        if (cur == st) return true;
        else return false;
    }
    if (ladderInfo[cnt][cur] == 0 ){
        ret = ret || exam(st, cur, cnt+1);
    }
    else if (ladderInfo[cnt][cur] == 1){
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


void makeladder(int cur, int cnt){
    if(cnt == cur){
        if(examine()){
           cout << cur;
           exit(0);
        }        
        return;
    }
    for (int j = 1; j <= h; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if(ladderInfo[j][i] == 0 && ladderInfo[j][i+1] == 0){
                ladderInfo[j][i]=1; ladderInfo[j][i+1] =2;
                makeladder(cur+1, cnt);
                ladderInfo[j][i]=0; ladderInfo[j][i+1] =0;
            }
        }   ;
    }
    
    
}

int main(){
    cin >> n >> m >> h;
    while (m--)
    {
        int num, pos;
        cin >> num >> pos;
        ladderInfo[num][pos] =1; ladderInfo[num][pos+1] = 2;        
    }
    for (int i = 0; i < 4; i++)
    {        
        makeladder(0, i);
    }
    cout << -1;
    
    return 0;
}