#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int r, c;
string cmd;
char board[16][16];
bool check[16][16];
static int cnt = 1;
int px, py;

void move(char c){
    string str = "UDLR";
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int dir = str.find(c);
    int nx = dx[dir] + px;
    int ny = dy[dir] + py;
    if (board[nx][ny] == '#') return;
    if (board[nx][ny] == 'b'){
        int nnx = nx + dx[dir];
        int nny = ny + dy[dir];
        if (board[nnx][nny] != '.') return;
        swap(board[nnx][nny], board[nx][ny]);
    }
    swap(board[nx][ny], board[px][py]);
    px = nx;
    py = ny;
}
bool isend(){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (check[i][j] && board[i][j] != 'b') return false;
        }
        
    }
    return true;
}

void solve(){
    memset(check, 0, sizeof(check));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '+') {
                check[i][j] = 1;
                board[i][j] = '.';
            }
            if (isupper(board[i][j])){
                check[i][j] = 1;
                board[i][j] = tolower(board[i][j]);
            }
            if (board[i][j] == 'w') {
                px = i;
                py = j;
            }

        }
        
    }
    cin >> cmd;
    bool flag = false;
    for (auto s : cmd)
    {
        if(isend()) {
            flag = true;
            break;
        }
        move(s);
    }
    if (isend()) flag = true;
    string str = (flag ? "complete" : "incomplete");

    cout << "Game " << cnt++ << ": " << str << '\n';

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            
            if (check[i][j] && isalpha(board[i][j])) board[i][j] = toupper(board[i][j]);
            else if (check[i][j] && !isalpha(board[i][j])) board[i][j] = '+';
            cout << board[i][j];
        }
        cout << '\n';
    }
    
}

int main()
{
    fastio;
    
    while (1)
    {
        cin >>r >> c;
        if(!r && !c) break;
        solve();
    }
    
    return 0;
}