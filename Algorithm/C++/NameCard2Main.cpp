#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard2.h"

int main(void)
{
	List list;
	NameCard *nc;
	ListInit(&list);

	/*** 3���� ������ ���� ***/
	nc = MakeNameCard("pdh", "01011112222");
	LInsert(&list, nc);

	nc = MakeNameCard("ksb", "01033334444");
	LInsert(&list, nc);

	nc = MakeNameCard("kmg", "01055556666");
	LInsert(&list, nc);
	
	
	/*** �̸��� �������� ��ȣ ���� ��ȸ ***/
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

	/*** �̸��� �������� ��ȣ ���� ���� ***/
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


	/*** �̸��� �������� ���� ���� ***/
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


	/*** ����� �������� ��� ***/
	if (LFirst(&list, &nc)) {
			ShowNameCardInfo(nc);
		while (LNext(&list, &nc)) {
				ShowNameCardInfo(nc);
		}
	}

	return 0;
}
