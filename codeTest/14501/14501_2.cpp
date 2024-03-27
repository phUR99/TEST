//백트래킹 방식이 아닌 top_down 방식의 dp 풀이법
#include <bits/stdc++.h>
using namespace std;

int cache[20];
int T[20], P[20];
int n;

int solve(int day){
    if (day > n) return -987654321;
    if (day == n) return 0;
    int &ret = cache[day];
    if (ret != -1) return ret;

    ret = max(solve(day +1), solve(day + T[day])+P[day]);
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> T[i] >> P[i];
        cache[i] = -1;
    }
    cout << solve(0);    

    return 0;
}