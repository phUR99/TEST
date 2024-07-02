#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> tree[55];
int N;
int del;
int findleaf(int node){
    if(node == del) return 0;
    if(tree[node].empty() || (tree[node][0] == del && tree[node].size() == 1)) return 1;
    int ret = 0;
    for (auto child : tree[node])
    {
        ret += findleaf(child);
    }
    return ret;
}

int main(){
    fastio;
    cin >> N;
    int root = 0;
    for (int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;
        if(parent == -1) {
            root = i;
            continue;
        }
        tree[parent].push_back(i);
    }
    cin >> del;    
    int ans = findleaf(root);
    cout << ans;
    return 0;
}