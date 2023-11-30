 #include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<int> u, l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h;
    cin >> n >> h;

  
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i % 2 == 0) l.push_back(temp);
        else {
            u.push_back(h-temp);
        }
    }
    sort(u.begin(), u.end()); sort(l.begin(), l.end());
    int m = 1e9 + 1;
    int ans = 0;
    // l보다 i가 작거나 같다면 부딪힌다.
    // u보다 i가 크거나 같다면 부딪힌다.
    for (int i = 0; i < h; i++)
    {
        int c1 = l.size() - (upper_bound(l.begin(), l.end(), 0.1 + i) - l.begin());
        int c2 = upper_bound(u.begin(), u.end(), 0.1 + i) - u.begin();

        if (c1 + c2 < m) {
            m = c1 + c2;
            ans = 1;
        }
        else if (c1 + c2 == m) 
        {
            ans++;
        }
    }
    cout << m << ' ' << ans;
    

}
