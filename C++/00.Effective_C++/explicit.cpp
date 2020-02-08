#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	98.09�� ���Ե� Ű����
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

    // �ִ� n �� ��Ҹ� ���� �� �ִ� Stack ������
    // �⺻���� ������ �ý��ϴ�.
    explicit Stack(int n = MIN_ELEM) 
        : _data(n), _pos(0) 
    {
        cout << "Stack(int) called" << endl;
    }

    // �ٸ� Stack �� �����ؼ� �����ϴ� ���� ������
    Stack(const Stack& other) 
        : _data(other._data), _pos(other._pos) 
    {
        cout << "Stack(const Stack&) called" << endl;
    }

    // �ٸ� �迭�� �����ؼ� �����ϴ� ������
    Stack(int arr[], int n) 
        : _data(arr, arr + n), _pos(n) 
    {
        cout << "Stack(int[], int) called" << endl;
    }

    // �ٸ� vector �� �����ؼ� �����ϴ� ������
    Stack(vector<int> v) 
        : _data(v), _pos(v.size()) 
    {
        cout << "Stack(vector<int>) called" << endl;
    }

    // �׳� ��� �۵��ϴ��� Ȯ���ϱ� ���� ������ ��� �Լ�
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
    s1 = v;       // �̰� � ȿ���� ����ų��� ? ���ÿ��ٰ� vector�� ���� �ִ´�??
                  // Stack(vector<int>) called

    s2 = 10;      // ���� �ƴѰ��� ? �� �̻����� �ʳ��� ? ���ÿ��ٰ� ������ ���� �ִ´�??
                  // Stack(int) called
    s1.printAll();          // ���� ������� ? : 3 3 3 3 3 3 3 3 3 3
    s2.printAll();          // ���� ������� ? : 0 0 0 0 0 0 0 0 0 0
 }

/*
    <75�� ���� �ؼ�>
     
     1) operator= ����Ǿ� ���� ����!

     2) �����Ϸ��� ������ ���� �Ҵ� �����ڰ� ���� ���Դϴ�. �ڱⰡ ������ ���� �Ҵ� �����ڸ� ������ �ߴ���(?), 
     �̹����� 10 �̶�� �������� ���� �Ҵ� �������� ���ڿ� ȣȯ�� ���� �ʳ׿�.
     �ֳ��ϸ�, �����Ϸ��� ������ operator=(const Stack&) �� ���ڸ� Stack Ŭ������ ���� ���̱� ������.

     3) Ȥ�� ������ ���� �Ҵ� �������� ����(const Stack& �� �̴ϴ�)�� ��ȯ�� �� �ִ����� �� �̴ϴ�
     
     4) ���⿡�� C++ �����Ϸ��� ���ڰ� �ϳ��� �����ڸ� �Ͻ��� ����ȯ�ϴµ� ����Ѵٴ� ��(??!!)�� ����� ������.

     5) Stack(int) �� ���� ��׿�. �׷��� �ᱹ Stack(10) �� ȣ���ؼ� 10���� ��Ҹ� ���� Stack �� �����ϰ� �װ� ���� �Ҵ� �����ڸ� �̿��ؼ� s2 �� �Ҵ��ϰ� �˴ϴ�
 */

/*
    ����: 
    '�����Ϸ� ���忡�� ���� ����� 'C++ �� �Ͻ��� ����ȯ ��Ģ'�� ������'
    Ŭ������ ������ �߿� ���ڰ� �ϳ��� �����ڵ��� ���α׷����� �ǵ��ʹ� ���� ������� 
    �����Ϸ��� ���� �Ͻ��� ����ȯ�� �����ǵ��� �Ǿ� �־
    s1 = v, s2 = 10 �̶�� �ڵ带 ������ ���� Stack(vector<int>), Stack(int) �� ȣ���Ͽ� 
    '�ӽ� ��ü'�� �����ϰ�, 
    �� '�ӽ� ��ü'�� ������ ���� �Ҵ� �����ڸ� ȣ���ϰ� �˴ϴ�
*/

/*  explicit Ű���� �ʿ伺�� ��� :

    ������...
    �ƹ��� �����Ϸ��� �Ѵ����� s2 = 10 �� ������ �� Stack(int) �� ȣ���ϴ� �� 
    ���α׷��� ���忡���� �� �����ϱ� ���� ���Դϴ�. 
    �׷��� �̷� ����ġ ���� ������ �Ͼ�� ���α׷��Ӵ� �׷� ���׸� ���� ã�� ����� �˴ϴ�.


    ���ذ��� ����̾� s2 = 10 �� ���� �ڵ带 �ۼ����� �ʵ��� Coding Guideline �� �־� �ΰ�,
    Code Review �� �ϰ� �׷� ����� �ְ����� �� �� ���� ����� �ƿ� s2 = 10 �� ���� �ڵ带 ������
    �����Ͻÿ� ������ �߻��� �����ٸ� �� ���� ���Դϴ�
    (�׻� ����ϼ���! ������ ���� �߰��� ���� �����ϴµ� ��� ����� �۴�).

    explicit Ű����� ���ڰ� �ϳ��� �����ڰ� �Ͻ��� ����ȯ�� ������ �ʵ��� ���ݴϴ�.

    �׷���, Ŭ������ �����ڸ� ������ ��, ���ڰ� �ϳ��� �ִ� �����ڿ� ���ؼ��� �Ͻ���
    ����ȯ�� �߻��� �� ����� ���������� �� �����غ���, �Ͻ��� ����ȯ�� ���� �ȵǴ�
    �ǹ̸� ���Ե� ���(i.g. s2 = 10; ) explicit��� Ű���带 �� ���δ�.

    ���:
    �����ڿ� explicit Ű���带 �Ἥ ���ʿ��� �Ͻ��� ����ȯ�� ���Ƶ���.
*/

/*
    http://opensw.wikidot.com/cpp-fundamentals-explicit
*/