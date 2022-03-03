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

#include "client.h"
#include "data_structs.c"

#define PORT 5000
#define IP "127.0.0.1"
#define FILE_SIZE 1024
#define MAX_CLIENTS 10
#define MAX_FILES 5

int cli_sd = -1;
int files[MAX_FILES];

/*
Need method for socket connection
 */

bool connected(const char *ip, uint16_t port) {
  cli_sd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in client;

  client.sin_family = AF_INET;
  client.sin_port = htons(PORT);

  if (inet_aton(IP, &client.sin_addr) == 0) {
    return false;
  } else if (cli_sd == -1) {
    return false;
  } else if (connect(cli_sd, (const struct sockaddr *) &client, sizeof(client)) == -1) {
    return false;
  } else {
    return true;
  }
}

/*
Need method for socket disconnection
 */

void disconnected(void) {
  close(cli_sd);
  cli_sd = -1;
}

/*
Need method for chunk sending
 */

/*
Need method for chunk receiving
 */
