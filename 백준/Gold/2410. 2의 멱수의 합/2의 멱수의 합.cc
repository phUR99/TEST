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
ll d[1'000'005];
int di = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    d[1] = 1;
    for (int i = 2; i < 1'000'003; i++)
    {
        // n이 홀수일 경우 -> n-1의 개수랑 동일(n-1 + 1)의 형태일 거니까
        if (i%2 == 1)
        {
            d[i] = d[i - 1] %di;
        }
        // n이 짝수일 경우 -> 1이 포항될 경우 n-1의 개수랑 동일, 1이 없을 경우 2의 거듭제곱으로 표현 가능
        // 따라서, 이를 2로 나눈 n/2의 경우의 가짓수와 동일하다
        else
        {
            d[i] = (d[i - 1]  + d[i / 2]) %di;
        }
        
    }
    cout << d[n];

}