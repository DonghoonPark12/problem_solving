#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/types.h>
/*
	<linux/list.h>

	#define LIST_HEAD_INIT(name) { &(name), &(name) }
	
	#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name) //name이라는 list_head 구조체 선언
																	     // *next와 *prev는 본인(name 구조체)를 가리키도록 주소 초기화
	
	static inline void INIT_LIST_HEAD(struct list_head *list)
	{
		WRITE_ONCE(list->next, list);
		list->prev = list;
	}

*/

/*
	<linux/type.h>

	struct list_head { //list_head 구조체의 목적은 리스트를 구성하는 노드 안에 연결 리스트를 내장하는 것이다. 
		struct list_head *next, *prev;
	};

	-----
	쉽게 풀어쓰면
	struct list_head name = { &(name), &(name) }
*/
static LIST_HEAD(birthday_list);


struct birthday *person; //구조체 포인터 
person = kmalloc(sizeof(*person), GFP KERNEL); // 커널 함수, 커널 메모리 할당 
person->day = 2;
person->month = 8;
person->year = 1995;
INIT_LIST_HEAD(&person->list);


