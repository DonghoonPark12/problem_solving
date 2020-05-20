#include <stdint.h>

#define CMDSIZE 100

/*
	��Ȳ : 
	cls, ins ���� ȣ��Ǿ�� �ϴ� �Լ��� �����Ѵ�.
	������ �Լ��� ���� �޴� cls, ins�� Ȯ���ϰ� ������ �´� �Լ��� 
	ȣ���ؾ� �Ѵ�.

	������ ���� ������ ����	: 
	APDU(���)�� �Լ��� �ϳ��� ������. �׸��� �̰��� �迭�� ��Ҵ�.
	�ϳ��� ��⺰�� �������̽��� ����� �и��� �� �ִ� ������ �ִ�.

	���� : 
	����ü �������� �ּҸ� Handler���� �Ѱ��ش�. 	

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




