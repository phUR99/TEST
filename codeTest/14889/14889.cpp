#include <bits/stdc++.h>
using namespace std;

int score[25][25];
bool isUsed[30];
int n;
int ans = 987654321;


int diff(vector<int> &arr1, vector<int> &arr2){
    int ret1 = 0, ret2 = 0;
    for (int i = 0; i < n/2; i++)
    {
        for (int j = i +1 ; j < n/2; j++)
        {
            ret1 += score[arr1[i]][arr1[j]] + score[arr1[j]][arr1[i]];
            ret2 += score[arr2[i]][arr2[j]] + score[arr2[j]][arr2[i]];
        }
        
    }        
    return abs(ret1 - ret2);
}

void makeCase(int cnt, int cur){
    if(cnt == n /2){
        vector<int> arr1, arr2;
        for (int i = 1; i <= n * n; i++)
        {
            if(isUsed[i]) arr1.push_back(i);
            else arr2.push_back(i);            
        }
        ans = min(ans, diff(arr1, arr2));            
        return;
    }   
    for (int i = cur + 1; i <= n; i++){
        if(isUsed[i]) continue;
        isUsed[i] = true;
        makeCase(cnt + 1, i);
        isUsed[i] = false;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++){
            cin >> score[i][j];
        }
    }
    makeCase(0, 0);
    cout << ans;

    return 0;
}