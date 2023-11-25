#include <bits/stdc++.h>
//idea: h 배열을 만들어서 최대 높이의 함수를 만들어낸다
//그러나 이렇게 만들어진 h 배열은 최대 높이만 알 수 있을 뿐, 배열의 성분은 정확하지 않기 때문에(순서가 반영되지 않음) index를 받아 줄 배열이 필요하다
//idx의 역순으로 a를 탐색하면서 idx랑 일치하는 값을 찾아 배열에 넣은 후 reverse 를 이용하여 출력한다.
using namespace std;
#define ll long long

int a[1'000'005];
int h[1'000'005], o[1'000'005];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(h, h + n, 1e9+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[idx] < a[i]) {
            idx++;
            h[idx] = a[i];
            o[i] = idx;
        }
        else
        {
            auto l = lower_bound(h, h + n, a[i]) - h;
            h[l] = a[i];
            o[i] = l;
        }
    }
    vector<int> answer;
    int cur = idx;
    for (int i = n-1; i >= 0; i--)
    {
        if (o[i] == cur) {
            answer.push_back(a[i]);
            cur--;
        }
    }
    cout << idx + 1 << '\n';
    reverse(answer.begin(), answer.end());
    for (auto e : answer)
    {
        cout << e << ' ';
    }
}
