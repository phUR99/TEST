#include <bits/stdc++.h>
using namespace std;
int n, m;
/*
1부터 순서대로 ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 이다.
*/
int dx[] ={0,  0, -1, -1, -1, 0, 1, 1,  1};
int dy[] ={0, -1, -1,  0,  1, 1, 1, 0, -1};
// 격자의 가장 왼쪽 윗 칸은 (1, 1)이고, 가장 오른쪽 아랫 칸은 (N, N)이다
// A[r][c]는 (r, c)에 있는 바구니에 저장되어 있는 물의 양을 의미한다.
// N번 행의 아래에는 1번 행이, 1번 행의 위에는 N번 행이 있고, 
// 1번 열의 왼쪽에는 N번 열이, N번 열의 오른쪽에는 1번 열이 있다.
// 비바라기를 시전하면 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다
int A[55][55];
bool state[55][55];
bool oob(int x, int y){
    return x <=0 || x > n || y <=0 || y> n;
}
void changeState(int &cur){
    if(cur <= 0){
        while (cur <= 0)
        {
            cur += n;
        }        
        return;
    }
    else if(cur > n){
        while (cur > n)
        {
            cur -= n;
        }   
        return;
    }
    else return;
}

void moveCloud(int dir, int cnt){
    bool nxt_state[55][55];
    memset(nxt_state, false, sizeof(nxt_state));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(state[i][j] == true){
                int nx = i + dx[dir] * cnt;
                int ny = j + dy[dir] * cnt;
                changeState(nx);
                changeState(ny);
                nxt_state[nx][ny] = true;
            }
        }
        
    }
    memset(state, false, sizeof(state));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            state[i][j] = nxt_state[i][j];
        }
        
    }
    return;
}
void rain(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(state[i][j] == true){
                A[i][j]++;              
            }
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(state[i][j] == true){
                for (int dir = 2; dir <= 8; dir +=2)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(oob(nx, ny)) continue;
                    if(A[nx][ny] > 0){
                        A[i][j]++;
                    }
                }               
            }
        }
        
    }      
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)        
        {
            if(state[i][j]){
                state[i][j] = false;
                continue;
            }
            if (A[i][j] >= 2){
                state[i][j] = true;
                A[i][j] -=2;
            }
        }
        
    }
    
}
/*
void printstate(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << state[i][j] << ' ';
        }
        cout << '\n';
    }
}
void printA(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

}
*/
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
        
    }
    state[n][1] = true;
    state[n-1][1] = true;
    state[n][2] = true;
    state[n-1][2] = true;

    while (m--)
    {
        int d, s;
        cin >> d >> s;
        moveCloud(d, s);
        rain();
        /*
        cout << '\n';
        printstate();
        printA();
        cout << '\n';
        */
    }
    int ans =0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
           ans += A[i][j];
        }
        
    }
    cout << ans;
    return 0;
}