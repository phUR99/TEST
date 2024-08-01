#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int C, N;
int cache[1105];
vector<pair<int, int>> cityList;
int main(){
    fastio;
    cin >> C >> N;
    
    cityList.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cityList[i].second >> cityList[i].first;
    }
    sort(cityList.begin(), cityList.end());
    fill(cache, cache+1105, 987654321);
    cache[0] = 0;
    for (int i = 0; i < N; i++)
    {        
        cache[cityList[i].first] = cityList[i].second;
    }
    
    for (int i = 0; i < C + cityList.back().first; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i - cityList[j].first < 0) continue;
            cache[i] = min(cache[i], cache[i - cityList[j].first] + cityList[j].second);
        }
                
    }
    int ans = 987654321;
    for (int i = C; i < C + cityList.back().first; i++)
    {
        ans = min(ans, cache[i]);
    }
    cout << ans;
    return 0;
}