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
int n, m;
int arr1[1'000'005], arr2[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    int pt1 = 0, pt2 = 0;
    for (int i = 0; i < n+m; i++)
    {
        if (pt1 == n)
        {
            while (pt2 != m) {
                cout << arr2[pt2] << ' ';
                pt2++;
            }
            break;
        }
        if (pt2 == m)
        {
            while (pt1 != n) {
                cout << arr1[pt1] << ' ';
                pt1++;
            }
            break;
        }
        if (arr1[pt1] > arr2[pt2]) {
            cout << arr2[pt2] << ' ';
            pt2++;
        }
        else {
            cout << arr1[pt1] << ' ';
            pt1++;
        }
        
    }
}