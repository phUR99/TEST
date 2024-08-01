#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SIZE 400005
long long sumTree[SIZE];
int idxTree[SIZE];
long long arr[100005];
int S = 1;
int minIdx(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    return (arr[a] > arr[b] ? b : a);    
}

long long sumQuery(int left, int right, int node, int qLeft, int qRight){
    if(left > qRight || right < qLeft) return 0;
    if(left >= qLeft && right <= qRight) return sumTree[node];
    int mid = (left + right) / 2;
    return (sumQuery(left, mid, node*2, qLeft, qRight) + sumQuery(mid+1, right, node*2+1, qLeft, qRight));
}
int minQuery(int left, int right, int node, int qLeft, int qRight){
    if(left > qRight || right < qLeft) return -1;
    if(left >= qLeft && right <= qRight) return idxTree[node];
    int mid = (left + right) / 2;
    int a = minQuery(left, mid, node*2, qLeft, qRight);
    int b = minQuery(mid+1, right, node*2+1, qLeft, qRight);
    return minIdx(a, b);
     
}
long long query(int left, int right){
    if(left  == right) return arr[left] * arr[left];
    int idx = minQuery(0, S-1, 1, left, right);
    long long ret = arr[idx] * sumQuery(0, S-1, 1, left, right);
    if(left < idx)  ret = max(ret, query(left, idx-1));
    if(right > idx) ret= max(ret, query(idx+1, right));
    return ret;

}
int main(){
    fastio;
    fill(sumTree, sumTree+SIZE, 0);
    fill(idxTree, idxTree+SIZE, -1);
    int N;
    cin >> N;
    
    while (N > S) S *= 2;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sumTree[S+i] = arr[i];
        idxTree[S+i] = i;
    }
    for (int i = S-1; i > 0; i--)
    {
        idxTree[i] = minIdx(idxTree[i*2], idxTree[i*2+1]);
        sumTree[i] = sumTree[i*2] + sumTree[i*2+1];
    }
    cout << query(0, N-1);
      
    return 0;
}