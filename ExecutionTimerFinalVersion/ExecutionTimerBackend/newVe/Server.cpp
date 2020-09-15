#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<unistd.h>
#include "ExecResult.h"
#include<iostream>
#define PORT 8081
 


int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = (INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        perror("socket bind failed...\n");

        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        perror("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
    int len2 =sizeof(servaddr);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t*)&len);//can also be len2
    if (connfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");
    
    //myExecResult * results = new myExecResult();
    //int valRead2 = recv(connfd,(void *)results,sizeof(*results),0);

    //std::cout << results->funcName << " : " << results->difference << std::endl;
    
    //As an alternative,I will try object version 

    int i = 0; 
    while (true ){
        myExecResult results;
    
        int receive = recv(connfd,(void *)&results,sizeof(results),0);
        std::cout << results.funcName << " : " << results.difference << std::endl;
        i++;

    }

   
    sleep(3);


}


