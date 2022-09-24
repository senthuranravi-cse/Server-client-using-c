#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <curses.h>

void server()
{
	char *ip = "127.0.0.1";
	int port = 5566;
	int server_sock, client_sock;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;
	server_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (server_sock < 0){
		perror("[-] Error!!!");
		exit(1);
	}
	printf("[+]Taxi server ON\n");
	memset(&server_addr, '\0', sizeof(server_addr));
	server_addr.sin_family = AF_INET;server_addr.sin_port = port;server_addr.sin_addr.s_addr = inet_addr(ip);n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));                                     
	if (n < 0){
		perror("[-]Bind error");
		exit(1);
	}
	printf("[+]Bind to the port number: %d\n", port);
	listen(server_sock, 5);
	printf("Wait for Customer");
	while(1){
		addr_size = sizeof(client_addr);
		client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
		printf("[+]Client arrived.\n");
		bzero(buffer, 1024);
		recv(client_sock, buffer, sizeof(buffer), 0);
		printf("Client: %s\n", buffer);
		char a[1000];
		printf("Reply:");
		scanf("%s",a);
		bzero(buffer, 1024);
		strcpy(buffer,a);
		printf("Admin: %s\n", buffer);
		send(client_sock, buffer, strlen(buffer), 0);

		bzero(buffer, 1024);
		recv(client_sock, buffer, sizeof(buffer), 0);
		printf("Client: %s\n", buffer);
		char b[1000];
		printf("Reply:");
		scanf("%s",b);
		bzero(buffer, 1024);
		strcpy(buffer,b);
		printf("Admin: %s\n", buffer);
		send(client_sock, buffer, strlen(buffer), 0);

bzero(buffer, 1024);
recv(client_sock, buffer, sizeof(buffer), 0);
printf("Client: %s\n", buffer);
char b1[1000];
printf("Reply:");
scanf("%s",b1);
bzero(buffer, 1024);
strcpy(buffer,b1);
printf("Admin: %s\n", buffer);
send(client_sock, buffer, strlen(buffer), 0);

		bzero(buffer, 1024);
		recv(client_sock, buffer, sizeof(buffer), 0);
		printf("Client: %s\n", buffer);
		char c[1000];
		printf("Reply:");
		scanf("%s",c);
		bzero(buffer, 1024);
		strcpy(buffer,c);
		printf("Admin: %s\n", buffer);
		send(client_sock, buffer, strlen(buffer), 0);

		char d[1000];
		printf("Driver Name:");
		scanf("%s",d);
		bzero(buffer, 1024);
		strcpy(buffer,d);
		send(client_sock, buffer, strlen(buffer), 0);
		
		char e[1000];
		printf("Driver Phone_no:");
		scanf("%s",e);
		bzero(buffer, 1024);
		strcpy(buffer,e);
		send(client_sock, buffer, strlen(buffer), 0);
		
		close(client_sock);
		printf("[+]Client disconnected.\n\n");
	}
}

void admin()
{

	FILE* fp = fopen("Driver.csv", "a+");
	char name[50],cm[90];
	int accountno, amount,age,exp;
	if (!fp) {
		printf("Can't open file\n");
	}
	printf("\nEnter Driver Name\n");
	scanf("%s", name);
	printf("\nEnter Driver Phone Number\n");
	scanf("%d", &accountno);
	printf("\nEnter Carno\n");
	scanf("%d", &amount);
	printf("Enter age\n");
	scanf("%d",&age);
	printf("Enter Experience\n");
	scanf("%d",&exp);
	printf("Enter carmodel");
	scanf("%s", cm);
	fprintf(fp, "%s, %d, %d,%d,%d,%s\n", name,accountno, amount,age,exp,cm);
	printf("\nNew Driver Added");
	fclose(fp);
}
void driver()
{
	FILE *fpt; 
	char c,d;
	char str[50];
	fpt=fopen("Driver.csv","r"); 
	if(fpt==NULL){
		printf("Can't open file ");
	}
	else {
		printf("Name,Phone_no,Carno,Age,Experience,Carmodel");
		printf("\n");
		printf("---- -------- ----- --- ---------- ---------");
		printf("\n");
		while(fgets(str,50,fpt)){
			puts(str);
		}
	}
	fclose(fpt);
}
void Customer()
{
	FILE *fpt; 
	char c,d;
	char str[50];
	fpt=fopen("customer.csv","r"); 
	if(fpt==NULL){
		printf("Can't open file ");
	}
	else {
		printf("Name,Location,Destination,Phone_no");
		printf("\n");
		printf("---- -------- -------- ------------");
		printf("\n");
		while(fgets(str,50,fpt)){
			puts(str);
		}
	}
	fclose(fpt);
}

int main(){
	int n;
	printf("1.New Driver Added\n2.Server ON\n3.Customer Database\n4.Driver Database");
	scanf("%d",&n);
	if(n==1)
	{
		admin();
	}
	if(n==2)
	{
		server();
	}
	if(n==3)
	{
		Customer();
	}
	if(n==4)
	{
		driver();
	}
	return 0;
}
