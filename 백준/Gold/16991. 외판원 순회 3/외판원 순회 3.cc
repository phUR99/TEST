#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int full_bit;
vector<array<int, 2>> arr;
double dist(const array<int, 2> &a, const array<int, 2> &b){
    int r = (a[0] - b[0]);
    int c = (a[1] - b[1]);
    r = r * r;
    c = c * c;
    return sqrt(r + c);
}
vector<vector<double>> dists;

double cache[16][1 << 16];

double solve(int cur, int state){
    if (state == full_bit) return dists[cur][0];
    double &ret = cache[cur][state];
    if (ret != -1.0) return ret;
    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i)) continue;
        int nxtState = state | (1 << i);
        ret = min(ret, dists[cur][i] + solve(i, nxtState));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    arr.resize(n);
    dists.resize(n, vector<double>(n));
    full_bit = (1 << n) -1;
    for (auto &i : arr)
    {
        cin >> i[0] >> i[1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dists[i][j] = dist(arr[i], arr[j]);
        }
        
    }
    
    fill(&cache[0][0], &cache[15][(1<<16)-1], -1.0);    
    double ret = 987654321;
    cout.precision(6);
    cout << fixed << solve(0, 1);

    return 0;
}