#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int C, N, Q, h;

int maxtree[400005], mintree[400005];
int maxQuery(int left, int right, int node, int nodeleft, int noderight){
    if(noderight < left || nodeleft > right) return 0;
    else if (nodeleft <= left && noderight >= right) return maxtree[node];
    else{
        int mid = (left + right) / 2;
        return max(maxQuery(left, mid, node*2, nodeleft, noderight), maxQuery(mid +1, right, node*2+1, nodeleft, noderight));
    }
}
int minQuery(int left, int right, int node, int nodeleft, int noderight){
    if(noderight < left || nodeleft > right) return 987654321;
    else if(nodeleft <= left && noderight >= right) return mintree[node];
    else{
        int mid = (left + right) /2;
        return min(minQuery(left, mid, node*2, nodeleft, noderight), minQuery(mid+1, right, node*2+1, nodeleft, noderight));
    }
}


int main(){
    fastio;

    cin >> C;
    for (int c = 0; c < C; c++)
    {
        cin >> N >> Q;
        fill(maxtree, maxtree+4*N+1, 0);
        fill(mintree, mintree+4*N+1, 987654321);

        int S = 1;
        int left, right;

        while (S < N) S *= 2;

        for (int n = 0; n < N; n++)
        {
            cin >> h;
            mintree[n+S] = h;
            maxtree[n+S] = h;
        }
        for (int i = S-1; i > 0 ; i--)
        {
            maxtree[i] = max(maxtree[i*2], maxtree[i*2+1]);
            mintree[i] = min(mintree[i*2], mintree[i*2+1]);
        }                                 
        while(Q--)
        {            
            cin >> left >> right;            
            left++; right++;
            cout << maxQuery(1, S, 1, left, right) -  minQuery(1, S, 1, left, right)<< '\n';            
        }        
    }    
    return 0;
}