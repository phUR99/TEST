using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int R,C,K,W; // R 세로 C 가로

// x, y, t로 이루어져 있다.

// t가 0인 경우 (x, y)와 (x-1, y) 사이에 벽이 있는 것이고, 세로 - 왼쪽 기준
// 1인 경우에는 (x, y)와 (x, y+1) 사이에 벽이 있는 것이다. 가로 - 아래쪽 기준

int arr[25][25];
int tmp[25][25];
bool sero[25][25];
bool garo[25][25];
bool isvisited[25][25];

bool isInside(int y, int x){
    return !(y > R || y < 1 || x > C || x < 1);
}

class air{
public :
    int y; int x; int d;
    air(int y, int x, int d) : y(y), x(x), d(d) {};
};

vector<air> airs;
vector<pair<int, int>> check;


//1: 방향이 오른쪽인 온풍기가 있음
//2: 방향이 왼쪽인 온풍기가 있음
//3: 방향이 위인 온풍기가 있음
//4: 방향이 아래인 온풍기가 있음

void right(int y, int x, int s){
    if(!isInside(y, x) || isvisited[y][x]) return ;
    isvisited[y][x]=true;
    // 벽 있는지 확인해야함
    arr[y][x] += s;

    if(s==1) return;

    // 대각선 위 (y-1, x+1)
    if(isInside(y-1, x+1)){
        if(!garo[y-1][x] && !sero[y-1][x+1]) right(y-1, x+1, s-1);
    }

    // 오른쪽 (y, x+1) 오른쪽 벽만 확인 (horizon : 왼 기준)
    if(isInside(y, x+1)){
        if(!sero[y][x+1]) right(y, x+1, s-1);
    }

    // 대각선 아래 (y+1, x+1)
    if(isInside(y+1, x+1)){
        if(!garo[y][x] && !sero[y+1][x+1]) right(y+1, x+1, s-1);
    }
}

void left(int y, int x, int s){
    if(!isInside(y, x) || isvisited[y][x]) return ;
    isvisited[y][x]=true;
    // 벽 있는지 확인해야함
    arr[y][x] += s;

    if(s==1) return;

    // 대각선 위 (y-1, x-1)
    if(isInside(y-1, x+1)){
        if(!garo[y-1][x] && !sero[y-1][x]) left(y-1, x-1, s-1);
    }

    // 왼쪽 (y, x-11) 오른쪽 벽만 확인 (horizon : 왼 기준)
    if(!sero[y][x]) left(y, x-1, s-1);


    // 대각선 아래 (y+1, x-1)
    if(isInside(y+1, x+1)){
        if(!garo[y][x] && !sero[y+1][x]) left(y+1, x-1, s-1);
    }


}

void down(int y, int x, int s){
    if(!isInside(y, x) || isvisited[y][x]) return ;
    isvisited[y][x]=true;
    // 벽 있는지 확인해야함
    arr[y][x] += s;

    if(s==1) return;

    // 대각선 왼쪽 (y+1, x-1)
    if(isInside(y+1, x-1)){
        if(!garo[y][x-1] && !sero[y][x]) down(y+1, x-1, s-1);
    }

    // 아래 (y+1, x) 오른쪽 벽만 확인 (horizon : 왼 기준)
    if(isInside(y+1, x)){
        if(!garo[y][x]) down(y+1, x, s-1);
    }

    // 대각선 오른쪽 (y+1, x+1)
    if(isInside(y+1, x+1)){
        if(!garo[y][x+1] && !sero[y][x+1]) down(y+1, x+1, s-1);
    }
}

void up(int y, int x, int s){
    if(!isInside(y, x) || isvisited[y][x]) return ;
    isvisited[y][x]=true;
    // 벽 있는지 확인해야함
    arr[y][x] += s;

    if(s==1) return;



    // 대각선 왼쪽 (y-1, x-1)
    if(isInside(y-1, x-1)){
        if(!garo[y-1][x-1] && !sero[y][x]) up(y-1, x-1, s-1);
    }


    // 위 (y-1, x)
    if(isInside(y-1, x)){
        if(!garo[y-1][x]) up(y-1, x, s-1);
    }

    // 대각선 오른쪽 (y-1, x+1)
    if(isInside(y-1, x+1)){
        if(!garo[y-1][x+1] && !sero[y][x+1]) up(y-1, x+1, s-1);
    }


}



