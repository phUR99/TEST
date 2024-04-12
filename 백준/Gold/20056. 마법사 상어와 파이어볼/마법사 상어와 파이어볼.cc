#include <bits/stdc++.h>
using namespace std;
// 대각선 1, 3, 5, 7;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = { 0,  1, 1, 1, 0, -1, -1, -1};
int n, m, k;
struct info{
    int mass, speed, direction;
};
queue<info> board[55][55];
queue<info> tmp_board[55][55];

void change(int& p){
    while (p > n)
    {
        p -= n ;
    }
    while (p < 1)
    {
        p += n;
    }
    return;    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    while (m--)
    {
        int x, y, m, s ,d;
        cin >> x >> y >> m >> s >> d;      
        board[x][y].push({m, s, d});                        
    }
    while (k--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                auto &q = board[i][j];                
                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    int x = i + dx[cur.direction] * cur.speed;
                    int y = j + dy[cur.direction] * cur.speed;
                    int m = cur.mass;
                    change(x);
                    change(y); 
                    auto &Q = tmp_board[x][y];
                    Q.push({m, cur.speed, cur.direction});
                }                         
            }            
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                auto &q = tmp_board[i][j];
                auto &Q = board[i][j];
                if (q.empty()) continue;
                if (q.size() < 2){
                    auto cur = q.front(); q.pop();
                    Q.push(cur);
                    continue;
                }
                vector<int> dir;
                int sumMass = 0;
                int sumSpeed = 0;
                int cnt = 0;                                
                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    sumMass += cur.mass;
                    sumSpeed += cur.speed;
                    dir.push_back(cur.direction %2);
                    cnt++;
                }
                sumMass /= 5;
                if(sumMass == 0) continue;
                sumSpeed /= cnt;
                int flag = 0;
                int cnt1 = 0;
                int cnt2 = 0;
                for (auto cur : dir)
                {
                    if(cur) cnt1++;
                    else cnt2++;
                }
                if(cnt1 && cnt2) flag = 1;
                
                for (int p = flag; p < 8; p += 2)
                {
                    Q.push({sumMass, sumSpeed, p});
                }                
            }
            
        }
        
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            auto &q = board[i][j];            
            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                ans += cur.mass;
            }                       
        }
        
    }
    cout << ans;

    return 0;
}