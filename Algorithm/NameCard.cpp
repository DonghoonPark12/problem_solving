
#include "NameCard.h"

int main() {
	NameCard manClerk("Lee", "ABSEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	NameCard manAssist("Kim", "HappyCam", "010-5555-6666", COMP_POS::ASSIST);
	
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	
	return 0;
}