void solve1(int y, int x, int d){
    memset(isvisited, false, sizeof(isvisited));

    if(d==1) right(y, x, 5);
    else if(d==2) left(y, x, 5);
    else if(d==3) up(y, x, 5);
    else if(d==4) down(y, x, 5);
    else cout<<"[go] RT error\n";

}

void solve2(){

    for(int y=1; y<=R; y++){
        for(int x=1; x<=C; x++){

            int target = arr[y][x]/4;

            // 1. 위
            int ny = y-1; int nx=x;
            if(isInside(ny, nx) && !garo[ny][nx]){
                if(arr[y][x]>arr[ny][nx]){
                    int dif = arr[y][x]-arr[ny][nx];
                    dif/=4;
                    tmp[y][x] -= dif;
                    tmp[ny][nx] += dif;
                }
            }
            // 2. 아래
            ny = y+1;
            nx = x;
            if(isInside(ny, nx) && !garo[y][x]){
                if(arr[y][x]>arr[ny][nx]){
                    int dif = arr[y][x]-arr[ny][nx];
                    dif/=4;
                    tmp[y][x] -= dif;
                    tmp[ny][nx] += dif;
                }
            }

            // 3. 왼
            ny = y;
            nx = x-1;
            if(isInside(ny, nx) && !sero[y][x]){
                if(arr[y][x]>arr[ny][nx]){
                    int dif = arr[y][x]-arr[ny][nx];
                    dif/=4;
                    tmp[y][x] -= dif;
                    tmp[ny][nx] += dif;
                }
            }

            // 4. 오
            ny = y;
            nx = x+1;
            if(isInside(ny, nx) && !sero[y][x+1]){
                if(arr[y][x]>arr[ny][nx]){
                    int dif = arr[y][x]-arr[ny][nx];
                    dif/=4;
                    tmp[y][x] -= dif;
                    tmp[ny][nx] += dif;
                }
            }

        }
    }

}


void solve3(){

    for(int i=1; i<=C; i++){
        if(arr[1][i]>0) arr[1][i]--;
        if(arr[R][i]>0) arr[R][i]--;
    }

    for(int j=2; j<R; j++){
        if(arr[j][1]>0) arr[j][1]--;
        if(arr[j][C]>0) arr[j][C]--;
    }

}


bool checkAir(){

    for(auto c : check){
        if(arr[c.first][c.second]<K) return false;
    }

    return true;
}


void copyArr(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            arr[i][j] += tmp[i][j];
            tmp[i][j]=0;
        }
    }
}

void show(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}


//온풍기가 있는 칸도 다른 온풍기에 의해 온도가 상승할 수 있다.
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>R>>C>>K;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin>>arr[i][j];

            if(arr[i][j]>=1 && arr[i][j]<=4){
                airs.push_back(air(i,j,arr[i][j]));
                arr[i][j]=0;
            }
            else if(arr[i][j]==5) {
                arr[i][j]=0;
                check.push_back({i,j});
            };
        }
    }

    cin>>W;
    int x, y, t;
    for(int i=0; i<W; i++){
        cin>>y>>x>>t;
        if(t==0) garo[y-1][x]=true;
        else sero[y][x+1]=true;
        }


    int choco=0;
    while(1){

        //1 . 온풍기
        for (auto a : airs){
            int y = a.y;
            int x = a.x;
            int d = a.d;

            if(d==1) solve1(y, x+1, d);
            else if(d==2) solve1(y, x-1, d);
            else if(d==3) solve1(y-1, x, d);
            else if(d==4) solve1(y+1, x, d);
        }

        //2. 온도 조절
        solve2();
        copyArr();

        //3. 온도가 1 이상인 가장 바깥쪽 칸의 온도가 1씩 감소
        solve3();

        //4. 초콜렛 하나 먹는다
        choco++;

     //   cout<<choco<<'\n';
     //   show();
     //   cout<<"========\n";

        //5. 조사하는 모든 칸의 온도가 K 이상이 되었는지 검사.
        if(checkAir()) break;
        if(choco>100) break;
    }

    cout<<choco;

}