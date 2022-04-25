#include<iostream>
#include<winsock2.h>
#pragma warning(disable : 4996)//关闭过期函数的警告
#pragma warning(disable : 6031)//忽略返回值接受
#pragma comment(lib, "ws2_32.lib")

int main() {
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);//初始化winsock库，返回0表示初始化成功

	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);//创建流式套接字

	SOCKADDR_IN serverAddr;//地址结构体，保存地址的协议，ip，端口
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(8080);

	connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));//为啥需要转化为sockaddr*

	char sendData[] = "hello world";

	send(clientSocket, sendData, strlen(sendData), 0);

	char recvData[1024]="\0";

	recv(clientSocket, recvData, 1024, 0);//接受缓冲区的大小，缓冲区多大，就写多大，别用strlen（）

	printf("%s", recvData);

	return 0;
}
