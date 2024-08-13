#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
ll tree[4000005];
void update(int left, int right, int node, int target, int diff){
    if(target < left || target > right) return;
    tree[node] += diff;
    if(left == right) return;
    int mid = (left + right) /2;
    update(left, mid, node*2, target, diff);
    update(mid+1, right, node*2+1, target, diff);    
}
ll query(int left, int right, int node, int qleft, int qright){
    if (left > qright  || right < qleft) return 0;
    else if(left >= qleft && right <= qright) return tree[node];
    int mid = (left + right) /2;

    return query(left, mid, node*2, qleft, qright) + query(mid+1, right, node*2+1, qleft, qright);
}
int N, Q;

int main(){
    fastio;
    cin >> N >> Q;
    int s = 1;
    while (N > s) s *= 2;    
    int c, p, q;

    for (int i = 0; i < Q; i++)
    {
        cin >> c >> p >> q;
        if(c == 1){
            update(1, s, 1, p, q);
        }
        else{
            cout << query(1, s, 1, p, q) << '\n';
        }
    }
    

    return 0;
}