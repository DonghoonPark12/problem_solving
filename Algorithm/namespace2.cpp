#include <namespace.h>

void BestComImpl::SimpleFunc() {
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}
void ProgComImpl::SimpleFunc() {
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}

void BestComImpl::PrettyFunc() {
	std::cout << "Pretty!!" << std::endl;
}