#ifndef __NAME_CARD2__
#define __NAME_CARD2__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

NameCard *MakeNameCard(char *name, char*phone); //NameCard ����ü ���� �Ҵ� �� �ʱ�ȭ

void ShowNameCardInfo(NameCard *pcard); //NameCard ����ü ������ ���� ���

int NameCompare(NameCard *pcard, char *name);//�̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ.

void ChangePhoneNum(NameCard *pcard, char *phone); //��ȭ��ȣ ������ ����.

#endif