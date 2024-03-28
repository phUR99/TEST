#include <bits/stdc++.h>
using namespace std;
/*
1. 나무를 어떻게 관리할까에 대한 고민이 필요
2. 문제 잘 읽기.. 초기 땅의 비료 값을 5로 설정이 되어있었다.

*/
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
int n, m, k;
int A[12][12];
vector<int> treeInfo[12][12];
queue<int> deadTree[12][12];
int curFood[12][12];

void spring(){
    for (int i =1; i <=n; i++){
        for (int j = 1; j <= n; j++)
        {
            if(treeInfo[i][j].empty()) continue;
            for (auto idx = treeInfo[i][j].begin(); idx != treeInfo[i][j].end();)
            {
                if (curFood[i][j] >= *idx) {
                    curFood[i][j] -= *idx;
                    // *(idx)++는 idx의 값을 증가시키는 구문임
                    (*idx)++;
                    idx++;              
                }
                else{
                    deadTree[i][j].push(*idx);
                    // erase를 할 경우 반복자가 무효화 되므로 erase의 return을 받는 식으로 업데이트 필요
                    idx = treeInfo[i][j].erase(idx);
                    
                }                
            }
            
        }
        
    }
    return;
}
void summer(){

    for (int i =1; i <=n; i++){
        for (int j = 1; j <= n; j++)
        {
            while (!deadTree[i][j].empty())
            {
                int cur = deadTree[i][j].front(); deadTree[i][j].pop();
                curFood[i][j] += cur /2;
            }
                                   
        }
        
    }
    return;
}
void autumn(){
    for (int i =1; i <=n; i++){
        for (int j = 1; j <= n; j++)
        {
            if(treeInfo[i][j].empty()) continue;
            for (auto idx = treeInfo[i][j].begin(); idx != treeInfo[i][j].end(); idx++)
            {
                if(*idx % 5 == 0){
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        auto it = treeInfo[nx][ny].begin();
                        treeInfo[nx][ny].insert(it , 1);
                    }
                    
                }
            }
            
        }
        
    }
    return;
}
void winter(){
    for (int i =1; i <=n; i++){
        for (int j = 1; j <= n; j++)
        {
            curFood[i][j] += A[i][j];
        }
        
    }
    return;
}


void spendTime(int day){
    if(day == k) return;
    spring();
    summer();
    autumn();
    winter();
    spendTime(day + 1);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i =1; i <=n; i++){
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
            curFood[i][j] = 5;
        }
        
    }
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        treeInfo[x][y].push_back(c);

    }
    spendTime(0);
    int ans = 0;
    for (int i =1; i <= n; i++){
        for (int j = 1; j <= n; j++)
        {
            if(treeInfo[i][j].empty()) continue;
            ans += (int)treeInfo[i][j].size();
        }
        
    }    
    cout << ans;

    return 0;
}