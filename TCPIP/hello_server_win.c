#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
/*
	int WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);

	int WSACleanup();

	SOCKET socket(int af, int type, int protocol);

	int bind(SOCKET s, const struct sockaddr *name, int namelen);

	int listen(SOCKET s, int backlog);

	SOCKET accept(SOCKET s, struct sockaddr *addr, int *addrlen);

	int connect(SOCKET s, const struct sockaddr *name, int namelen);

	int closesocket(SOCKET s); //리눅스의 경우는 소켓 종료시 파일 종료 함수 사용하였다
*/

void ErrorHandling(char* message);

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;

	int szClntAddr;
	char message[] = "Hello World!";

	if (argc != 2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if (hClntSock == INVALID_SOCKET)
		ErrorHandling("accept() error");

	send(hClntSock, message, sizeof(message), 0);
	closesocket(hClntSock);
	closesocket(hServSock);

	WSACleanup();
}