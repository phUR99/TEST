#include <bits/stdc++.h>
// 그리디? : st와 ed를 비교하면서 st < ed일 경우 계속해서 최선의 경우를 찾을 수 있음.
// iterator 체크하기 i++를 break문 앞에 둘 경우에는 n+1 을 체크하는 것이 아닌 n+2를 체크하기 때문에 오류 가능
// ed의 길이가 원소가 작을 때 큰 경우 (1, 4) (2, 3)이 있을 수 있기 때문에 ed의 길이는 max를 사용해서 갱신해준다.
using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> line;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        line.push_back({ st, ed });
    }
    sort(line.begin(), line.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int st = line[i].first;
        int ed = line[i].second;
        while (i + 1 < n)
        {   
            if (line[i + 1].first > ed) break;
            i++;           
            ed = max(ed, line[i].second);
        }
        ans += ed - st;
    }
    cout << ans;

}
