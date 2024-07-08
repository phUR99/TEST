#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct FenwickTree{
    vector<long long> tree;
    FenwickTree(int n) : tree(n+1) {}
    long long sum(int pos){
        long long ret = 0;
        while (pos > 0)
        {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void add(int pos, long long val){        
        while (pos < tree.size())
        {            
            tree[pos] += val;
            pos += pos & (-pos);
        }        
    }
    void modify(int pos, long long val){
        val -= sum(pos) - sum(pos-1);
        add(pos, val);        
    }
};
int N, M;

int main(){
    fastio;
    cin >> N >> M;
    FenwickTree F(N+1);
    long long c, a, b;
    long long answer = 0;
    for (int m = 0; m < M; m++)
    {
        cin >> c >> a >> b;
        if(c){
            F.modify(a, b);
        }
        else{
            answer = F.sum(max(a, b)) - F.sum(min(a, b)-1);
            cout << answer << '\n';
        }
    }
    


    return 0;

}