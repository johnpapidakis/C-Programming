/* Simple TCP Server where the port number is passed as an argument */
#include <stdio.h>
/* Headers needed for the socket programming */
#include <sys/types.h> /*define some data types used in system calls */ 
#include <sys/socket.h> /*definitions of structures needed for sockets */ 
#include <unistd.h> /* contains various constants */
#include <netinet/in.h>
#include <netdb.h>
/*constants and structures needed for Internet domain addresses */
#include <errno.h> /* Necessary because errno value used */ 
#include <string.h> /* Necessary for bzero() */
#include <stdlib.h> /* Necessary for exit() */
#include <time.h>
/*constants and structures needed for Internet domain addresses */
#include <arpa/inet.h> /* It is needed because inet_ntoa() */ 

#define BUFSIZE 1024
/* error - wrapper for perror */ 
void error(char *msg) 
{
    perror(msg);
    exit(0); 
}

int main(int argc, char *argv[]) 
{ 
    int sockfd, portno, n; 
    socklen_t serverlen;
    struct sockaddr_in serveraddr; 
    struct hostent *server;
    char *hostname; 
    char buf[BUFSIZE];
    /* check command line arguments */ 

    if (argc != 3) 
    {
        fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
        exit(0); 
    }

    hostname = argv[1]; 
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 

    if (sockfd < 0)
        error("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */ 
    server = gethostbyname(argv[1]);

    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0); 
    }

    /* build the server's Internet address */ 
    memset(&serveraddr,0, sizeof(serveraddr)); 
    serveraddr.sin_family = AF_INET; 
    bcopy((char *)server->h_addr,

    (char *)&serveraddr.sin_addr.s_addr, server->h_length); 
    serveraddr.sin_port = htons(portno);

    do
    {
        /* get a message from the user */ 
        memset(buf, 0, BUFSIZE); 

        printf("\nPlease enter a binary number or type 'q' to cancel the connection: "); 
        fgets(buf, BUFSIZE, stdin);
        if(*buf == 'q')
        {
            printf("\nClinet connection cancelled...");
            break;
        }
        else
        {
            /* send the message to the server */
            serverlen = sizeof(serveraddr);
            n = sendto(sockfd, buf, BUFSIZE, 0,(struct sockaddr *) &serveraddr, serverlen); 
            if (n < 0)
                error("ERROR in sendto");

            char decstr[5];
            n =recvfrom(sockfd, decstr, 5, 0,(struct sockaddr *) &serveraddr, &serverlen); 
            if (n < 0)
                error("ERROR in recvfrom");
                
            printf("\nDecimal conversion of the number from server: %s\n", decstr); 
        }
    }while(1);

    close (sockfd);
    return 0;
}