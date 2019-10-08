#include <iostream>
#include <string>
using namespace std;

class player{
    string name;
public:
    void setname(string str);
    string getname();
};
void player::setname(string str){
    this->name = str;
}
string player::getname(){ 
    return this->name;
}

class GambligGame{
    public:
    player pl[2];
    void setgame();
};
void GambligGame::setgame(){
    cout<<"*** 갬블링 게임을 시작합니다. *****";
    string str;
    cout<<"첫번째 선수 이름>>"; cin>>str; (pl[0]).setname(str);
    cout<<"두번째 선수 이름>>"; cin>>str; (pl[1]).setname(str);
    int st = 0;
    while(1){
        cout<<pl[st%2].getname()<<": \n";
        cin.ignore(); cout<<"<Enter>\n";
        int a = rand()%2, b = rand()%2, c = rand()%2;
        cout<<"         "<<a<<"     "<<b<<"     "<<c<<"     ";
        if(a==b && b==c){
            cout<<pl[st%2].getname()<<"님 승리!!\n"; break;
        }
        else{
            cout<<"아쉽군요!\n";
        }
        st++;
    }
}
int main(){
    GambligGame gbl;
    gbl.setgame();
    return 0;
}