#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int arr[105];
int cache[105][105];

int solution(int cur, int cnt){ 
    
    if(cnt == 0) return 0;
    if(cur <= 0)  return -987654321;

    int &ret = cache[cur][cnt];
    if(ret != -1) return ret;
    int pSum = 0;
    ret = solution(cur - 1, cnt);
    for (int i = cur; i > 0 ; i--)
    {
        pSum += arr[i];
        ret = max(ret, pSum + solution(i-2, cnt - 1));
    }
    return ret;
}

int main(){
    fastio;
    cin >> N >> M;
    memset(cache, -1, sizeof(cache));
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    int answer  = solution(N, M);
    cout << answer;

    return 0;
}