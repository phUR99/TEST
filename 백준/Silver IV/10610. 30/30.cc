#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin >> str;
    sort(str.begin(), str.end(), greater<>());
    long long int sum = 0;
    for (auto i : str) {
        sum += i - '0';
    }

    if (str[str.length() - 1] == '0' && sum % 3 == 0) cout << str;
        
    else cout << -1;
}