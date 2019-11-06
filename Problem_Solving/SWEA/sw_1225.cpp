#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int t, num[8], k;
	for (int tc = 1; tc <= 10; ++tc) {
		scanf("%d", &t);
		for (int i = 0; i<8; ++i) scanf("%d", num + i);

		k = 0;
		while (true) {
			num[k % 8] -= k % 5 + 1;
			if (num[k % 8] <= 0) break;
			k++;
		}
		/*
		�迭 ���ҿ� ���ư��鼭 1~5�� ���� ���ش�. -= k%5 + 1
		���Ҵ� idx�� 8���� ũ�� �ȵȴ�. num[k%8]
		*/
		num[k % 8] = 0;
		printf("#%d", tc);
		for (int i = 1; i <= 8; ++i) 
			printf(" %d", num[(k + i) % 8]);
		printf("\n");
	}
}

//����Ʈ�� Ǯ��
#include <cstdio> 
/*
1,2. ���� ����, ������
���ڿ����� Ư�� ����Ŭ�� ������ ���ڰ� ���Ҹ� �ϸ� ���Ұ� 0���� ���� ��� ����.
3. ��� �ذ����� ��ȹ
����Ʈ�� Ǯ�� ������(���� �� ���� ����� �ְ�����) ��带 �����ϰ�, 1~5 ���� �� ��� ����, ������ �ݺ�
4. ��ȹ ����
�� ���� ����� ������ ���̴�. �� ����� ������ �״�� ����
5. ����
6. ȸ��, ���� ���
- tail�� ��� ��带 �����ϰ� �̵��ؾ� �Ѵٴ� ���� �˾�����
- ������ ������ (1) tail->next ��� ���� (2) tail ������ �̵� (3) ������ ���� �̴�.
- ����/�̵�/����
*/
typedef struct node {
	int data;
	node *next;
}Node;

int main() {
	int n;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (int t = 0; t < 10; t++) {
		scanf("%d ", &n);
		int data_;//����Ʈ�� ����� ������ ���� ���� 
		Node *head = new Node;
		//Node *tail = new Node;
		Node *tail = head;
		for (int i = 0; i < 8; i++) {
			tail->next = new Node;
			tail = tail->next;
			scanf("%d ", &data_);
			tail->data = data_;
		}
		int loss = 1;
		while (tail->data > 0) {
			Node *tmp = head->next;
			head->next->data -= loss;
			head->next = head->next->next;//��� ����

										  //tail = tail->next; //�����͸� �̵���Ų ������
										  //tail = new Node; //New ��带 ����� �ȵȴ�.
			tail->next = new Node;//���� ��带 �����ϰ�
			tail = tail->next;//�����͸� �̵��Ѵ�. 

			tail->data = tmp->data;//�ڷ� �̵�
			if (loss == 5)
				loss -= 4;
			else
				loss += 1;
			delete tmp;
		}
		if (tail->data < 0) tail->data = 0;
		printf("#%d ", n);
		Node *prt = head->next;
		//while (prt != NULL) {
		while (prt != tail->next) {
			printf("%d ", prt->data);
			prt = prt->next;
		}
		delete head;
		printf("\n");
	}
	return 0;
}