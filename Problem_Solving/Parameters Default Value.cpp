#include <iostream>

//int Adder(int num1 = 1, int num2 = 2);
//int BoxVolume(int  length) {
//	return length * 1 * 1;
//}
//
//int BoxVolume(int  length, int width) {
//	return length * width * 1;
//}
//int BoxVolume(int  length, int width, int height) {
//	return length * width * height;
//}
int SimpleFunc(int a = 10) {
	return a + 1;
} 
int SimpleFunc(void) {
	return 10;
}
int main() {
	/*std::cout << Adder() << std::endl;
	std::cout << Adder(5) << std::endl;
	std::cout << Adder(3,5) << std::endl;
	*/

	std::cout << SimpleFunc(7) << std::endl;
	std::cout << SimpleFunc() << std::endl; //10 ?? 11??

	//std::cout << "[3,3,3]: " << BoxVolume(3,3,3) << std::endl;
	//std::cout << "[5,5,D]: " << BoxVolume(5, 5) << std::endl;
	//std::cout << "[7,D,D]: " << BoxVolume(7) <<std::endl;

	//std::cout << "[D,D,D]: " << BoxVolume() << std::endl;
}
	




//int Adder(int num1, int num2) {
//	return num1 + num2;
//}