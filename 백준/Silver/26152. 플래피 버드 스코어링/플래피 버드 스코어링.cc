#include <bits/stdc++.h>
//헤맨 이유: 벡터를 페어로 설정했는데 설정함에 따라서 이분탐색을 위해서 벡터를 정렬한 후 다시 나눌 필요가 있었다. 이 부분에서 헤맴.
//min_element가 o(n)의 복잡도를 가진다는 것을 몰랐다. 
using namespace std;
#define ll long long
#define X first
#define Y second

int l[250050];
vector<pair<int, int>> vec;

int height[250050];
int idx[250050];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return  a.second > b.second;
    }
    else return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    vec.push_back({ -0x7fffffff, n });
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        l[i] -= temp;
        vec.push_back({l[i], i});
    }
    sort(vec.begin(), vec.end(), cmp);
    int cur = 1e9 + 1;
    for (int i = 0; i <= n; i++)
    {
        height[i] = vec[i].first;
        cur = min(cur, vec[i].second);
        idx[i] = cur;
    }
    cin >> w;
    while (w--)
    {
        cin >> temp;
        int score = lower_bound(height, height + n + 1, temp) - height;
        cout << idx[score-1] << '\n';
    }

}

/*
#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<int> v;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    v[i] -= tmp;
  }

  for (int i = 1; i < n; i++) {
    v[i] = min(v[i-1], v[i]);
  }
  reverse(v.begin(), v.end());

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> tmp;
    cout << n - (lower_bound(v.begin(), v.end(), tmp) - v.begin()) << '\n';
  }
}
*/
