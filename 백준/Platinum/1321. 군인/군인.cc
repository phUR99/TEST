#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;

int tree[2000050];

void update(int left, int right, int node, int target, int diff){
    if(target < left || target > right) return;
    tree[node] += diff;
    if(left == right) return;
    int mid = (left + right)/2;
    update(left, mid, node*2, target, diff);
    update(mid+1, right, node*2+1, target, diff);
}
int query(int left, int right, int node, int value){
    if(left == right) return left;
    int mid = (left + right)/2;

    if(tree[node*2]>= value) return query(left, mid, node*2, value);
    else return query(mid+1, right, node*2+1, value - tree[node*2]);
}

int main(){
    fastio;
    cin >> N;
    int S = 1;
    while (N > S) S *=2;    
    
    for (int i = 0; i < N; i++)
    {
        cin >> tree[S+i];
    }
    for (int i = S-1; i > 0; i--)
    {
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    
    cin >> M;
    int c, a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> c;
        if(c == 1){
            cin >> a >> b;
            update(1, S, 1, a, b);
        }
        else{
            cin >> a;
            cout << query(1, S, 1, a) << '\n';
        }
    }
    

    return 0;
}