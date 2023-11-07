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


int n;
int x[1'000'005];
int d[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    //가장 긴 수열을 만들어줄 d 배열
    d[0] = x[0];
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        // 크면
        if (x[i] > d[last])
        {
            //인덱스를 증가시켜서 올려준다
            d[++last] = x[i];
        }
        // 작으면
        else
        {
            // 더 작은 인덱스로 넣어준다.
            int idx = lower_bound(d, d + last, x[i]) - d;
            d[idx] = x[i];
        }
    }
    // 항상 덮어 씌워지기 때문에 다시 작아지더라도 lower_bound를 통해서 idx가 줄어든다.
    cout << last + 1; (인덱스 + 1)이 길이
}
