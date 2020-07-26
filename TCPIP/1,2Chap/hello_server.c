#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char* message);

/*
	[설명]
	소켓은 네트워크 연결 도구
	소켓은 프로그래머에게 데이터 송수신에 대한 물리적, SW적 세세한 내용을 신경쓰지 않게 한다.

	TCP 함수를 한번 호출하지만, IP 계층-Link 계층에는 여러번 데이터가 주고 받을 수 도 있다.
	즉, 전송경로 확인, 송신에 대한 응답 등의 과정을 사용자는 신경쓰지 않아도 된다. 

	int socket(int domain, int type, int protocol);

	int bind(int sockfd, struct sockaddr* myaddr, socklen_t addlen);

	int listen(int sockfd, int backlog);

	int accept(int sockfd, struct sockaddr *arr, socklen_t addlen);
*/

/*
	라우팅 알고리즘(경로를 구성하는 방법)  <-- 표준화된 IP 계층의 결과
*/
int main(int argc, char *argv[])
{
	int serv_sock; /* 서버소켓 - 문지기 */
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
		문지기 역할을 하는 서버 소켓이 만들어지고, 
		연결 요청 대기 큐가 만들어진다.

		★ Listen 함수 호출 이후에야 클라이언트의
		(연결 요청 정보가 서버의 연결 요청 대기큐에 등록된 후 반환되는)
		connect 함수 호출이 유효하다.
	*/
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");
	
	/* 
		대기큐에 존재하던 연결 요청 하나를 꺼내 새로운 소켓을 생성.
		연결 요청한 클라이언트 소켓에 연결까지 이루어 진다. 

		클라이언트 요청이 들어올때 까지 반환하지 않는다.
	*/
	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
		error_handling("accept() error");

	/*
		클라이언트에게 데이터 전송
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