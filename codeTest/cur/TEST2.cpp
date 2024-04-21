#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int board[25][25];
int tmp_board[25][25];
bool path[25][25];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            if(tmp){
                board[i][j] = tmp;
                path[i][j] = true;
                if(board[i][j] == 4) board[i][j] = 0;
            }            
        }
    }

    return 0;
}