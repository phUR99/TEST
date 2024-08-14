#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector<pair<int, int>> coord;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
long long cache[100005][5];
int N;

long long dist(int x, int y, int X, int Y){
    return abs(x -X) + abs(y - Y);
}




int main(){
    fastio;
    cin >> N;
    int x, y;
    for (int i = 0; i <= N; i++)
    {
        fill(cache[i], cache[i]+5, 0x3fffffffffffffff);
    }
    

    for (int i = 0; i <= N; i++)
    {
        cin >> x >> y;
        coord.push_back({x, y});
    }
    cache[0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                int px = coord[i-1].first + dx[k];
                int py = coord[i-1].second + dy[k];
                int cx = coord[i].first + dx[j];
                int cy = coord[i].second + dy[j];
                long long diff = dist(px, py, cx, cy);
                cache[i][j] = min(cache[i][j], cache[i-1][k] + diff);
            }            
        }        
    }
    long long answer = *min_element(cache[N], cache[N]+5);
    cout << answer;

    return 0;
}