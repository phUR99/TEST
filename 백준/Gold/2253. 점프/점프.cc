#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int cache[10005][505];
bool notVisited[10005];

int solution(int cur, int dir){
    if(cur > N) return 987654321;
    if(cur == N) return 0;
    if(notVisited[cur]) return 987654321;

    int &ret = cache[cur][dir];
    if(ret != -1) return ret;
    ret = 987654321;
    if(dir > 1) ret = min(ret, solution(cur + dir - 1, dir - 1) + 1);
    if(dir > 0) ret = min(ret, solution(cur + dir, dir) + 1);
    ret = min(ret, solution(cur + dir + 1, dir + 1) + 1);
    return ret;
}

int main(){
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int c;
        cin >> c;
        notVisited[c] = true;
    }
    int answer  = solution(1, 0);
    if(answer == 987654321) answer = -1;
    cout << answer;
    return 0;
}