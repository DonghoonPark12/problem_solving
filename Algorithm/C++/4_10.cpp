#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Histogram{
    string str;
    char alpha[26];
public:
    Histogram(string _str)
    :str(_str)
    {};
    void put(string str);
    void putc(char c);
    void print();
};

void Histogram::put(string str){
    // convert string to back to lower case
	//for_each(str.begin(), str.end(), [](char & c) {c = ::tolower(c);} );
    
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });

    (this->str).append(str);
}

void Histogram::putc(char c){ 
    (this->str)+=tolower(c);
    //(this->str).push_back(c);
}

void Histogram::print(){
    cout<<str<<'\n';
    cout<<"총 알파벳 수 "<<sizeof(str)<<'\n';

    for(int i=0; i<sizeof(str); i++){
        alpha[str[i] - 'a']++;
    }
    for(int i=0;i<26;i++){
        cout<<char(i+int('a'))<<" ("<<alpha[i]<<")  :"<<string('*',alpha[i])<<'\n';
    }
}

int main(){
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
    elvisHisto.put("falling in love in you");
    elvisHisto.putc('-');
    elvisHisto.put("Elvis Presly");
    elvisHisto.print();

    return 0;
}
