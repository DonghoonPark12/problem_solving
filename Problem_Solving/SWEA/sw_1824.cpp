
// int mem;
// void mem_plus(){
//     if (mem == 15) mem = 0;
//     else mem++;
// }
// void mem_minus(){
//     if (mem == 0) mem = 15;
//     else mem--;
// }

// int main(){
//     freopen("input.txt", "r", stdin);
//     int T;
//     int Answer;
//     for(int tc; tc<T;tc++){
//         mem = 0;
//         int x=0, y=0;
//         cin>>T;
//         int r,c;
//         cin>>r>>c;
//         vector<vector<int> > arr(r, vector<int>(c));
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 cin>>arr[i][j];
//             }
//         }  
//         while(1){
//             if(arr[y][x]<10 && arr[y][x]>=0){
//                 mem = arr[y][x];
//                 x++;
//             }
//             else if(arr[y][x] == '>'){x++;}
//             else if(arr[y][x] == '<'){x--;}
//             else if(arr[y][x] == '^'){y--;}
//             else if(arr[y][x] == 'v'){y++;}
//             else if(arr[y][x] == '_'){if (mem==0) x++; else x--;}
//             else if(arr[y][x] == '|'){if (mem==0) y++; else y--;}
//             else if(arr[y][x] == '+'){mem_plus();}
//             else if(arr[y][x] == '-'){mem_minus();}
//             else if(arr[y][x] == '?'){
//                 if(rand()%4==0 && x+1<c){ x++; }
//                 else if(rand()%4==1 && x-1>=0){ x--; }
//                 else if(rand()%4==2 && y+1<r){ y++; }
//                 else if(rand()%4==3 && y-1>=0){y--;}
//                 else{}
//             }
//             else if(arr[y][x]){Answer = 1; break;}


//         }

//         if(Answer)
//             cout<<"#"<<tc+1<<"YES"<<endl;
//         else
//             cout<<"#"<<tc+1<<"NO"<<endl;
//     }
// }
/*
    프로그램을 종료시키는 것을 판단하게 하기 위해서는 visited 배열이 필요하며,
    x, y, 메모리, 방향 정보를 visited 배열이 방문 여부를 판단하는데 사용해야 한다.
    https://hibee.tistory.com/290
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
struct node{
    int x, y, mem, dir;
    node(int _x, int _y, int _mem, int _dir)
    :x(_x), y(_y), mem(_mem), dir(_dir)
    {}
};
int r,c;
bool visited[21][21][16][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<char> > arr(21, vector<char>(21));

bool bfs(){
    queue<node> q;
    q.push(node(0,0,0,0));
    visited[0][0][0][0] = true;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int mem = q.front().mem;
        int dir = q.front().dir;
        q.pop();

        if(arr[x][y]<='9' && arr[x][y]>='0'){ mem = arr[x][y] - '0';}
        else if(arr[x][y] == '>'){dir = 0;}
        else if(arr[x][y] == '<'){dir = 1;}
        else if(arr[x][y] == 'v'){dir = 2;}
        else if(arr[x][y] == '^'){dir = 3;}
        else if(arr[x][y] == '_'){dir = mem == 0? 0 : 1;}
        else if(arr[x][y] == '|'){dir = mem == 0? 2 : 3;}
        else if(arr[x][y] == '+'){mem = mem==15 ? 0:mem + 1;}
        else if(arr[x][y] == '-'){mem = mem==0 ? 15:mem - 1;}
        else if(arr[x][y] == '@') return true;
        else if(arr[x][y] == '?'){
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx == -1) nx = r-1;
                else if(nx == r) nx = 0;
                if(ny == -1) ny = c-1;
                else if(ny == c) ny = 0;

                if(!visited[nx][ny][mem][i]){
                    q.push(node(nx, ny, mem, i));
                    visited[nx][ny][mem][i] = true;
                }
            }
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx == -1) nx = r-1;
        else if(nx == r) nx = 0;
        if(ny == -1) ny = c-1;
        else if(ny == c) ny = 0;

        if(!visited[nx][ny][mem][dir]){
            q.push(node(nx, ny, mem, dir));
            visited[nx][ny][mem][dir] = true;
        }
    }
    return false;
}

int main(){
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    int T;
    string Answer;
    cin>>T;
    for(int tc =0; tc<T;tc++){
        cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>arr[i][j];
            }
        }  
        memset(visited, false, sizeof(visited));
        Answer = bfs() ? "YES" : "NO";
        cout<<"#"<<tc+1<<" "<<Answer<<endl; 
    }
    return 0;
}