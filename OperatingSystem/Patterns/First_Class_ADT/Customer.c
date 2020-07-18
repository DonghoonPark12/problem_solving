#include "Customer.h"
#include <stdlib.h>

#define Pointer_Allocation_Method       0
#define Memory_Pool_Method              0
#define Memory_and_Allocation_Method    1

/* Include guards and include files omitted. */
#define MAX_NO_OF_ORDERS 42

#if Pointer_Allocation_Method
/*
    리스트 방식, 고객이 메모리에 산별적으로 존재.
    구조체 안에 고객의 순번이 존재
*/

/* Internal representation of a customer. */
typedef struct
{
    const char* name;
    Address address;
    size_t noOfOrders;
    Order orders[MAX_NO_OF_ORDERS];
} Customer;

pCustomer createCustomer(const char* name, const Address* address)
{
    pCustomer customer = malloc(sizeof(Customer));
    if (customer)
    {
        /* Initialize each field in the customer... */
        //strcpy(customer->name, " ");
        //strcpy(customer->address.street, " ");
    }

    return customer;
}

void destoryCustomer(pCustomer customer)
{
    free(customer);
}

#elif Memory_Pool_Method
/*
    MemoryPool방식 : 고객의 정보가 메모리에 연속적으로 존재.
*/
#define MAX_NO_OF_CUSTOMERS 42

typedef struct
{
    const char* name;
    Address address;
    //size_t noOfOrders;
    //Order orders[42];
} Customer;

static struct Customer objectPool[MAX_NO_OF_CUSTOMERS];
static size_t numberOfObjects = 0;


pCustomer createCustomer(const char* name, const Address* address)
{
    pCustomer customer = NULL;

    if (numberOfObjects < MAX_NO_OF_CUSTOMERS) {
        customer = &objectPool[numberOfObjects++];
    }
    /* Initialize Customer */
    /* ... */

    return customer;
}

void destroyCustomer(pCustomer customer)
{
    /*
      In case de-allocation is needed, an array will still do, but
      a more sophisticated method for keeping track of “allocated” objects will be needed.
      However, such an algorithm is outside the scope of this book.
    */
}

#elif Memory_and_Allocation_Method == 1



#endif
