#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    int Answer;
    for(int tc; tc<T;tc++){
        cin>>T;
        int r,c;
        cin>>r>>c;
        vector<vector<int> > arr(r, vector<int>(c));

        cout<<"#"<<tc+1<<Answer<<endl;
    }
}