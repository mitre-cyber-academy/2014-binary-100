#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>	
#include <string.h>
#include <errno.h> //DEBUGGING


int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	int request;
	int incoming; 
	int pass = 0x4e49434b; //CHANGE TO ACTUAL PASS
	char key[] = "aSByZWFsbHkgaG9wZSBsaWZlIGdldHMgZWFzaWVyLi4u";
	char reject[] = "Nope.\n";

	bzero((char *) &server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(51717);

	bind(sock, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(sock, 10);

	socklen_t clientLength = sizeof(client_address);

	printf("%d\n", request); //DEBUGGING

	while((incoming = accept(sock, (struct sockaddr *) &client_address, &clientLength)))
	{
		int temp = recv(incoming, &request, sizeof(request), 0);

		if(temp == - 1)
		{
			printf("***RECEIVE ERROR**** \n");
			printf("%s\n", strerror(errno));	
		}

		if(request == pass)
		{
			printf("%d\n", request); //DEBUGGING
			printf("%d\n", pass); //DEBUGGING
			puts("Access granted");
			temp = send(incoming, strcat(key, " \n"), sizeof(key) + 1, 0);
		}
		else
		{
			printf("Request: %d\n", request);  //DEBUGGING
			printf("Request (Hex): %x\n", request); //DEBUGGING
			printf("Pass: %d\n", pass);  //DEBUGGING
			printf("Pass (Hex): %x\n", pass); //DEBUGGING
			puts("Access denied");
			temp = send(incoming, reject, sizeof(reject) + 1, 0);
		}
	}
	close(incoming);
	close(sock);

	return(0);
}