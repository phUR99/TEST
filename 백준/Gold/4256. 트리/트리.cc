#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int preorder[1005];
int inorder[1005];

void postorder(int in_st, int in_ed, int pre_st, int pre_ed)
{
    if (in_st > in_ed || pre_st > pre_ed)
        return;
    int root = preorder[pre_st];
    int i;
    for (i = in_st; i <= in_ed; i++)
    {
        if (inorder[i] == root)
            break;
    }
    int L = i - in_st;
    postorder(in_st, i - 1, pre_st + 1, pre_st + L);
    postorder(i + 1, in_ed, pre_st + L + 1, pre_ed);
    cout << root << ' ';
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    postorder(0, n - 1, 0, n - 1);
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}