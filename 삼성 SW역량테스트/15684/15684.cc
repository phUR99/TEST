#include <bits/stdc++.h>
using namespace std;

/*
1. 처음에 틀렸던 이유 : M이 0이 아니어도 가로선을 0개만 쓰고 풀 수 있다는 사실을 간과했음 -> 경우의 수를 빡빡하게 세야한다
2. 시간초과의 위험성 : 현재 풀이로는 0.8초까지가 한계지만 나중에 더 좋은 풀이를 찾아보자
*/


int n, m, h;
int ladderInfo[50][50];
const int MX = 987654321;
int ans = MX;

bool exam(int st, int cur, int cnt){
    bool ret = false;
    while (ladderInfo[cnt][cur] == 0 && cnt <=h) cnt++;   
    if(cnt == h+1 && cur == st){
        return true;                
    }                      
    if(abs(cur-st) > h+1 - cnt) return false;
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
