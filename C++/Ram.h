#pragma once
class Ram {
	char mem[100 * 1024];
	int size;
public:
	Ram();
	~Ram();
	char read(int address); //address �ּ��� �޸� ����Ʈ ����
	void write(int address, char value); //address �ּҿ� �� ����Ʈ�� value ����
};

