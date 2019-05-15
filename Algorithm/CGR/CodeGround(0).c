/* 상황에 따라 유리한 자료 구조가 있기 때문에 유연하게 사용할 수 있어야 한다. 	   			   */
/* 배열의 장, 단점: 포인터가 필요 없고, Value 값만 있어서 인덱싱에 편리. 	   			   */
/*				원소를 넣고, 빼기가 힘들다. 넣으려면 다른 원소들을 밀어야 한다.			   */
/* 리스트의 장, 단점: 원소(노드)들을 원할 때 마다 넣고, 빼기가 비교적 쉽다.	 			   */
/*				노드를 정의하는데 구조체가 필요하다(저장공간 더 필요) 포인터가 필요하다.	   */
				
/* List */
/* 첫 줄에 명령어의 개수 N이 주어진다. 			 */
/* 두 번째 줄부터 N개의 줄에 걸쳐 하나의 명령어 입력 */
/* Push x : x를 리스트의 끝에 추가			 */
/* get x : 리스트의 x 번째 원소 출력 			 */
/* size x : 리스트의 크기 출력 				 */
/* count x : 리스트에 있는 x의 개수를 출력      */
/* clear: 리스트를 비운다 					 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
	int value;
} node;

typedef struct list {
	node *head;
	node *last;
	int size;
} list;

void Init_list(list *mylist);
void push_back(list *mylist, int value);
int get_idx(list *mylist, int idx);
int count_target(list *mylist, int target);

