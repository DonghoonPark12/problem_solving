#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
vector<int> pick;

int n,m; 
void dfs(int pos, vector<bool> visited){
    if(pick.size() == m){
        for(int v = 0; v<pick.size(); v++)
            cout<<pick[v]<<' ';
        cout<<'\n';
        return ;
    }
    for(int i=0;i<num.size();i++){
        if(!visited[num[i]]){
            pick.push_back(num[i]);
            visited[num[i]] = true;

            dfs(i + 1, visited);

            pick.pop_back();
            visited[num[i]] = false;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        num.push_back(i+1);
    }
    vector<bool> visited(n,false);
    dfs(0, visited);

    return 0;
}