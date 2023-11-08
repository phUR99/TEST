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
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cout << lcm(temp1, temp2) << '\n';
    }
  
}