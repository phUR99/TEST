#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    priority_queue<int> pq;
    //기존의 데드라인별로 정리한 배열을 사용했을 때의 문제점
    //데드라인이 더 늦지만 유리한 경우를 반영하지 못함
    //헤결책: 데드라인 별로 값을 넣어준 후에 데드라인의 역순으로 값을 넣어주면서 우선순위 큐의 top을 계속해서 더해줌
    //이렇게 하면 데드라인이 더 늦지만 유리한 경우를 반영할 수 있음.
    vector<vector< int >> vd(200'002);
    for (int i = 0; i < n; i++)
    {
        int dl, cn;
        cin >> dl >> cn;
        vd[dl].push_back(cn);
    }
    int ans = 0;
    for (int cur = 200'001 ; cur != 0; cur--)
    {
        for (int nd : vd[cur]) {
            pq.push(nd);
        }
        if (pq.empty()) continue;
        ans += pq.top(); pq.pop();
    }
    cout << ans;
}