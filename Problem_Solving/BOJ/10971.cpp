#include <iostream>
#include <algorithm>
using namespace std;
int n; 
int  w[10][10];
bool vis[10];
int _min;
int sc;
void dfs(int s, int cnt, int wsum){

    if(cnt == 4) {
        if(w[s][sc]!=0){
            _min = min(_min, wsum + w[s][sc]);
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(i != s && vis[i] == false && w[s][i] != 0){//s와 같은 i는 거른다. 왜냐하면 i->i는 비용이 없기 때문.
            vis[i] = true;
            dfs(i, cnt+1, wsum + w[s][i]);
            vis[i] = false;
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    _min = 0x7fffffff;

    for(int s=0; s<n;s++){
        vis[s] = true;
        sc = s;
        dfs(s,1, 0);
        vis[s] = false;
    }
    cout<<_min<<'\n';
    return 0;
}