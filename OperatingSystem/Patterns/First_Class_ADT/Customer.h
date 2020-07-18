#include "Address.h"

typedef struct Customer* pCustomer;

//void initCustomer(Customer * theCustomer,const char* name, const Address * address);

//void placeOrder(Customer * customer,const Order * order);

pCustomer createCustomer(const char* name, const Address* address);

void destoryCustomer(pCustomer customer);



/* A lot of other related functions... */