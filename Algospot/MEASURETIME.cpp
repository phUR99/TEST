#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct FenwickTree
{
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}

    int sum(int pos){        
        int ret = 0;

        while (pos > 0)
        {
            ret += tree[pos];
            pos &= (pos - 1);
        }        
        return ret;
    }
    void add(int pos, int val){      
  
        while (pos < tree.size())
        {
            tree[pos] +=val;
            pos += pos & (-pos);
        }        
    }
};
int C, N, a;

int main(){
    fastio;
    cin >> C;
    for (int c = 0; c < C; c++)
    {
        cin >> N;
        FenwickTree F(1000000);
        long long answer = 0;
        int M = 0;
        for (int n = 0; n < N; n++)
        {
            cin >> a;
            answer += F.sum(999999) - F.sum(a);                    
            F.add(a, 1);
        }
        cout << answer  << '\n';
    }
    


    return 0;
}