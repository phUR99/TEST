#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
struct node{
    int l, r, d;
};
node rule[10005];
int N, K, D;
bool match(int x){
    long long sum = 0;
    for (int i = 0; i < K; i++)
    {
        if(x < rule[i].l) continue;
        int v = min(x, rule[i].r);
        sum += (v-rule[i].l)/rule[i].d + 1;
    }
    return sum >= D;
}


int main(){
    fastio;
    cin >> N >> K >> D;
    for (int i = 0; i < K; i++)
    {
        cin >> rule[i].l >> rule[i].r >> rule[i].d;
    }
    int st = 1;
    int ed = 1'000'000;

    while (st <= ed)
    {
        int mid = (st + ed)/2;
        if(match(mid)){
            ed = mid -1;
        }
        else{
            st = mid + 1;
        }   
    }
    cout << st;

    return 0;
}