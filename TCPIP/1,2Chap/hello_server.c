#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char* message);

/*
	[����]
	������ ��Ʈ��ũ ���� ����
	������ ���α׷��ӿ��� ������ �ۼ��ſ� ���� ������, SW�� ������ ������ �Ű澲�� �ʰ� �Ѵ�.

	TCP �Լ��� �ѹ� ȣ��������, IP ����-Link �������� ������ �����Ͱ� �ְ� ���� �� �� �ִ�.
	��, ���۰�� Ȯ��, �۽ſ� ���� ���� ���� ������ ����ڴ� �Ű澲�� �ʾƵ� �ȴ�. 

	int socket(int domain, int type, int protocol);

	int bind(int sockfd, struct sockaddr* myaddr, socklen_t addlen);

	int listen(int sockfd, int backlog);

	int accept(int sockfd, struct sockaddr *arr, socklen_t addlen);
*/

/*
	����� �˰���(��θ� �����ϴ� ���)  <-- ǥ��ȭ�� IP ������ ���
*/
int main(int argc, char *argv[])
{
	int serv_sock; /* �������� - ������ */
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "Hello World!";

	if (argc != 2)  {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_familty = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind() error");

	/*
		������ ������ �ϴ� ���� ������ ���������, 
		���� ��û ��� ť�� ���������.

		�� Listen �Լ� ȣ�� ���Ŀ��� Ŭ���̾�Ʈ��
		(���� ��û ������ ������ ���� ��û ���ť�� ��ϵ� �� ��ȯ�Ǵ�)
		connect �Լ� ȣ���� ��ȿ�ϴ�.
	*/
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");
	
	/* 
		���ť�� �����ϴ� ���� ��û �ϳ��� ���� ���ο� ������ ����.
		���� ��û�� Ŭ���̾�Ʈ ���Ͽ� ������� �̷�� ����. 

		Ŭ���̾�Ʈ ��û�� ���ö� ���� ��ȯ���� �ʴ´�.
	*/
	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
		error_handling("accept() error");

	/*
		Ŭ���̾�Ʈ���� ������ ����
	*/
	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);
	close(serv_sock);
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}