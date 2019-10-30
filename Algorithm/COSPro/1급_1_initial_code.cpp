#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class DeliveryStore{
public:
    virtual void set_order_list(vector<string> order_list) = 0;
    virtual int get_total_price() = 0;
};

class Food{
public:
    string name;
    int price;
    Food(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class PizzaStore :DeliveryStore{ 
private:
    vector<Food> menu_list;
    vector<string> order_list;
public:
    PizzaStore(){
        //init menu_list
        menu_list = {{"Cheese", 11100}, {"Potato", 12600}, {"Shrimp", 13300},{"Pineapple", 21000}, {"Meatball", 19500}};

        //init order_list
        order_list.clear();
    }
    void DeliveryStore::set_order_list{
        for(int i = 0; i < order_list.size(); i++)
            this->order_list.push_back(order_list[i]);
    };

    @@@{
        int total_price = 0;
        for(int i = 0; i < order_list.size(); i++){
            for(int j = 0; j < menu_list.size(); j++)
                if(order_list[i] == menu_list[j].name){
                    total_price  += menu_list[j].price;
                    break;
                }
        }
        return total_price ;
    };
};

int solution(vector<string> order_list){
    DeliveryStore* delivery_store = new PizzaStore();
    
    delivery_store->set_order_list(order_list);
    int total_price = delivery_store->get_total_price();
    
    return total_price;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<string> order = {"Cheese", "Pineapple", "Meatball"};
    int ret = solution(order);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
    
    return 0;
}