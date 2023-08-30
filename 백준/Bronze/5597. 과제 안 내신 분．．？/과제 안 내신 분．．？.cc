#include <iostream>
#include <queue>
using namespace std;
bool check[31];


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    check[0] = true;

    for (int i = 1; i <= 28; i++)
    {
        int n;
        cin >> n;
        check[n] = true;
    }

    for (int i = 1; i <= 30; i++)
    {
        if (!check[i])
        {
            cout << i << '\n';
        }
    }

}