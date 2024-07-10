#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SIZE 100
int T = 10;
int n;
int ladder[SIZE][SIZE];
bool visited[SIZE][SIZE];

int answer;

int main(){
    fastio;
    
    for (int t = 0; t < T; t++){
        cin >> n;
        int x = SIZE-1; int y = SIZE-1;
        for (int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++){
                cin >> ladder[i][j];
                visited[i][j] = false;
                if(ladder[i][j] == 2){
                    x = i;
                    y = j;
                }
            }
        }        
        while (x >= 0)
        {
            visited[x][y] = true;
            if(y - 1 >= 0 && ladder[x][y-1] && !visited[x][y-1]) y--;
            else if(y +1 < SIZE && ladder[x][y+1] && !visited[x][y+1]) y++;
            else x--;            
        }
        answer = y;
        cout << "#" << n << ' ';
        cout << answer << '\n';
    }

    return 0;
}