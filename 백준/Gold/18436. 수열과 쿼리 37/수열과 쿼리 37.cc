#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int tree[400005];
int n, m;
void update(int left, int right, int node, int target, int diff){
    if(left > target || right < target) return;
    
    if(left == right) {
        tree[node] = diff;
        return;
    }
    int mid = (left + right) /2;
    update(left, mid, node*2, target, diff);
    update(mid+1, right, node*2+1, target, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(int left, int right, int node, int qleft, int qright){
    if(left > qright || right < qleft) return 0 ;
    if(left >= qleft && right <= qright) return tree[node];
    int mid = (left + right)/2;
    return query(left, mid, node*2, qleft, qright) + query(mid+1, right, node*2+1, qleft, qright);
}

int main(){
    fastio;    
    int tmp;
    cin >> n;
    int s = 1 ;
    while (n > s) s *= 2;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        tmp %= 2;
        update(1, s, 1, i, tmp);
    }
    cin >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if(a == 1){
            c %= 2;
            update(1, s, 1, b, c);
        }
        else if (a == 2){
            cout << c - b + 1 - query(1, s, 1, b, c) << '\n';
        }
        else{
            cout << query(1, s, 1, b, c) << '\n';
        }
    }
    

    return 0;
}