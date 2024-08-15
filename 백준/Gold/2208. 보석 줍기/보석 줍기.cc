#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int pSum[100500];
int n, m;


int main(){
    fastio;
    cin >> n >> m;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        pSum[i] = pSum[i-1] + tmp;
    }
    int answer = 0;
    int preMin = 0;
    for (int i = m; i <= n; i++)
    {
        preMin = min(preMin, pSum[i-m]);
        answer= max(answer, pSum[i] - preMin);
    }
    cout << answer;
 

    return 0;
}