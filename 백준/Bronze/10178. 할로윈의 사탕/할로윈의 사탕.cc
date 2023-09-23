#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int c, v;
		scanf("%d %d", &c, &v);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v, c % v);
	}

}
