#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int tree[400050];
int answer[100005];


int query(int left, int right, int node, int value){
    if(left == right) return left;
    int mid = (left + right)/2;

    if(tree[node*2] >= value) return query(left, mid, node*2, value);
    else return query(mid+1, right, node*2+1, value - tree[node*2]);
}
void update(int left, int right, int node, int target){
    if(left > target || right < target) return;
    if(left == right) {
        tree[node] = 0;
        return;
    }
    int mid = (left + right)/2;
    update(left, mid, node*2, target);
    update(mid+1, right, node*2+1, target);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int N;

int main(){
    fastio;
    int s = 1;
    cin >> N;
    while(N > s) s*=2;
    for (int i = 0; i < N; i++)
    {
        tree[i+s] = 1;
    }
    for (int i = s-1; i > 0; i--)
    {
        tree[i] = tree[i*2] + tree[i*2+1];
    }
        
    int ret;
    int q;

    for (int i = 1; i <= N; i++)
    {
        cin >> q;
        ret = query(1, s, 1, q+1);
        answer[ret] = i;
        update(1, s, 1, ret);
    }
    for (int i = 1; i <= N; i++)
    {
        cout << answer[i] <<'\n';
    }    
    return 0;
}