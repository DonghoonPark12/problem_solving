#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard2.h"

int main(void)
{
	List list;
	NameCard *nc;
	ListInit(&list);

	/*** 3개의 데이터 저장 ***/
	nc = MakeNameCard("pdh", "01011112222");
	LInsert(&list, nc);

	nc = MakeNameCard("ksb", "01033334444");
	LInsert(&list, nc);

	nc = MakeNameCard("kmg", "01055556666");
	LInsert(&list, nc);
	
	
	/*** 이름을 기준으로 번호 정보 조회 ***/
	char *searchname = "ksb";
	if (LFirst(&list, &nc)) {
		if (NameCompare(nc, searchname) == 1) {
			ShowNameCardInfo(nc);
		}
		else {
			while (LNext(&list, &nc)) {
				if (NameCompare(nc, searchname) == 1) {
					ShowNameCardInfo(nc);
					break;
				}
			}
		}
	}

	/*** 이름을 기준으로 번호 정보 변경 ***/
	searchname = "ksb";
	char *toChangeNum = "01088889999";
	if (LFirst(&list, &nc)) {
		if (NameCompare(nc, searchname) == 1) {
			ChangePhoneNum(nc,toChangeNum);
		}
		else {
			while (LNext(&list, &nc)) {
				if (NameCompare(nc, searchname) == 1) {
					ChangePhoneNum(nc, toChangeNum);
				}
			}
		}
	}


	/*** 이름을 기준으로 정보 삭제 ***/
	searchname = "ksb";
	if (LFirst(&list, &nc)) {
		if (NameCompare(nc, searchname) == 1) {
			nc = LRemove(&list);
			free(nc);
		}
		else {
			while (LNext(&list, &nc)) {
				if (NameCompare(nc, searchname) == 1) {
					nc = LRemove(&list);
					free(nc);
					break;
				}
			}
		}
	}


	/*** 저장된 데이터의 출력 ***/
	if (LFirst(&list, &nc)) {
			ShowNameCardInfo(nc);
		while (LNext(&list, &nc)) {
				ShowNameCardInfo(nc);
		}
	}

	return 0;
}
