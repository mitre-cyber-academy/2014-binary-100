#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>	
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_address;
	struct hostent *server = gethostbyname("localhost"); //REPLACE WITH ACTUAL SERVER NAME
	int port = 51717; //REPLACE WITH ACTUAL PORT
	int out;
	char reply[64] = "";
	uint32_t temp;

	bzero((char *) &server_address, sizeof(server_address));

	server_address.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
	server_address.sin_port = htons(port);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));

	int keyRequest = 0;
	char buffer[80];

	//printf("%d\n", sizeof(buffer)); //DEBUGGING
	//printf("%d\n", sizeof(keyRequest)); //DEBUGGING

	//printf("Buffer[0]: %p 	Buffer[79]: %p	 Buffer: %p 	keyRequest: %p\n", &buffer[0], &buffer[79], &buffer, &keyRequest); //DEBUGGING, BUT MAY KEEP

	//printf("keyRequest: %d\n", keyRequest);

	printf("Input: ");
	gets(buffer);
	//puts(buffer); //DEBUGGING

	//printf("Request: %d\n", keyRequest); //DEBUGGING
	//printf("Requsest (Hex): %x\n", keyRequest); //DEBUGGING

	temp = htonl(keyRequest);

	out = send(sock, &temp, sizeof(uint64_t), 0);
	out = recv(sock, reply, 64, 0);

	puts(reply);

	return(0);
}