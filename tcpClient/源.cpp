#include<iostream>
#include<winsock2.h>
#pragma warning(disable : 4996)//�رչ��ں����ľ���
#pragma warning(disable : 6031)//���Է���ֵ����
#pragma comment(lib, "ws2_32.lib")

int main() {
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);//��ʼ��winsock�⣬����0��ʾ��ʼ���ɹ�

	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);//������ʽ�׽���

	SOCKADDR_IN serverAddr;//��ַ�ṹ�壬�����ַ��Э�飬ip���˿�
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(8080);

	connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));//Ϊɶ��Ҫת��Ϊsockaddr*

	char sendData[] = "hello world";

	send(clientSocket, sendData, strlen(sendData), 0);

	char recvData[1024]="\0";

	recv(clientSocket, recvData, 1024, 0);//���ܻ������Ĵ�С����������󣬾�д��󣬱���strlen����

	printf("%s", recvData);

	return 0;
}
