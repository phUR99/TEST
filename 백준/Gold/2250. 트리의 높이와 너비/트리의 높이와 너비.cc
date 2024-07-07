#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct node{
    int left = -1, right = -1, parent = -1;
};

node adj[10005];
vector<int> level[10005];
int N;
int maxL = 0;

void dfs(int l, int n, int &ret){        
    if (adj[n].left != -1) dfs(l+1, adj[n].left, ret);
    level[l].push_back(ret);    
    ret++;
    maxL = max(maxL, l);
    if (adj[n].right != -1) dfs(l+1, adj[n].right, ret);    
}

int main(){
    fastio;    
    cin >> N;
    int p, c;
    for (int i = 0; i < N; i++)
    {
        cin >> p;
        for (int j = 0; j < 2; j++)
        {
            cin >> c;
            if(c == -1) continue;
            if(j == 0) adj[p].left = c;
            else adj[p].right = c;
            adj[c].parent = p;
        }        
    }    
    int root;
    for (int i = 1; i <= N; i++)
    {
        if(adj[i].parent != -1) continue;
        root = i;
        break;
    }
    
    int a = 0;
    dfs(1, root, a);
    int ansL = -1;
    int ansR = -1;
    for (int i = 1; i <= maxL; i++)
    {        
        int m = level[i].front();
        int M = level[i].back();
        int R = M - m + 1;        
        if(ansR < R){
            ansL = i;
            ansR = R;
        }
    }

    cout << ansL << ' ' << ansR;
    
    


    return 0;
}