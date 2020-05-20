#include <stdint.h>

#define CMDSIZE 100

/*
	상황 : 
	cls, ins 마다 호출되어야 하는 함수가 존재한다.
	각각의 함수는 전달 받는 cls, ins를 확인하고 각각에 맞는 함수를 
	호출해야 한다.

	다음과 같은 구조의 장점	: 
	APDU(명령)과 함수를 하나로 묶었다. 그리고 이것을 배열에 담았다.
	하나의 모듈별로 인터페이스와 기능을 분리할 수 있는 장점이 있다.

	사용법 : 
	구조체 포인터의 주소를 Handler에게 넘겨준다. 	

*/

typedef void* EntryHandler;

typedef struct CommandEntry {
	uint8_t cls;
	uint8_t ins;

	void (* FuncP)();
}CommandEntry, *pCommandEntry;

struct CommandEntry CmdArray[CMDSIZE];

EntryHandler FindCommand(uint8_t cls, uint8_t ins) {
	int i;
	CommandEntry *pCommand = &CmdArray[0];

	for(i=0;i < CMDSIZE; i++){
		if (pCommand->cls == cls && pCommand->ins == ins) {
			break;
		}
		pCommand++;
	}
	return (EntryHandler)pCommand;
}




