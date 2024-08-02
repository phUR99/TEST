#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int tree[400005];

int query(int left, int right, int node, int qLeft, int qRight){
    if(left > qRight || right < qLeft) return 1;
    if(left >= qLeft && right <= qRight) return tree[node];
    int mid =(left + right)/2;
    return query(left, mid, node*2, qLeft, qRight) * query(mid+1, right, node*2+1, qLeft, qRight);
}
void update(int left, int right, int node, int target, int value){
    if(target > right || target < left) return;
    if(left == right){
        tree[node] = value;
        return;
    }
    int mid = (left + right)/2;
    update(left, mid, node*2, target, value);
    update(mid+1, right, node*2+1, target, value);
    tree[node] = tree[node*2] * tree[node*2+1];
}
int change(int a){
    if(a > 0) return 1;
    else if(a == 0) return a;
    else return - 1;
}
char answer(int q){
    if(q > 0) return '+';
    else if(q == 0) return '0';
    else return '-';
}

int N, K, S;
char c;
int s, e;

int main(){
    fastio;
    while (cin >> N)
    {
        cin >> K;
        S = 1;
        while (N > S) S *=2;
        memset(tree, 0, sizeof(tree));
        
        for (int i = 0; i < N; i++)
        {
            cin >> tree[S+i];
            tree[S+i] = change(tree[S+i]);
            
        }
        for (int i = S-1; i > 0; i--)
        {
            tree[i] = tree[i*2] * tree[i*2+1];
        }
        for (int i = 0; i < K; i++)
        {
            cin >> c >> s >> e;
            if(c == 'P') cout << answer(query(1, S, 1, s, e));
            else update(1, S, 1, s, change(e));
        }                
        cout << '\n';
        
    }    
    return 0;
}