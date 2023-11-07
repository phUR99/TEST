#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>

using namespace std;
#define ll long long


int n, k;
int x[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int ed = 0;
    int ans = 0;
    int cur = 0;
    int cnt = 0;
    if (x[ed] % 2 == 1) cnt++;
    for (int st = 0; st < n; st++)
    {
        //idx 판단 잘하기. k - cnt >0이 안되는 이유는 좌항은 ed +1 일 때를 보고 있는 데 우항은 ed일 때를 관찰하고 있어서 안된다!!
        while (ed + 1 != n && k - cnt -x[ed+1]%2 >= 0) {
            ed++;         
            if (x[ed] % 2 == 1) { 
                cnt++;
            }
        }
        cur = ed - st - cnt + 1;
        ans = max(cur, ans);
        if (x[st] % 2 == 1 && cnt > 0) cnt--;
        
    }
    cout << ans;
}
