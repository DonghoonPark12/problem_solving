#include <string>
#include <NameCard2.h>

NameCard *MakeNameCard(char * name, char * phone)
{
	//NameCard *nc_tmp = new (NameCard);
	NameCard *nc_tmp = (NameCard *)malloc(sizeof(NameCard));

	//char *name = new char[NAME_LEN];
	//char *phone = new char[PHONE_LEN];
	strcpy(nc_tmp->name, name);
	strcpy(nc_tmp->phone, phone);
	return nc_tmp;
}

void ShowNameCardInfo(NameCard * pcard) {
	printf("Name: %s:\n",pcard->name);
	printf("Phone: %s:\n",pcard->phone);
}

int NameCompare(NameCard * pcard, char * name) {
	if (strcmp(pcard->name,name)) {
		return 1;
	}
	return 0;
}

void ChangePhoneNum(NameCard *pcard, char * phone) {
	strcpy(pcard->phone,NULL);
	strcpy(pcard->phone, phone);
}
