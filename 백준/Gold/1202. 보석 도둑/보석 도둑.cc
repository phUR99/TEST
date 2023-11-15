#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    //원소의 삽입/삭제가 빈번히 일어난다 -> 이진검색트리 활용하기
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    pair<int, int> j[300'005];
    multiset<int> bag;
    for (int i = 0; i < n; i++)
    {
        cin >> j[i].second >> j[i].first;
    }
    // 가치가 큰 순서대로 정렬하기 
    sort(j, j + n);
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        bag.insert(temp);
    }
    ll ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
        int m, v;
        tie(v, m) = j[i];
        // 일정 무게 m보다 작은 iter를 반환 (가장 가치가 크면서, 가장 무게가 작은 보석)
        auto it = bag.lower_bound(m);
        if (it == bag.end()) continue;
        ans += v;
        bag.erase(it);
    }
    cout << ans;
}