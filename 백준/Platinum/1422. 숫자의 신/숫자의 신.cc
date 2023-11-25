#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll arr[55];
// 내림차순으로 정리하고 싶을 경우 부등호는 > 를 사용한다. 등호는 일반적으로 사용하지 말자.
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + n, greater<>());
    vector<string> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(to_string(arr[i]));
        k--;
    }
    // 가장 큰 값을 최대한 많이 넣는 것이 최적의 해를 보장하는 것을 알 수 있다.
    while (k--)
    {
        vec.push_back(to_string(arr[0]));
    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto e : vec)
    {
        cout << e;
    }


}
