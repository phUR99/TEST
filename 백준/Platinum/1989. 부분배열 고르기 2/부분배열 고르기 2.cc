#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[100005];
int n;
int low, high;
ll ret = -1;
void solve(int l, int r){
    if(l > r) return;

    int mid = (l + r) / 2;
    int left = mid, right = mid;
    ll sum = arr[mid];
    ll mn = arr[mid];

    if (ret < sum * mn) {
        ret = sum * mn;
        low = left;
        high = right;
    }

    while (l < left || right < r) {
        if (right < r && (left == l || arr[left - 1] < arr[right + 1])) {
            right++;
            sum += arr[right];
            mn = min(mn, 1LL * arr[right]);
        } else {
            left--;
            sum += arr[left];
            mn = min(mn, 1LL * arr[left]);
        }

        if (ret < sum * mn) {
            ret = sum * mn;
            low = left;
            high = right;
        }
    }

    solve(l, mid - 1);
    solve(mid + 1, r);
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(0, n-1);
    cout << ret << '\n';
    cout << low+1 << ' ' << high+1 << '\n';
    return 0;
}