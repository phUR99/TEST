#include<iostream>
#include<algorithm>
using namespace std;
  
const int SIZE = 1 << 22;
const int len = 1 << 21;
long long tree[SIZE];
long long n, p, d;
int arr[2000010];
long long prefix[2000010];
long long discount[2000010];
  
void update(int idx, long long value)
{
    idx += len;
    tree[idx] = value;
    idx /= 2;
    while (idx >= 1)
    {
        tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        idx /= 2;
    }
}
  
long long get(int idx, int s, int e, int ts, int te)
{
    int mid;
  
    if (s > te || e < ts) return 0;
    else if (ts <= s && e <= te) return tree[idx];
  
    mid = (s + e) / 2;
  
    return max(get(2 * idx, s, mid, ts, te), get(2 * idx + 1, mid + 1, e, ts, te));
}
  
int main()
{
    int t, T;
    int i;
    int s, e;
    int mid;
    int ans;
  
    cin.tie(NULL);
    ios::sync_with_stdio(false);
  
    cin >> T;
    for (t = 1; t <= T; t++)
    {
        cin >> n >> p >> d;
        for (i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
          
        for (i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        discount[1] = 0;
        for (i = 1; i <= d; i++)
        {
            discount[1] += arr[i];
        }
        for (i = d + 1; i <= n; i++)
        {
            discount[i - d + 1] = discount[i - d] + arr[i] - arr[i - d];
        }
  
        for (i = 1; i <= n; i++)
        {
            update(i, discount[i]);
        }
  
        ans = d;
        s = 1;
        e = d;
        while (e <= n)
        {
            if (prefix[e] - prefix[s - 1] - get(1, 0, len - 1, s, e - d + 1) <= p)
            {
                ans = max(ans, e - s + 1);
                e++;
            }
            else s++;
        }
  
        cout << '#' << t << ' ' << ans << '\n';
  
        for (i = 1; i <= n; i++)
        {
            update(i, 0);
        }
    }
}