/*
* Vector와 다르게 랜덤 접근이 가능, 앞에 삽입, 삭제가 용이
* Vector와 같이 중간 삽입 삭제는 용이하지 않다.
* 또한, 순차 접근이 가능, 크기 변경이 가능
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <malloc.h>
#include <string>
#include <iostream>
using namespace std;
int cnt = 0;

struct Node
{
	int data;
	Node *prev;
	Node *next;
};

struct Deque
{
	Node *head;
	Node *tail;
};

void init_Deque(Deque *Target_Deque)
{
	Target_Deque->head = NULL;
	Target_Deque->tail = NULL;
}

void input_Head(Deque *Target_Deque, int data)
{
	Node *New = (Node *)malloc(sizeof(Node));
	/* 앞으로 처음 추가 할때 */
	if (Target_Deque->head == NULL)
	{
		Target_Deque->head = New;
		Target_Deque->tail = New;
		New->prev = NULL;
		New->next = NULL;
		New->data = data;
		cnt++;
		return;
	}
	/* 하나 이상의 노드가 있을 때 */
	New->next = Target_Deque->head;
	Target_Deque->head->prev = New;
	Target_Deque->head = New;
	New->prev = NULL;
	New->data = data;
	cnt++;
}

void input_Tail(Deque *Target_Deque, int data)
{
	Node *New = (Node *)malloc(sizeof(Node));
	/* 뒤로 처음 추가 할때 */
	if (Target_Deque->tail == NULL)
	{
		Target_Deque->head = New;
		Target_Deque->tail = New;
		New->prev = NULL;
		New->next = NULL;
		New->data = data;
		cnt++;
		return;
	}
	New->prev = Target_Deque->tail;
	Target_Deque->tail->next = New;
	Target_Deque->tail = New;
	New->next = NULL;
	New->data = data;
	cnt++;
}
	
int output_Head(Deque *Target_Deque)
{
	if (Target_Deque->head == NULL||cnt == 0)
	{
		//printf("Empty!");
		//printf("-1\n");
		return -1;
	}
	int return_value;
	return_value = Target_Deque->head->data;
	Node *Cur = Target_Deque->head;

	Node *new_head = Target_Deque->head->next;
	//if (new_head != NULL)
	new_head->prev = NULL; //<- [ ]
	//Target_Deque->head->next = NULL; //[ ] -> 
	//Cur = Target_Deque->head;
	//if (new_head != NULL)
	Target_Deque->head = new_head;
	free(Cur);
	cnt--;

	return return_value;
}

int output_Tail(Deque *Target_Deque)
{
	if (Target_Deque->head == NULL || cnt == 0)
	{
		//printf("Empty!");
		//printf("-1\n");
		return -1;
	}
	int return_value;
	return_value = Target_Deque->tail->data;
	Node *Cur = Target_Deque->tail;

	Node *new_tail = Target_Deque->tail->prev;
	if(new_tail != NULL)
	new_tail->next = NULL; // [ ] ->
	//Target_Deque->tail->prev = NULL; // <- [ ]
	if (new_tail != NULL)
	Target_Deque->tail = new_tail;
	free(Cur);
	cnt--;

	return return_value;
}

int empty(Deque *Target_Deque)
{
	if ((Target_Deque->head == NULL && Target_Deque->tail == NULL)||cnt == 0)
		return 1;
	else
		return 0;
}

int size(Deque *Target_Deque)
{
	int cnt = 0;
	Node *cur = Target_Deque->head;

	while (cur != NULL)
	{
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	Deque *deq = (Deque *)malloc(sizeof(Deque));

	init_Deque(deq);

	int T,n;
	scanf("%d", &T);

	string str;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		if (str == "push_back")
		{
			cin >> n;
			input_Tail(deq, n);
		}
		else if (str == "push_front")
		{
			cin >> n;
			input_Head(deq, n);
		}
		else if (str == "front")
		{
			printf("%d\n", deq->head->data);
		}
		else if (str == "back")
		{
			printf("%d\n", deq->tail->data);
		}
		else if (str == "empty")
		{
			printf("%d\n", empty(deq));
		}
		else if (str == "pop_front")
		{
			printf("%d\n",output_Head(deq));
		}
		else if (str == "pop_back")
		{
			printf("%d\n", output_Tail(deq));
		}
		else if (str == "size")
		{
			printf("%d\n", size(deq));
		}
		else
		{

		}
		
	}
	return 0;

}

/*
#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
string s;
cin>>n;
deque<int> q;
	for(int i=0;i<n;++i){
	cin>>s;
	if(s=="push_back"){
		int x;
		cin>>x;
		q.push_back(x);
	}else if(s=="push_front"){
		int x;
		cin>>x;
		q.push_front(x);
	}else if(s=="pop_front"){
		cout<<(q.empty() ? -1:q.front())<<endl;
		if(!q.empty())
			q.pop_front();
	}else if(s=="pop_back"){
		 cout<<(q.empty()?-1:q.back())<<endl;
		if(!q.empty())
			q.pop_back();
	}else if(s=="size"){
		cout<<q.size()<<endl;
	}else if(s=="empty"){
		cout<<q.empty()<<endl;
	}else if(s=="front"){
		cout<<(q.empty()?-1:q.front())<<endl;
	}else if(s=="back"){
		cout<<(q.empty()?-1:q.back())<<endl;
}


*/
/*
	constexpr unsigned int HashCode(const char* str)
	{
	return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
	}

	void foo(const char* str)
	{
	switch (HashCode(str))
	{
	case HashCode("Kim"):
	// Do something...
	break;

	case HashCode("Lee"):
	// Do something...
	break;

	case HashCode("Park"):
	// Do something...
	break;
	}
	}
*/


/*
* 앞으로 문자열을 받을 때 string을 이용할 것
*
*/