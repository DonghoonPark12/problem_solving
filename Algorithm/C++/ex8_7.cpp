#include <iostream>
using namespace std;

class BaseMemory {
	char *mem;
protected:
	BaseMemory(int size) {
		mem = new char[size];
	}
	void ch_memvalue(int i, char x) {
		mem[i] = x;
	}
	char get_memvalue(int i) {
		return mem[i];
	}
};
class ROM : BaseMemory {
public:
	ROM(int size, char *c, int num)
		:BaseMemory(size) {
		for (int i = 0; i < num; i++) {
			ch_memvalue(i, c[i]);
		}
	}
	char read(int i) {
		return get_memvalue(i);
	}
};

class RAM : BaseMemory {
public:
	RAM(int size)
		:BaseMemory(size)
	{}
	char read(int i) {
		return get_memvalue(i);
	}
	void write(int i, int value) {
		ch_memvalue(i, value);
	}
};
int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
	return 0;
}