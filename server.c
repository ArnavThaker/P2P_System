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

/*

 */
bool connected(const char* ip, uint16_t port) {
  
}


void disconnected (void) {
  close(serv_sd);
  serv_sd = -1;
}
