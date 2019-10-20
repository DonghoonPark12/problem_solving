#include <iostream>
#include <cstring>
using namespace std;

class Person{
private:
    char *name;
    int age;
public:
    Person(char *name, int age){
        int len = strlen(name) + 1; 
        this->name = new char[len];
        strcpy(this->name, name);
        this->age = age;
    }
    Person(const Person &p){
        int len = strlen(p.name) + 1; 
        this->name = new char[len];
        strcpy(this->name, p.name);
        this->age = p.age;
    }
    void ShowPersonInfo() const {
        cout<<"이름 : "<<name<<endl;
        cout<<"나이 : "<<age<<endl;
    }
    ~Person(){
        delete []name;
        cout<<"Call destructor!"<<endl;
    }
};

int main(){
    Person man1("Lee Dong Woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}