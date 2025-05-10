    #include <bits/stdc++.h>
    using namespace std;
    vector<array<int, 2>> arr;
    int n, k;
    int cache[505][505];

    int solve(int idx, int remain){
        if(idx == n-1) return 0;
        int &ret = cache[idx][remain];
        if(ret != -1) return ret;
        auto dist = [](array<int, 2> &a, array<int, 2> &b)
        {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);      
        };
        ret = solve(idx + 1, remain) + dist(arr[idx], arr[idx+1]);
        for (int i = 2; i <= remain + 1 && idx + i < n; i++)
        {
            ret = min(ret, solve(idx + i, remain - i + 1) + dist(arr[idx], arr[idx + i]));
        }
        return ret;
    }

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            array<int, 2> tmp;
            cin >> tmp[0] >> tmp[1];
            arr.push_back(tmp);
        }
        memset(cache, -1, sizeof(cache));
        int ret = solve(0, k);
        cout << ret;
        return 0;
    }