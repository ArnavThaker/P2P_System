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


int serv_sd = -1;

/*

 */
bool connected(const char* ip, uint16_t port) {
  
}


void disconnected (void) {
  close(serv_sd);
  serv_sd = -1;
}
