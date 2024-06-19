#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>

struct persona{
    char name[50];
    char cognome[50];
    int eta;
};

int main(int argc, char **argv){

    int sockfd;
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    struct persona p;

    if(argc < 2){
        printf("Errore. Devi inserire il numero di porta\n");
        return -1;
    }

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0){
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sockfd, (struct sockaddr *) &local_addr, len) < 0){
        printf("Errore nell'apertura di bind()\n Utilizza un altro valore\n");
        return -1;
    }

    for(;;){
        recvfrom(sockfd, &p, sizeof(p)+1, 0, (struct sockaddr *) &remote_addr, &len);
        printf("IP = %s Port = %d Nome %s, Cognome %s, eta %d\n", inet_ntoa(remote_addr.sin_addr),
            ntohs(remote_addr.sin_port), p.name, p.cognome, p.eta);
        
    }

    close(sockfd);
    return 0;
}