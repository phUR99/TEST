#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int S = 1;
int tree[400050];
int query(int left, int right, int node, int qLeft, int qRight){
    if(left > qRight || right  < qLeft) return 1987654321;
    if(left >= qLeft && right <= qRight) return tree[node];
    int mid = (left + right)/2;
    return min(query(left, mid, node*2, qLeft, qRight), query(mid+1, right, node*2+1, qLeft, qRight));
}
void update(int left, int right, int node, int target, int value){
    if(target < left || target > right) return;
    if(left == right){
        tree[node] = value;
        return;
    }
    int mid = (left + right)/2;
    update(left, mid, node*2, target, value);
    update(mid+1, right, node*2+1, target, value);
    tree[node] = min(tree[node*2], tree[node*2+1]);

}

int main(){
    fastio; 
    cin >> N;
    fill(tree, tree+400050, 1987654321);

    while (N > S) S *=2;
        
    for (int i = 0; i < N; i++)
    {
        cin >> tree[S+i];
    }
    for (int i = S-1; i > 0; i--)
    {
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
    cin >> M;
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        if(a == 1){
            update(1, S, 1, b, c);
        }
        else{
            cout << query(1, S, 1, b, c) << '\n';
        }
    }
    


    return 0;
}