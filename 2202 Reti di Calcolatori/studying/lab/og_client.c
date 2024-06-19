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
    struct sockaddr_in dest_addr;
    struct persona p;

    if(argc < 3){
        printf("Devi Inserire IP e porta del server\n");
        return -1;
    }

    //Dichiariamo il tipo socket
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){ // if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        printf("Errore nell'apertura di socket!");
        return -1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(dest_addr.sin_addr));
    dest_addr.sin_port = htons(atoi(argv[2]));

    printf("Inserisci il nome di una persona\n");
    scanf("%s", p.name);
    printf("Inserisci il cognome di una persona\n");
    scanf("%s", p.cognome);
    printf("Inserisci l'eta' di una persona\n");
    scanf("%s", &p.eta);

    sendto(sockfd, &p, sizeof(p)+1, 0, (struct sockaddr *)&dest_addr,
                                                    sizeof(dest_addr));

    

    close(sockfd);


    return 0;
}