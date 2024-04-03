#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int board[52][52];
void rotate(int x, int d, int k){
    queue<int> q;
    for (int i = x; i <= n; i += x)
    {
        for (int j = 1; j <= m; j++)
        {
            int idx = d ? j + k : j - k;
            if (idx < 1) idx += m;
            else if(idx > m) idx -=m;
            q.push(board[i][idx]);
        }
        for (int j = 1; j <= m; j++)
        {
            board[i][j] = q.front(); q.pop();
        }
        
    }
    return;
}
void masking(){
    bool visited[52][52];
    memset(visited, false, sizeof(visited));
    /*
    (i, 1)은 (i, 2), (i, M)과 인접하다.
    (i, M)은 (i, M-1), (i, 1)과 인접하다.
    (i, j)는 (i, j-1), (i, j+1)과 인접하다. (2 ≤ j ≤ M-1)
    (1, j)는 (2, j)와 인접하다.
    (N, j)는 (N-1, j)와 인접하다.
    (i, j)는 (i-1, j), (i+1, j)와 인접하다. (2 ≤ i ≤ N-1)
    */
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int bef, nxt, cbef, cnxt;
            bool a, b, c, d;
            if(board[i][j] == 0) continue;
            bef =  (j  == 1) ? m : j -1;
            nxt =  (j  == m) ? 1 : j +1;
            cbef = i - 1;
            cnxt = i + 1;
            a = (board[i][j] == board[i][bef]) ;
            b = (board[i][j] == board[i][nxt]) ;
            if(i == 1){
                c = (board[i][j] == board[cnxt][j]) ;
                visited[i][j] = (a || b || c);
            }
            else if (i == n){
                d = (board[i][j] == board[cbef][j]);
                visited[i][j] = (a || b || d);
            }
            else{
                c = (board[i][j] == board[cnxt][j]) ;
                d = (board[i][j] == board[cbef][j]) ;
                visited[i][j] = (a || b || c || d);
            }
            
        }
        
    }
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(visited[i][j]) {
                board[i][j] = 0;                
                flag = true;
            }
            sum += board[i][j];
            if(board[i][j]) cnt++;
            
        }
        
    }
    if (flag == false){
        if(cnt == 0) return;        
       
        if(sum % cnt == 0){            
            sum /= cnt;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if(board[i][j] != 0 && board[i][j] < sum) board[i][j]++;
                    else if (board[i][j] > sum) board[i][j]--;
                }
            }
        }    
        else{
            sum /= cnt;           
            for (int i = 1; i <= n; i++)
            {
                   
                for (int j = 1; j <= m; j++)
                {
                    if(board[i][j] != 0 && board[i][j] <= sum) board[i][j]++;
                    else if (board[i][j] > sum) board[i][j]--;
                }
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
        
    }
    while (t--)
    {
        int x, d, k;
        cin >> x >> d >> k;        
        rotate(x, d, k);
        masking();
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += board[i][j];
        }
        
    }
    cout << ans;

    return 0;    
}