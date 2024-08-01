#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N;
int M;

int main(){
    fastio;
    vector<int> cranes, boxes, cranesSize;        
    cin >> N;
    cranes.resize(N);
    cranesSize.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> cranes[i];
    }
    cin >> M;
    boxes.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> boxes[i];
    }
    sort(cranes.begin(), cranes.end());
    sort(boxes.begin(), boxes.end(), greater<>());
    for (int i = 0; i < M; i++)
    {
        if(boxes[i] > cranes.back()){
            cout << -1;
            return 0;
        }
        
        int idx = lower_bound(cranes.begin(), cranes.end(), boxes[i]) - cranes.begin();
        //cout << cranes[idx] << ' ';
        idx = min_element(cranesSize.begin() + idx, cranesSize.end()) - cranesSize.begin();
        cranesSize[idx]++;        
    }
    cout << *max_element(cranesSize.begin(), cranesSize.end());

    return 0;
}