#include <bits/stdc++.h>
using namespace std;
/*
못 푼 이유 : idx번째부터 idx + L 번째를 어떻게 체크해야할 지를 구현하지 못했음
1. 벡터를 선언해서 필요한 행 혹은 열의 원소를 받는다
2. 그 벡터를 탐색하면서 경사로를 깔 수 있는 지를 체크한다.
3. idx와 cnt를 쓰는 것을 생각하는 게 핵심이었음. 
현재 원소보다 앞에 있는 원소가 클 경우 cnt의 개수가 L보다 크다면 cnt를 1로 만들고 idx를 증가시킨다. (이 부분을 생각을 못했음)
현재 원소보다 앞에 있는 원소가 작을 경우 앞에 있는 원소부터 L-1번째부터 전부 같은 지 체크하고 
같다면 idx+L로 idx를 변경하고 cnt를 0으로 바꾼다 -> 사용했기 때문에 쓸 수 없다.(이 부분을 구현하지 못했음)
*/
int n, L;
int board[105][105];
int ans =0;
int check(vector<int>& line){
    int idx =0;
    int cnt =1;
    while (idx < n -1)
    {
        if(abs(line[idx+1] - line[idx]) > 1) return 0;
        if(line[idx+1] - line[idx] == 0){
            idx++;
            cnt++;
        }
        else if(line[idx+1] - line[idx] > 0){
            if (cnt < L) return 0;
            cnt = 1;
            idx++;
        }
        else{
            if (idx + L >=n) return 0;
            for (int i = idx + 1; i < idx + L; i++)
            {
                if(line[i] != line[i+1]) return 0;

            }
            idx = idx+ L;
            cnt =0;            
        }
    }
    return 1;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> L;
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> line;
        for (int j = 0; j < n; j++) line.push_back(board[i][j]);                
        ans += check(line);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> line;
        for (int j = 0; j < n; j++) line.push_back(board[j][i]);                
        ans += check(line);
    }
    cout << ans;
    return 0;
}