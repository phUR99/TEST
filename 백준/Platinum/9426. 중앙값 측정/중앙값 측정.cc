#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int tree[65536 * 4];
int N, K;

void update(int left, int right, int node, int value, int target){
    if(left > target || right < target) return;
    tree[node] += value;
    if(left == right) return;
    int mid = (left + right) /2;
    update(left, mid, node*2, value, target);
    update(mid+1, right, node*2+1, value, target);
}
long long ans = 0;
void query(int left, int right, int node, int target){
    if(left == right) {
        ans += left;
        return;
    }
    int mid = (left + right) /2;
    if(tree[node*2] >= target){
        query(left, mid, node*2, target);
    }
    else{
        query(mid +1, right, node*2+1, target-tree[node*2]);
    }
}
int arr[250500];

int main(){
    fastio;
    cin >> N >> K;
    
    int S = 1;
    while(65535 > S) S *= 2;

    
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        update(0, S-1, 1, 1, arr[i]);
        if(i - K >= 0){            
            query(0, S-1, 1, (K+1)/2);            
            update(0, S-1, 1, -1, arr[i-K+1]);
        }
    }
    cout << ans;

    return 0;
}