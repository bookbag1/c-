#include<iostream>
#include<winsock2.h>
#pragma comment (lib, "ws2_32.lib")
#pragma warning(disable : 4996)//关闭过期函数的警告
using namespace std;

int main() {
	cout << "服务器启动, 等待连接\n";

	WSADATA wsaData;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN serverAddr;
	
	serverAddr.sin_family = AF_INET;

	serverAddr.sin_port = htons(8080);

	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

	listen(serverSocket, 5);

	SOCKET clientSocket;
	SOCKADDR_IN clientAddr;
	int len = sizeof(SOCKADDR_IN);

	clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &len);


	char recvData[1024] = "\0";

	recv(clientSocket, recvData, 1024, 0);

	printf("%s\n", recvData);

	char sendData[] = "hello client";

	send(clientSocket, sendData, strlen(sendData), 0);

	cout << "结束";

	return 0;
}