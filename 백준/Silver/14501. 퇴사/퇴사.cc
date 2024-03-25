#include <bits/stdc++.h>
using namespace std;

struct node
{
    int day, cost;
};
node arr[20];

int n;

int maxValue(int cur){ 
    int ret = 0;
    for (int i = cur; i < n; i++)
    {
        if(i + arr[i].day > n) continue;
        ret = max(ret, maxValue(arr[i].day + i) + arr[i].cost);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].day >> arr[i].cost;
    }
    cout << maxValue(0);

    return 0;
}