/* ��Ȳ�� ���� ������ �ڷ� ������ �ֱ� ������ �����ϰ� ����� �� �־�� �Ѵ�. 	   			   */
/* �迭�� ��, ����: �����Ͱ� �ʿ� ����, Value ���� �־ �ε��̿� ��. 	   			   */
/*				���Ҹ� �ְ�, ���Ⱑ �����. �������� �ٸ� ���ҵ��� �о�� �Ѵ�.			   */
/* ����Ʈ�� ��, ����: ����(���)���� ���� �� ���� �ְ�, ���Ⱑ ���� ����.	 			   */
/*				��带 �����ϴµ� ����ü�� �ʿ��ϴ�(������� �� �ʿ�) �����Ͱ� �ʿ��ϴ�.	   */
				
/* List */
/* ù �ٿ� ��ɾ��� ���� N�� �־�����. 			 */
/* �� ��° �ٺ��� N���� �ٿ� ���� �ϳ��� ��ɾ� �Է� */
/* Push x : x�� ����Ʈ�� ���� �߰�			 */
/* get x : ����Ʈ�� x ��° ���� ��� 			 */
/* size x : ����Ʈ�� ũ�� ��� 				 */
/* count x : ����Ʈ�� �ִ� x�� ������ ���      */
/* clear: ����Ʈ�� ���� 					 */

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

