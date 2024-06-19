typedef struct s_client {
  struct sockaddr_in addr;
  int lives;
  char nome[50];
} client;
