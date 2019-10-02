#include <namespace.h>

void BestComImpl::SimpleFunc() {
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}
void ProgComImpl::SimpleFunc() {
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}

void BestComImpl::PrettyFunc() {
	std::cout << "Pretty!!" << std::endl;
}