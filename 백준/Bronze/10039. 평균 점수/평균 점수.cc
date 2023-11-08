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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        temp = max(40, temp);
        ans += temp;
    }
    cout << ans / 5;
   
  
}