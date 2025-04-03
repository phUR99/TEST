#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool visited[205][205][205];
int a, b, c;

int main()
{
    fastio;
    cin >> a >> b >> c;
    queue<array<int ,3>> q;
    q.push({c, 0, 0});
    visited[c][0][0] = 1;
    while (!q.empty())
    {   
        auto cur = q.front(); q.pop();
        int hc = cur[0];
        int ha = cur[1];
        int hb = cur[2];
        //cout << hc << ' ' << ha << ' ' << hb << '\n';
        int na=0, nb=0, nc=0;
        
        //a
        nc = ha +hc;
        nb = hb;
        if(nc > c){
            na = nc - c;
            nc = c;
        }
        else na = 0;
            
        if(!visited[nc][na][nb]){
            q.push({nc, na, nb});
            visited[nc][na][nb] = 1;
        }
        na=0, nb=0, nc=0;
        nb = ha +hb;
        nc = hc;
        if(nb > b){
            na = nb - b;
            nb = b;
        }
        else na =0;

        if(!visited[nc][na][nb]){
            q.push({nc, na, nb});
            visited[nc][na][nb] = 1;
        }
        na=0, nb=0, nc=0;
        //b
        nc = hc+ hb;
        na = ha;
        if(nc > c){
            nb = nc - c;
            nc = c;
        }
        else nb = 0;

        if(!visited[nc][na][nb]){
            q.push({nc, na, nb});
            visited[nc][na][nb] = 1;
        }
        na=0, nb=0, nc=0;
        na = ha + hb;
        nc = hc;
        if(na > a){
            nb = na -a;
            na = a;
        }
        else nb = 0;

        if(!visited[nc][na][nb]){
            q.push({nc, na, nb});
            visited[nc][na][nb] = 1;
        }
        //c
        na=0, nb=0, nc=0;
        na = hc + ha;
        nb = hb;
        if(na > a){
            nc = na - a;
            na = a;
        }
        else nc = 0;

        if(!visited[nc][na][nb]){
            q.push({nc, na, nb});
            visited[nc][na][nb] = 1;
        }
        na=0, nb=0, nc=0;
        nb = hc + hb;
        na = ha;
        if(nb > b){
            nc = nb - b;
            nb = b;
        }
        else nc = 0;

        if(!visited[nc][na][nb]){
            q.push({nc, na, nb});
            visited[nc][na][nb] = 1;
        }
    }
    set<int> ret;
    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if(visited[i][0][j]) ret.insert(i);
        }
        
    }
    for (auto it : ret)
    {
        cout << it << ' ';
    }
    
    
    
    return 0;
}