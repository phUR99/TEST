#include <iostream>
using namespace std;
int main()
{
    int a, b, t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int ret = 1;
        while (b--)
        {
            ret *= a;
            ret %= 10;
        }
        cout << (ret == 0 ? 10 : ret) << '\n';
    }

    return 0;
}