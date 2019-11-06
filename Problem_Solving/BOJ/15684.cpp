#include <iostream>
#include <cstring>
using namespace std;
int h,n,m;
int s[31][11];
int backup[31][11];
int ret;

struct p{
    int y,x;
};
p t[30*9];

bool check(){
    for(int i=1;i<=n;i++){
        while(t[i].y != h){
            if( s[t[i].y][t[i].x] == 1 &&
                s[t[i].y][t[i].x+1] == 1 ){
                    t[i].x++;
                }
            else if( s[t[i].y][t[i].x] == 1 &&
                s[t[i].y][t[i].x-1] == 1 ){
                    t[i].x--;
                }
            else{
                t[i].y++;
            }
        }
    }
    bool flag = true;
    for(int i=1;i<=n;i++){
        if(t[i].x != i){
            flag = false;
        }
    }
    if(flag) return true;
    else return false;
}

int y,x;
// void dfs(int set, int yy, int xx){
//     if(set > 3) return;
//     if(check())
//         cnt = min(cnt,set);


//     for(y=yy;y<=h;y++){
//         for(x=xx;x<n;x++){
//             //memcpy(backup, s, sizeof(backup));
//             if(s[y][x] != 1){
//                 s[y][x] = 1; s[y][x+1] = 1;
//             }
//             for(int i=1;i<n;i++){
//                 t[i].x = i; t[i].y = 1;
//             } 
//             dfs(set+1, y, x);
//             s[y][x] = 0; s[y][x+1] = 0;
//             //memcpy(s, backup, sizeof(s));
//         }
//         x = 1;
//     }

// }

void dfs2(int count, int y, int x){
    if(count >= ret) return;
    if(check()){
        ret = count;
        return;
    }
    if(count == 3) return;

    for(int i=y;i<=h;i++){
        for(int j=x;j<n;j++){
            if(s[i][j]!=1 && s[i][j-1] != 0 && s[i][j+1] != 1){
                s[i][j] = 1;
                dfs2(count+1, i, j);
                s[i][j] = 0;
            }
        }
        x = 1;
    }
}
int main(){
    cin>>n>>m>>h;
    int tm1, tm2;
    for(int i=0;i<m;i++){
        cin>>tm1>>tm2;
        s[tm1][tm2] = 1;
        s[tm1][tm2+1] = 1;
    }
    for(int i=1;i<n;i++){
        t[i].x = i; t[i].y = 1;
    } 
    // cnt = -1;
    if(check()){
        ret = 0;
        cout<< ret<<'\n';
        return 0;
    }
    // else{
    //     dfs(0, 1, 1);        
    // }

    ret = 4;
    dfs2(0, 1, 1);
    if(ret == 4) ret = -1;
    cout<<ret<<'\n';
}

/*
    int cnt;//g
    int p; //g



    p = h*n - 2*m;


    
    for(int i=1;i<=n;i++){
        while(t[i].y != h){
            if( s[t[i].y][t[i].x] == 1 &&
                s[t[i].y][t[i].x+1] == 1 ){
                    t[i].x++;
                }
            else if( s[t[i].y][t[i].x] == 1 &&
                s[t[i].y][t[i].x-1] == 1 ){
                    t[i].x--;
                }
            else{
                t[i].y++;
            }
        }
    }
    bool flag = true;
    for(int i=1;i<=n;i++){
        if(t[i].x != i){
            flag = false;
        }
    }
    if(flag)
        return cnt;
        


 */