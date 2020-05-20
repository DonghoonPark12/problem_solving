/* Thread */

#include <thread>
#include <iostream>
using namespace std;

void func1(int value) {
	for (int i = 0; i < 500; i++){
		cout << value;
	}
}

int main() {
	thread t1(&func1,3);
	thread t2(&func1,4);


	t1.join();
	t2.join();


	for (int i = 0; i < 500; i++){
		cout << 0;
	}


	return 0;
}