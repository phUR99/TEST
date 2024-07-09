#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, h, k;
pair<int, int> a[500005];

int answer = 0;

int main(){
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+N, greater<pair<int,int>>());
    multiset<int> s;

    for (int i = 0; i < N; i++)
    {
        multiset<int>::iterator it = s.lower_bound(-a[i].second+1);
        if(it == s.end()) s.insert(-1);
        else{
            int val = *it;
            s.erase(it);
            s.insert(val-1);
        }
    }
    answer = s.size();
    cout << s.size();

    return 0;
}