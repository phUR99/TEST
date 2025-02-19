#include <bits/stdc++.h>
using namespace std;
int cache[105][105];
int mm, nn;
const int MOD =1e9+7;
int board[105][105];
int solve(int x, int y)
{
    if(board[x][y]) return 0;
    if(x == mm && y == nn) return 1;
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    ret= 0;
    if(x< mm)
        ret += solve(x+1, y);
    if(y <nn)
        ret += solve(x, y+1);
    return ret %= MOD;
}


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    mm = m;
    nn = n;
    memset(cache, -1, sizeof(cache));
    for(auto i : puddles) board[i[0]][i[1]] = 1;
    answer = solve(1, 1);    
    return answer;
}