#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MX = 987654321;
// n = 100
// c = 4
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int n;
const int dx[] = {MX, -1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {MX, 0, -1, -1, -1, 0, 1, 1, 1};
int table[9][8];
int board[105][5];
int tmp_board[105][5];
int BUFFER[105][5];
int idx[] ={0, 0, 0, 0, 0};
pair<int ,int> ORDER[105], tmp_ORDER[105];
int ans = 0;

int play(){
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int block = tmp_ORDER[i].first;
        int &pos = idx[tmp_ORDER[i].second];
        tmp_board[pos][tmp_ORDER[i].second] = block;
        pos++;
        int SIZE = MX;     
        int MAX = 0;   
        while (true)
        {   memset(BUFFER, 0, sizeof(BUFFER));
            for (int j = 1; j <= 4; j++)
            {
                SIZE = min(SIZE, idx[j]);
                MAX = max(MAX, idx[j]);
            }
            if(!SIZE) break;
            ret += SIZE; 
            for (int row = 0; row < SIZE; row++){
                for (int j =1; j <=4; j++){
                    tmp_board[row][j] = 0;
                }
            }
            for (int row = 0; row < MAX; row++)
            {
                for (int j =1; j <=4; j++){
                    int cur = tmp_board[row][j];
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int direction = table[cur][dir];
                        int nx = row + dx[direction];
                        int ny = j + dy[direction];
                        if (nx < 0 || ny < 1 || ny > 4) continue;
                        if (BUFFER[nx][ny] == 0) BUFFER[nx][ny] = cur;
                        else BUFFER[nx][ny] = min(BUFFER[nx][ny], cur);
                        break;
                    }
                    
                }
            }
            for (int j =1; j <=4; j++){
                int &tmp = idx[j];
                tmp = 0;
                for (int row = 0; row < MAX + 1; row++)
                {
                    if(BUFFER[row][j] == 0) continue;
                    tmp_board[tmp][j] = BUFFER[row][j];
                    tmp++;
                }                           
            }            
        }        
    }
    return ret;    
}


void make_ORDER(int cnt){    
    while (!ORDER[cnt].second == 0 && cnt < n)
    {
        tmp_ORDER[cnt].first = ORDER[cnt].first;
        tmp_ORDER[cnt].second = ORDER[cnt].second;
        cnt++;
    }
    if (cnt == n){
        ans = max(ans, play());
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        tmp_ORDER[cnt].first = ORDER[cnt].first;
        tmp_ORDER[cnt].second= i;
        make_ORDER(cnt+1);
    }
    


}


int main() {
    cin >> n;
    for (int i = 1; i <=8; i++){
        for(int j = 0; j < 8; j++){
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        cin >> ORDER[i].first;
        cin >> ORDER[i].second;
    }
    make_ORDER(0);
    cout << ans;

    return 0;
}