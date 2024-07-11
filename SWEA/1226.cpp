#include <iostream>
#include <queue>
#include <string.h>
#define SIZE 16

using namespace std;
int board[SIZE][SIZE];
bool visited[SIZE][SIZE];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool solution(pair<int, int> st, pair<int, int> ed){
    queue<pair<int, int>> q;
    q.push(st);
    visited[st.first][st.second] = true;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
            if(board[nx][ny] || visited[nx][ny]) continue;
            if(nx == ed.first && ny == ed.second) return 1;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
        
    }
    return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    T = 10;
    pair<int, int> st, ed;
    char c;
    int answer;
    int t;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> t;
        answer = 0;           
        memset(visited, false, sizeof(visited));        
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {                
                cin >> c;
                board[i][j] = c - '0';
                if(board[i][j] == 2) {st.first = i; st.second =j; board[i][j] = 0;}
                if(board[i][j] == 3) {ed.first = i; ed.second =j; board[i][j] = 0;}
            }            
        }        
        answer = solution(st, ed);
        cout << "#" << test_case << ' ';
        cout << answer << '\n';
	}
	return 0;
}