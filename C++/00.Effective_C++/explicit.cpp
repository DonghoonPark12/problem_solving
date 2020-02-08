#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	98.09년 도입된 키워드
*/

template <typename T>
struct Print {
    void operator() (T v) {
        cout << v << " ";
    }
};

class Stack {
private:
    vector<int> _data;
    int _pos;

public:
    const static int MIN_ELEM = 10;

    // 최대 n 개 요소를 가질 수 있는 Stack 생성자
    // 기본값을 지정해 봤습니다.
    explicit Stack(int n = MIN_ELEM) 
        : _data(n), _pos(0) 
    {
        cout << "Stack(int) called" << endl;
    }

    // 다른 Stack 을 복사해서 생성하는 복사 생성자
    Stack(const Stack& other) 
        : _data(other._data), _pos(other._pos) 
    {
        cout << "Stack(const Stack&) called" << endl;
    }

    // 다른 배열을 복사해서 생성하는 생성자
    Stack(int arr[], int n) 
        : _data(arr, arr + n), _pos(n) 
    {
        cout << "Stack(int[], int) called" << endl;
    }

    // 다른 vector 를 복사해서 생성하는 생성자
    Stack(vector<int> v) 
        : _data(v), _pos(v.size()) 
    {
        cout << "Stack(vector<int>) called" << endl;
    }

    // 그냥 어떻게 작동하는지 확인하기 위한 디버깅용 멤버 함수
    void printAll() {
        for_each(_data.begin(), _data.end(), Print<int>());
        cout << endl;
    }
};

int main(void){
    Stack s1;
    s1.printAll();
    Stack s2(20);
    s2.printAll();
    Stack s3(s2);
    
    vector<int> v(10, 3);
    for_each(v.begin(), v.end(), Print<int>());
    cout << endl;
    
    Stack s4(v);  // Stack(vector<int>) called
    Stack s5 = v; // Stack(vector<int>) called
    s1 = v;       // 이게 어떤 효과를 일으킬까요 ? 스택에다가 vector를 집어 넣는다??
                  // Stack(vector<int>) called

    s2 = 10;      // 버그 아닌가요 ? 좀 이상하지 않나요 ? 스택에다가 정수를 집어 넣는다??
                  // Stack(int) called
    s1.printAll();          // 뭐가 찍힐까요 ? : 3 3 3 3 3 3 3 3 3 3
    s2.printAll();          // 뭐가 찍힐까요 ? : 0 0 0 0 0 0 0 0 0 0
 }

/*
    <75번 라인 해석>
     
     1) operator= 선언되어 있지 않음!

     2) 컴파일러가 생성한 복사 할당 연산자가 있을 것입니다. 자기가 생성한 복사 할당 연산자를 쓰려고 했더니(?), 
     이번에는 10 이라는 정수값이 복사 할당 연산자의 인자와 호환이 되질 않네요.
     왜냐하면, 컴파일러가 생성한 operator=(const Stack&) 은 인자를 Stack 클래스로 받을 것이기 때문에.

     3) 혹시 정수를 복사 할당 연산자의 인자(const Stack& 일 겁니다)로 변환할 수 있는지를 볼 겁니다
     
     4) 여기에서 C++ 컴파일러는 인자가 하나인 생성자를 암시적 형변환하는데 사용한다는 것(??!!)을 기억해 보세요.

     5) Stack(int) 가 눈에 띄네요. 그래서 결국 Stack(10) 을 호출해서 10개의 요소를 갖는 Stack 을 생성하고 그걸 복사 할당 연산자를 이용해서 s2 에 할당하게 됩니다
 */

/*
    정답: 
    '컴파일러 입장에서 살펴 본대로 'C++ 의 암시적 형변환 규칙'에 따르면'
    클래스의 생성자 중에 인자가 하나인 생성자들은 프로그래머의 의도와는 전혀 상관없이 
    컴파일러에 의해 암시적 형변환에 동원되도록 되어 있어서
    s1 = v, s2 = 10 이라는 코드를 만나면 각각 Stack(vector<int>), Stack(int) 를 호출하여 
    '임시 객체'를 생성하고, 
    그 '임시 객체'를 가지고 복사 할당 연산자를 호출하게 됩니다
*/

/*  explicit 키워드 필요성의 대두 :

    하지만...
    아무리 적응하려고 한다지만 s2 = 10 을 만났을 때 Stack(int) 를 호출하는 건 
    프로그래머 입장에서는 참 예상하기 힘든 일입니다. 
    그래서 이런 예상치 못한 수행이 일어나면 프로그래머는 그런 버그를 정말 찾기 힘들게 됩니다.


    피해가는 방법이야 s2 = 10 과 같은 코드를 작성하지 않도록 Coding Guideline 에 넣어 두고,
    Code Review 도 하고 그런 방법도 있겠지만 좀 더 좋은 방법은 아예 s2 = 10 과 같은 코드를 만나면
    컴파일시에 에러가 발생해 버린다면 더 좋을 것입니다
    (항상 기억하세요! 에러는 빨리 발견할 수록 수정하는데 드는 비용이 작다).

    explicit 키워드는 인자가 하나인 생성자가 암시적 형변환에 쓰이지 않도록 해줍니다.

    그러니, 클래스의 생성자를 설계할 때, 인자가 하나만 있는 생성자에 대해서는 암시적
    형변환이 발생할 때 어떤일이 벌어질지를 꼭 생각해보고, 암시적 형변환이 말이 안되는
    의미를 갖게될 경우(i.g. s2 = 10; ) explicit라는 키워드를 꼭 붙인다.

    결론:
    생성자에 explicit 키워드를 써서 불필요한 암시적 형변환을 막아두자.
*/

/*
    http://opensw.wikidot.com/cpp-fundamentals-explicit
*/