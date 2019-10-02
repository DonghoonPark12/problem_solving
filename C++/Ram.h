#pragma once
class Ram {
	char mem[100 * 1024];
	int size;
public:
	Ram();
	~Ram();
	char read(int address); //address 주소의 메모리 바이트 리턴
	void write(int address, char value); //address 주소에 한 바이트로 value 저장
};

