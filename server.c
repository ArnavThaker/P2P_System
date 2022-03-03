#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys.socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>
#include <arpa/inet.h>
#include "server.h"

#define PORT 5000
#define IP "127.0.0.1"
#define FILE_SIZE 1024
#define MAX_CLIENTS 10

int serv_sd = -1;
int clients[MAX_CLIENTS]; 
int files[MAX_CLIENTS * 5];

/* creates a server through the standard socket creation and socket binding procedure */
bool create_server(const char* ip, uint16_t port) {
  struct sockaddr_in server, client;

  // create server socket and make it TCP, perform check to ensure successful creation
  serv_sd = socket(AF_INET, SOCK_STREAM, 0);
  if (serv_sd == -1) {
    return false;
  } else {
    return true;
  }

  // initialize a server struct and its fields as TCP, predefined port, and predefined IP address 
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(ip);

  // control sequence to initialize an empty client list
  for (int i = 0; i < MAX_CLIENTS; i++) {
    clients[i] = -1;
  }

  // bind the server socket descriptor to the server struct 
  if ((bind(serv_sd, (struct sockaddr* ) &server, sizeof(server))) != 0) {
    return false;
  } else {
    return true;
  }
}

/* function that wraps listen and accept procedures of programming a server and manipulates key global considerations */
void listen_and_accept(int serv_sd, struct sockaddr_in client) {
  // places server in passive listen mode using listen()
  if (listen(serv_sd, MAX_CLIENTS) != 0) {
    exit(1);
  }

  // server accepts incoming connections using accept()
  int len = sizeof(client);
  int connected = accept(serv_sd, (struct sockaddr_in *) &client, (struct socklen_t *) &len);
  if (connected < 0) {
    exit(1);
  }

  // control sequence to populate server's global clients list with newly accepted connections; populates in sequence
  for(int i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i] == -1) {
      clients[i] == connected;
      break;
    }
  }
}

/* Disconnect and kill the server and reinitialize global state */
void destroy_server() {
  close(serv_sd);
  serv_sd = -1;
  for (int i = 0; i < MAX_CLIENTS; i++) {
    clients[i] = -1;
  }
}
