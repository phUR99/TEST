#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int inorder[100050];
int idx[100050];
int postorder[100005];
int N;

/*
왼쪽의 사이즈만큼 postorder도 분할 -> 이게 잘 생각이 안났음
*/

void solve(int in_st, int in_ed, int po_st, int po_ed)
{
    if (in_st > in_ed || po_st > po_ed)
        return;
    int rootIdx = idx[postorder[po_ed]];
    int left = rootIdx - in_st;
    cout << postorder[po_ed] << ' ';
    solve(in_st, rootIdx - 1, po_st, po_st + left - 1);
    solve(rootIdx + 1, in_ed, po_st + left, po_ed - 1);
}

int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> postorder[i];
    }
    solve(0, N - 1, 0, N - 1);
    return 0;
}