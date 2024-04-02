#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
int board[12][12];
int paper[6] = {0, 5, 5, 5, 5, 5};
bool visited[12][12];

struct node
{
    int x, y;
};
int ans = MX;
vector<node> one;
bool zero(const vector<node>::iterator it, int idx){
    int x = it->x;
    int y = it->y;
    if(x + idx > 10 || y + idx > 10) return true;
    for (int i = x; i < x + idx; i++)
    {
        for (int j = y; j < y + idx; j++){
            if (board[i][j] == 0 || visited[i][j]) return true;
        }
    }
    return false;
}

void coloring(const vector<node>::iterator it, bool color, int idx){
    int x = it->x;
    int y = it->y;
    for (int i = x; i < x + idx; i++)
    {
        for (int j = y; j < y + idx; j++){
            visited[i][j] = color;
        }
    }
    return;
}

void printarr(){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <10; j++){
            cout << (visited[i][j] ? 1 : 0) << ' ';
        }
        cout << '\n';
    }
    
}


void stitch(vector<node>::iterator it){
    if(it == one.end()){
        int cur = 0;
        for (int i = 1; i <= 5; i++)
        {   
            cur += 5 - paper[i];
        }
        ans = min(ans, cur);
        return;
    }
    else
    {
        if(visited[it->x][it->y]) {
            stitch(it+1);
        }
        else{
            for (int i = 5; i >= 1; i--)
            {
                if(paper[i] == 0 || zero(it, i)) continue;                 
                coloring(it, true, i);
                paper[i]--;        
                stitch(it +1);
                coloring(it, false, i);
                paper[i]++;
            }
        }
    }

    
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 10; i++)
    {
        for (int j =0; j < 10; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) one.push_back({i, j});
        }
    }
    stitch(one.begin());
    cout << (ans == MX ? -1 : ans);
    return 0;    
}