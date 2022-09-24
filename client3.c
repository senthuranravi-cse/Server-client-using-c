#include <stdio.h>
#include <stdlib.h>
#include<curses.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	FILE* fp = fopen("customer.csv", "a+");
	char *ip = "127.0.0.1";
	int port = 5566;
	int sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0){
		perror("[-]Error!!!");
		exit(1);
	}
	printf("[+]Taxi server created.\n");
	memset(&addr, '\0', sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = port;
	addr.sin_addr.s_addr = inet_addr(ip);
	connect(sock, (struct sockaddr*)&addr, sizeof(addr));
	printf("Connected to the Taxi server.\n");
	char a[100],b[100],c[100],b1[100];
	printf("Enter Name:");
	scanf("%s",a);
	bzero(buffer, 1024);
	strcpy(buffer,a);
	printf("Client: \n%s\n", buffer);
	send(sock, buffer, strlen(buffer), 0);
	bzero(buffer, 1024);
	recv(sock, buffer, sizeof(buffer), 0);
	printf("Admin: %s\n", buffer);
	printf("Enter Location:");
	scanf("%s",b);
	bzero(buffer, 1024);
	strcpy(buffer,b);
	printf("Client: \n%s\n", buffer);
	send(sock, buffer, strlen(buffer), 0);
	bzero(buffer, 1024);
	recv(sock, buffer, sizeof(buffer), 0);
	printf("Admin: %s\n", buffer);
	printf("Enter Destination:");
	scanf("%s",b1);
	bzero(buffer, 1024);
	strcpy(buffer,b1);
	printf("Client: \n%s\n", buffer);
	send(sock, buffer, strlen(buffer), 0);
	 bzero(buffer, 1024);
	 recv(sock, buffer, sizeof(buffer), 0);
	printf("Admin: %s\n", buffer);
	printf("Enter Phone_no:");
	scanf("%s",c);
	bzero(buffer, 1024);
	strcpy(buffer,c);
	printf("Client: \n%s\n", buffer);
	send(sock, buffer, strlen(buffer), 0);
	bzero(buffer, 1024);
	recv(sock, buffer, sizeof(buffer), 0);
	printf("Admin: %s\n", buffer);
	printf("\n");
	recv(sock, buffer, sizeof(buffer), 0);
	printf("Admin: %s\n", buffer);
	recv(sock, buffer, sizeof(buffer), 0);
	printf("Admin: %s\n", buffer);
	
	fprintf(fp, "%s, %s,%s,%s\n",a,b,b1,c);
	fclose(fp);
	close(sock);
	printf("your taxi will get you soon..................");
	printf("Disconnected from the server.\n");
	return 0;
}
